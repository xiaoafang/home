
#include<stdio.h>

int binary_search(int *a,int len,int value)
{
	int low,high,mid;
	low=0;
	high=len-1;
	while(low<=high)
	{
			mid=(low+high)/2;
		if(value<a[mid])
		{
			high=mid-1;
		}
		else if(value >a[mid])
		{
			low =mid+1;
		}
		else
			return mid;
	}
}
int main()
{
		  int b;
	int a[10]={1,2,5,7,9,13,16,18,23,34};
	b=binary_search(a,10,1);
	printf("%d ",b);
	return 0;
}
