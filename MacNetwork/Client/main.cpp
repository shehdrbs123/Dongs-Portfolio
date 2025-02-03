#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void error_handling(const char * message)
{
    printf("%s",message);
    exit(1);
}

int main(int argc, char* argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[] = "hello world\n";
    char buffer[100];
    int str_len;

    if(argc != 3)
    {
        printf("Usage : %s <IP> <PORT>\n",argv[0]);
        exit(1);
    }
    
    sock = socket(PF_INET,SOCK_STREAM,0);
    if(sock == -1)
        error_handling("socket() error");

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))== -1)
        error_handling("connect() error");
    
    str_len = read(sock,buffer,sizeof(buffer)-1);
    if(str_len == -1)
        error_handling("read() error");
    printf("Server Message : %s",buffer);
    write(sock,message,sizeof(message));

    close(sock);
    return 0;
    
}