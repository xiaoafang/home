#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
void mo(int *a,int size,int &output1,int &output2)
{
    sort(a,a+size);
    if(a==NULL)
        return;
    int i;
    int count=0;
    for(i=0;i<size;i++)
    {
        if(a[i]==a[i+1])
            count++;
        if(count==size/4)
            output2=a[i];
        if(count==size/2)
            output1=a[i];
    }
}
int main()
{
    int i,j;
    int a[10]={3,3,3,4,4,4,3,3,3,6};
    mo(a,10,i,j);
    printf("%d %d",i,j);
  //  int i,j,k;
  //  scanf("%d%d%d",&i,&j,&k);
  //  int a,b,c;
  //  for(a=5;a<10;a++)
  //  {
  //      for(b=7;b<10;b++)
  //      {
  //          for(c=6;c<10;c++)
  //          {
  //              if((8*a+6*b+6*c)==j && (a+b+c)==i && (2*a+b)==k)
  //              {
  //                  printf("%d %d %d\n",a,b,c);
  //              }    
  //          }
  //      }
  //  }
    return 0;
}

