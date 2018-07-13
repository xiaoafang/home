#include <stdio.h>
#include<stdint.h>
#include<algorithm>
#include <cstring>
#include<iostream>
using namespace std;
int main()
{
    int i;
    //char a[]="qwert";
    int a[5]={5,42,67,89,9};
    sort(a,a+5);
    for(i=0;i<5;i++)
    {

    cout<<a[i]<<" ";
    }
  //  uint64_t a=9;
    //printf("%d",a&(0x1ul<<3));
    //n=n>>1;
   // printf("%d,%d",1&n,n);
    return 0;
}
