#include <iostream>
#include <string>
#include <winsock2.h>
#include <ctime>

void error_handing(std::string message)
{
    std::cout << message << std::endl;
    exit(1);
}
int main(const int argc, const char* argv[])
{
    WSADATA wsa{};

    SOCKET serv_sock;
    SOCKET clnt_sock;

    SOCKADDR_IN serv_addr;
    SOCKADDR_IN clnt_addr;
    if(argc != 2)
    {
        printf("Usage : %s <PORT> \n",argv[0]);
        exit(1);
    }
    int clnt_addr_size = sizeof(clnt_addr);
    char buffer[1024];

    WORD sockVersion = MAKEWORD(2,2);
    if(WSAStartup(sockVersion,&wsa) != 0)
    {   
        error_handing("WSAStartup() error!");
    }
    serv_sock = socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock == SOCKET_ERROR)
        error_handing("socket() error");
    
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr =  htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock,(sockaddr*)&serv_addr,sizeof(serv_addr)) == -1)
        error_handing("bind() error");

    if(listen(serv_sock,5) == -1)
        error_handing("listen() error");


    while(true)
    {
        clnt_sock = accept(serv_sock,(sockaddr*)&clnt_addr,&clnt_addr_size);
        if(clnt_sock == INVALID_SOCKET)
            error_handing("accept() error");

        int cur_len = 0;
        int str_len = 0;
        while(cur_len = recv(clnt_sock,buffer,sizeof(buffer)-1,0))
        {
            if(cur_len == -1)
                error_handing("recv() error");
            
            std::cout << "length : " << cur_len << '\n';
            send(clnt_sock,buffer,cur_len,0);
        }

        
        std::cout << buffer << std::endl;

        closesocket(clnt_sock);
        

        if(strncmp("Q",buffer,2) == 0)
            break;
    }
    
    closesocket(serv_sock);
    WSACleanup();    
}
