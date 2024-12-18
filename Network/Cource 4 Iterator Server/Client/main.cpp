#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <winsock2.h>
#include <string>
#include <iostream>


void error_handling(const char* message)
{
    printf("%s\n",message);
    exit(1);
}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage : %s <IP> <PORT>",argv[0]);
        exit(1);
    }

    WSAData wsa;
    if(WSAStartup(MAKEWORD(2,2),&wsa) == -1)
        error_handling("WSAStartup() error");

    SOCKET sock;
    sock = socket(PF_INET,SOCK_STREAM,0);
    if(sock == INVALID_SOCKET)
        error_handling("socket() error");

    SOCKADDR_IN serv_sockaddr{};
    memset(&serv_sockaddr,0,sizeof(serv_sockaddr));
    serv_sockaddr.sin_family = AF_INET;
    serv_sockaddr.sin_addr.S_un.S_addr = inet_addr(argv[1]);
    serv_sockaddr.sin_port = htons(atoi(argv[2]));

    if(connect(sock,(sockaddr*)&serv_sockaddr,sizeof(serv_sockaddr)) == SOCKET_ERROR)
        error_handling("connect() error");
    
    char buffer[1024];
    std::string message;

    int read_len = 0;
    int str_len = 0;
    int idx = 0;
    // 데드락 주의
    
    std::getline(std::cin,message);
    str_len = send(sock,message.c_str(),message.length(),0);

    while(str_len > read_len)
    {
        read_len += recv(sock,buffer,sizeof(buffer),0);
        if(read_len == -1)
            error_handling("recv() error");
    }
    buffer[read_len] = 0;

    printf("%s\n",buffer);

    closesocket(sock);

    WSACleanup();
}