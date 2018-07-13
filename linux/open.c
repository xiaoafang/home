#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd = open("myfile",O_RDONLY,644);
	if(fd<0)
		return 1;
	const char*msg = "ealo\n";
	char buf[1024];
///	printf("%d ",strlen(msg));
	while(1)
	{
			  ssize_t s=read(fd,buf,strlen(msg));
			  if(s>0)
						 printf("%s",buf);
			  else
						 break;
	}
	close(fd);
	return 0;
}

