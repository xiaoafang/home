#include <stdio.h>
#include<errno.h>
int main()
{
    int n=1;
//    FILE *fp=fopen("mfile","r");
   // while(n++)
   // {
        errno=n;
    //    perror("");
//    if(fp==NULL)
    printf("%s,%d",errno,strerror(errno));
    //    if(n==100)

      //      break;
   // }
    //int count=0;
//  //  alarm(2);
    //for(;1;count++)
    //{ 
    //    printf("%d ",count);
    //    if(count==1000)
    //        abort();
    //}
    return 0;
}
