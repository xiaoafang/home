#include <stdio.h>
#include<iostream>
using namespace std;
void del(char *src,const char *sub)
{
    
    if(src==NULL)
        return ;
    if(sub==NULL)
        return ;
    while(src)
    {
        char *tmp=src;
        if(src==sub)
        {
            while(sub)
            {
                if(src==sub)
                {
                    src++;   
                    sub++;
                }  
            }
        }
        if(sub==NULL)
            tmp='\0';
        src++;
    }
}
int main()
{
    int i;
    char *b;
    char a[]="asdasaqwee";
    char c[]="wee";
    del(a,c);
   for(i=0;i<10;i++)
        cout<<a[i]<<" ";
    //int n,k;
    //scanf("%d,%d",&n,&k);
    //int i,a[100];
    //for(i=0;i<n;i++)
    //{
    //    a[i]=1;
    //}
    //int j,q=0;
    //for(i=2;i<n;i++)
    //{
    //    for(j=2;j<n;j++)
    //    {
    //        if((i%j)==0&&q==0)
    //        {
    //            a[i]=0;
    //            q=1;
    //        }
    //        if(i%j==0&&q==1)
    //        {
    //            a[i]=1;
    //            q=0;
    //        }
    //    }
    //}
    //for(i=0;i<n;i++)
    //{
    //    printf("%d",a[i]);

    //}
    return 0;
}
