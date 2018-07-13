#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mysql.h>
void insert_data()
{
    MYSQL *mysql_fd=mysql_init(NULL);
    if(mysql_real_connect(mysql_fd,"127.0.0.1","root","","shujikuming",3306,NULL,0)==NULL)
    {
        printf("connect failed!\n"); 
        return ;                  
    }  
       printf("connect mysql success!\n");

       const char *sql="INSERT INTO student_info (name,sex,phone) VALUES 
           (\"zhagnkk\".\"man\",\"1231231123\")";
       mysql_query(mysql_fd,sql);
       mysql_close(mysql_fd);
}
int main()
{
    char data[1024];
    if(getenv(("METMOD"))
    {
        if(strcasecmp("GET",getenv("METHOD"))==0)
        {
            strcpy(data,getenv("QUERY_STRING"));
    }
        else
        {
             int content_len =atoi(getenv("CONTRNT_LEN"));
             int i=0;
             for(i;i<content_len;i++)
             {
                read(0,data+i,1);
             }
             data[i]=0;
         }
    }
    printf("arg:%s\n",data);
    //printf("client version:%s\n",mysql_get_client_info());
    insert_data(name,sex,phone);
    return 0;
}
