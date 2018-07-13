#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#define MAX 1024
void mycal(char *buff)
{
    int x,y;
    sscanf(buff,"data1=%d&data2=%d",&x,&y);
    printf("<html>\n");
    printf("<body>\n");
    printf("<h3>%d + %d = %d</h3>\n",x,y,x+y);
    printf("<h3>%d - %d = %d</h3>\n",x,y,x-y);
    printf("<h3>%d * %d = %d</h3>\n",x,y,x*y);
    printf("<h3>%d / %d = %d</h3>\n",x,y,x/y);
    printf("</body>\n");
    printf("</html>\n");

}
int main()
{
    char buff[MAX]={0};
    if(getenv("METHOD"))
    {
        if(strcasecmp(getenv("METHOD"),"get")==0)
        {
            strcpy(buff,getenv("QUERY_STRING"));
        }
        else
        {
            int content_len = atoi(getenv("CONTENT_LEN"));
            int i=0;
            char c;
            for(i=0;i<content_len;i++)
            {
                read(0,&c,1);
                buff[i]='\0';
            }
        }
    }
    mycal(buff);
    return 0;
}
