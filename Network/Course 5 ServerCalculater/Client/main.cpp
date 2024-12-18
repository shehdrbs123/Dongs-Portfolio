#include <winsock2.h>
#include <string>
#include <iostream>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 10000

void error(const std::string& message)
{
    std::cout << message << '\n';
    exit(1);
}

void error_without_exit(const std::string& message)
{
    std::cout << message << '\n';
}

bool InputNumber(SOCKET socket, int& outInt)
{
    try
    {
        std::cin >> outInt;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    if(outInt >= 1000000000)
        return false;

    std::string networkStr(std::to_string(outInt));
    char buffer[1024];
    send(socket,networkStr.c_str(),networkStr.length(),0);
    recv(socket,buffer,sizeof(buffer),0);
    if(buffer[0] == '1')
        return true;
    else
        return false;
}

int main()
{
    WSADATA wasData{};
    WSAStartup(MAKEWORD(2,2),&wasData);

    SOCKET sock=socket(PF_INET,SOCK_STREAM,0);
    if(sock == INVALID_SOCKET)
        error("socket() error");

    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddr.sin_port = htons(SERVER_PORT);

    if(connect(sock,(sockaddr*)&serverAddr,sizeof(serverAddr)) == SOCKET_ERROR)
        error("socket() error");


    std::cout << "Operand Count : ";
    int count = 0;
    char buffer[1024];
    if(InputNumber(sock,count))
    {
        std::cout << count <<'\n';
        for(int i=0;i<count;++i)
        {
            std::cout << "Operand " << i+1 << " : ";
            int dump=0;
            if(!InputNumber(sock,dump))
                break;
        }

        std::cout << "Operator : ";
        std::cin >> buffer;

        send(sock,buffer,1,0);

        int str_len = recv(sock,buffer,sizeof(buffer),0);
        buffer[str_len] = 0;

        std::cout << "Operation Result : " << buffer << '\n';
    }else{
        std::cout << "InputNumber error()" << '\n';
    }

    closesocket(sock);

    WSACleanup();
}