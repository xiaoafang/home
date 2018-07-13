#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define SERVER_PORT 9999
#define SERVER_IP "192.168.46.68"

int main(int argc,char *argv[])
{
    char *str=a[1];
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
    {
        perror("socket\n");
        return 2;
    }
    
    struct sockaddr_in server_socket;
    server_socket.sin_family=AF_INET;
    server_socket.sin_addr.s_addr=htonl(INADDR_ANY);
    server_socket.sin_port=htons(_PORT_);

