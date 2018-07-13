#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<pthread.h>
#include<string.h>
#include<sys/stat.h>

#define HOME_PAGE "index.html"
#define SIZE 1024
//#define Debug 
//从套接字文件中，读取一行，并存入line数组，size为数组大小
static int get_line(int sock,char line[],int size)
{
    int c = 'q';
    int i = 0;
    ssize_t s=0;
    //一行不能超过数组大小并且/n结尾表示一行读取结束
    while(i < size-1 && c != '\n')
    {
       s = recv(sock,&c,1,0);
       if(s > 0)
       {
           if(c == '\r')
           {
                recv(sock,&c,1,MSG_PEEK);
                if(c != '\n')
                    c = '\n';
                else
                {
                    recv(sock,&c,1,0);
                }
           }
           line[i++] = c;
       }
       else
       {
           break;
       }
    }
    line[i] = '\0';
    return i;
}

void clear_header(int sock)
{
    char line[1024];
    do
    {
        get_line(sock,line,sizeof(line));
    }while((strcmp(line,"\n")!=0));
}

int excu_cgi(int sock,char *method,char *path,char *query_string)
{
    char line[1024];
    int content_len=-1;
    if(strcasecmp(method,"GET")==0)
    {
        clear_header(sock);
    }
    else
    {
        do
        {
            get_line(sock,line,sizeof(line));
            if(strncmp(line,"Content-Length: ",16)==0)
            {
                content_len=atoi(line+16);
            }
        }while(strcmp(line,"\n")!=0);
        if(content_len==-1)
            return 404;
    }

    char method_env[SIZE/8];
    char query_string_env[SIZE/8];
    char content_len_env[SIZE/8];

    sprintf(method_env,"METHOD=%s",method);
    putenv(method_env);
            printf("method:%s,path:%s\n",method,path);
    if(strcasecmp(method,"GET")==0)
    {
        sprintf(query_string_env,"QUERY_STRING=%s",query_string);
        putenv(query_string_env);
    }
    else
    {
        sprintf(content_len_env,"CONTENT_LEN=%d",content_len);//!
        putenv(content_len_env);
    }
    int input[2];
    int output[2];
    pipe(input);
    pipe(output);

    pid_t id=fork();

    if(id<0)
    {
        return 404;

    }
    else if(id==0)     //子进程
    {
        close(input[1]);    //关闭input的写端      
        close(output[0]);  //关闭output的读端

        //将文件描述符重定向到标准输入标准输出
        dup2(input[0],0);
        dup2(output[1],1);

        execl(path,path,NULL);         //替换CGI程序
        exit(1);

    }
    else         //father
    {
        close(input[0]);      //关闭input的读端
        close(output[1]);     //关闭output的写端

        char ch;
        if(strcasecmp(method,"POST")==0) //如果是post方法，则父进程需要给子进程发送参数
        {
            int i=0;
            for( i=0;i<content_len;i++ )
            {
                recv(sock,&ch,1,0);        //从sock里面一次读一个字符，总共读conten_len个字符
                write(input[1],&ch,1);
            }
        }

        sprintf(line,"HTTP/1.0 200 OK\r\n");
        send(sock,line,strlen(line),0);

        sprintf(line, "Content-Type: text/html\r\n");
        send(sock,line,strlen(line),0);

        sprintf(line,"\r\n");
        send(sock,line,strlen(line),0);

        //接收子进程的返回结果
        while(read(output[0],&ch,1)>0)      //如果CGI程序结束，写端关闭，则读端返回0
        {
            send(sock,&ch,1,0);
        }
        waitpid(id,NULL,0);              //回收子进程
        close(input[1]);
        close(input[0]);
    }
    return 200;
}


void echo_www(int sock,char *path,int size,int *err)
{
    clear_header(sock);
    int fd = open(path,O_RDONLY);
    if(fd < 0)
    {
        *err = 404;
        return ;
    }
    char line[1024];
    sprintf(line,"HTTP/1.0 200 OK\r\n");
    send(sock,line,strlen(line),0);
 
//    sprintf(line, "Content-Type: text/html\r\n");
//    send(sock,line,strlen(line),0);

    sprintf(line,"\r\n");
    send(sock,line,strlen(line),0);

    sendfile(sock,fd,NULL,size); //?
    close(fd);
}

void echo_error(int code)
{
    switch(code)
    {
        case 404:
            break;
        case 505:
            break;
        default:
            break;
    }
}
static void *hander_request(void *arg)
{
    //传入链接套接字
    int sock = (int)arg;
    char line[1024];
    char method[1024/32]; //?
    char url[1024];
    int errcode = 200;
    int cgi = 0;
    char *query_string=NULL;
    char path[1024];
    int ret;

#ifdef Debug
    do{
        get_line(sock,line,sizeof(line));
        printf("%s",line);
    }while(strcmp(line,"\n") != 0);
#else
    //如果读取行失败，则返回错误码
    if(get_line(sock,line,sizeof(line)) < 0)
    {
        errcode = 404;
        goto end;
    }
    //get method
    int i = 0;
    int j = 0;
    while(i < sizeof(method)-1 && j < sizeof(line) && !isspace(line[j]))
    {
        method[i] = line[j];
        i++,j++;
    }
    method[i]='\0';
    //method中我们只处理get和post方法
    if(strcasecmp(method,"GET")==0)
    {

       }
       else if(strcasecmp(method,"POST")==0) 
       {
            cgi=1;
       }
       else{
          errcode = 404; 
           goto end;      
       } 
      

    //过滤空格
    while(j < sizeof(line) && isspace(line[j]))
    {
        j++;
    }
    //获取url
    i=0;
    while(i < sizeof(url)-1 && j < sizeof(line) && !isspace(line[j]))
    {
        url[i] = line[j];
        i++,j++;
    }
    url[i] = '\0';
    
    //如果为get方法，把URL中的参数提取出来
    if(strcasecmp(method,"GET") == 0)
    {
        query_string = url;
        while(*query_string)
        {
            if(*query_string == '?')
            {
                *query_string = '\0';
                query_string++;
                cgi = 1;
                break;
            }
            query_string++;
        }
    }
    //按格式www+url输出到path中,url中为网页所在的目录
    sprintf(path,"www%s",url);
    //把目录拼接到path之后
    if(path[strlen(path)-1] == '/')
    {
        strcat(path,HOME_PAGE);
    }
    struct stat st;
    //判断主页存不存在，不存在出错返回
    if(stat(path,&st) < 0)
    {
        errcode = 404;
        goto end;
    }
    else
    {
        if(S_ISDIR(st.st_mode))
        {
           strcat(path,HOME_PAGE);                       
        }
        else
        {
            //如果存在判断文件是不是可执行文件，如果是按cgi方式处理
            if((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) || (st.st_mode & S_IXOTH))
            {
                cgi = 1;
            }
        }
        if(cgi)
        {
            
            errcode=excu_cgi(sock,method,path,query_string);
        }
        else//get方法，没有参数，
        {
            echo_www(sock,path,st.st_size,&errcode);
        }
    }
#endif
end:    
    if(errcode !=200)
    {
        echo_error(errcode);
    }
    close(sock);
}

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("usage:%s port\n",argv[0]);
        return 1;
    }

    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        perror("socket\n");
        return 2;
    }

    int opt=1;
    setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = htonl(INADDR_ANY);
    local.sin_port = htons(atoi(argv[1]));

    if(bind(sock,(struct sockaddr*)&local,sizeof(local)) < 0)
    {
        perror("bind\n");
        return 3;
    }
    if(listen(sock,5))
    {
        perror("listen\n");
        return 4;
    }
    for(;;)
    {
        struct sockaddr_in client;
        socklen_t len  = sizeof(client);
        int new_sock = accept(sock,(struct sockaddr*)&client,&len);
        if(new_sock < 0)
        {
            perror("accept\n");
            continue;
        }
        pthread_t id;
        //创建一个多线程，new_sock作为hander函数的参数
        pthread_create(&id,NULL,hander_request,(void*)new_sock);
        pthread_detach(id);
    }
    return 0;
}
