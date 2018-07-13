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
                                                           
//从套接字文件中，读取一行，并存入line数组，size为数组大小 
int get_line(int sock,char line[],int size)                
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

void* hander_request(void *arg)                    
 {                                                  
     //传入链接套接字                               
     int sock = (int)arg;                           
     char line[1024];                               
     char method[1024/32]; //?                      
     char url[1024];                                
     int errcode = 0;                               
     int cgi = 0;                                   
     char *query_string=NULL;                       
     char *path=NULL;                               
                                                    
     do{                                            
         get_line(sock,line,sizeof(line));          
         printf("%s",line);                         
     }while(strcmp(line,"\n") != 0);   
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
