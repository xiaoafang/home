#include<stdio.h>

int main()
{
	int a=1;
	int i;
	int b=1;
	for(i=0;i<5;i++)
	{
		int c=a+b;
 	   a=b;
		b=c;
	}
	printf("%d ",b);
	return 0;
}
