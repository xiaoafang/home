#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int outfd;
	outfd = open("myfile.bak",O_WRONLY|O_CREAT|O_TRUNC,0644);
	int infd;
	infd = open("tp",O_RDONLY);
	char buf[1024];
	int n;
	while((n=read(infd,buf,1024))>0)
			  write(outfd,buf,n);
	close(infd);
	close(outfd);
	unlink("tp");
	return 0;
}
