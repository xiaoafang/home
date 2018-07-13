#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
if(	(mkfifo("mypipe",0644)<0))
{
		  perror("nihao");
		  exit(EXIT_FAILURE);
}
	int rfd=open("mypipe",O_RDONLY);
	char buf[1024];
	while(1)
	{
		buf[0]=0;
		printf("please wait ...\n");
		ssize_t s = read(rfd,buf,sizeof(buf)-1);
		if(s>0)
		{
			buf[s-1]=0;
			printf("client ast:%s \n",buf);
		}else
			printf("client quit,exit now!\n");
	}
	close(rfd);
	return 0;
}
