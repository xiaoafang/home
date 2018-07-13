#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	mkfifo("tp",0664);
	int infd;
	infd = open("myfile",O_RDONLY);
	if(infd==-1)
		  exit(1);	  
	int outfd;
	outfd = open("tp",O_WRONLY);
	if(outfd==-1)
			  exit(1);
	char buf[1024];
	int n;
	while((n=read(infd,buf,1024))>0)
			  write(outfd,buf,n);
	close(infd);
	close(outfd);
	return 0;
}
