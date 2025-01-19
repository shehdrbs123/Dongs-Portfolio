#include <winsock2.h>
#include <string>
#include <iostream>
#include <locale>
#include <codecvt>
#include "errorHandling.h"

int main()
{
    WSAData wsaData;

    SetConsoleOutputCP(CP_UTF8);
    WSAStartup(MAKEWORD(2,2),&wsaData);

    SOCKET serv_sock = socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock == INVALID_SOCKET)
        error_handling("socket() error");

    
    SOCKADDR_IN serv_addr;
    memset(&serv_addr,0,sizeof(SOCKADDR_IN));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(9000);

    if(bind(serv_sock,(const sockaddr*)&serv_addr,sizeof(SOCKADDR)) == SOCKET_ERROR)
        error_handling("bind() error");

    if(listen(serv_sock,5) == SOCKET_ERROR)
        error_handling("listen() error");

    SOCKET clnt_sock;
    SOCKADDR_IN clnt_addr;
    int clnt_addr_size=sizeof(SOCKADDR_IN);
    
    char buffer[1024];
    while(true)
    {
        printf("대기중....\n");
        clnt_sock = accept(serv_sock,(sockaddr*)&clnt_addr,&clnt_addr_size);
        if(clnt_sock != INVALID_SOCKET)
        {
            int str_len = recv(clnt_sock,buffer,sizeof(buffer),0);
            buffer[str_len] = '\0';
            printf(L"%s : %s\n",inet_ntoa(clnt_addr.sin_addr),buffer);

            send(clnt_sock,buffer,str_len,0);
            closesocket(clnt_sock);
        }
    }
    closesocket(clnt_sock);
    closesocket(serv_sock);

    WSACleanup();
}
