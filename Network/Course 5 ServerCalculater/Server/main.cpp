#include <winsock2.h>
#include <string>
#include <iostream>
#include <vector>

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

bool GetNumber(const SOCKET& clientSocket, char * buffer, const int bufferSize,int& outInt)
{
    int recvLen = recv(clientSocket,buffer,sizeof(buffer),0);
    buffer[recvLen] = 0;
    std::string error1 = "4";
    std::string error2 = "2";
    std::string accept = "1";
   
    if(recvLen >= 10)
    {
        send(clientSocket,error1.c_str(),error1.length(),0);
        std::cout << "recvLen : "  << recvLen << '\n';
        return false;
    }
        
    outInt = atoi(buffer);
    if(outInt == -1)
    {   
        send(clientSocket,error2.c_str(),error2.length(),0);
        std::cout << "buffer : "  << buffer << '\n';
        return false;
    }
 
    send(clientSocket,accept.c_str(),accept.length(),0);
    //Sleep(100);
    return true;
}

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2),&wsaData);

    SOCKET serverSocket;
    serverSocket = socket(PF_INET,SOCK_STREAM,0);
    if(serverSocket == INVALID_SOCKET)
        error("socket() error");

    SOCKADDR_IN serverAddr;
    memset(&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port=htons(SERVER_PORT);

    if(bind(serverSocket,(SOCKADDR*)&serverAddr,sizeof(serverAddr)) == SOCKET_ERROR)
        error("bind() error");
    
    if(listen(serverSocket,15) == SOCKET_ERROR)
        error("listen() error");

    char buffer[1024];
    while(true)
    {
        SOCKADDR_IN clnt_addr;
        int clnt_addr_size = sizeof(clnt_addr);
        SOCKET clientSocket = accept(serverSocket,(SOCKADDR*)&clnt_addr,&clnt_addr_size);
        if(clientSocket == INVALID_SOCKET)
        {
            error_without_exit("accept() error");
            continue;
        }
        std::cout << inet_ntoa(clnt_addr.sin_addr) << " is requested Calcultate\n";

        //수 사이즈 요구
        int count;
        if(!GetNumber(clientSocket,buffer,sizeof(buffer),count))
        {
            closesocket(clientSocket);
            continue;
        }
        
        std::cout << "ready to GetNumber : " << count << '\n';
        //숫자 받기
        int maximumErrorCount = 0;
        std::vector<int> v(count);
        for(int i=0;i<count;++i)
        {
            int num;
            if(GetNumber(clientSocket,buffer,sizeof(buffer),num))
            {
                std::cout << "inputNumber : " << num <<'\n';
                v.emplace_back(num);
            }else {
                if(maximumErrorCount >= 3)
                    break;
                maximumErrorCount +=1;
                --i;
            }
        }

        // 계산 시작
        if(maximumErrorCount < 3)
        {
            recv(clientSocket,buffer,1,0);
            int base = v[0];
            switch(buffer[0])
            {
                case '*' :
                    for(int i=1;i<v.size();++i)
                    {
                        base += v[i];
                        
                    }
                    break;
                case '+' :
                    for(int i=1;i<v.size();++i)
                    {
                        base += v[i];
                    }
                    break;
                case '-' :
                    for(int i=1;i<v.size();++i)
                    {
                        base += v[i];
                    }
                    break;
                case '/' :
                    for(int i=1;i<v.size();++i)
                    {
                        if(v[i] == 0) continue;

                        base /= v[i];
                    }
                    break;  
            }
            std::string strResult = std::to_string(base);
            std::cout << "result : " << base << '\n';
            
            send(clientSocket,strResult.c_str(),strResult.length(),0);
        }

        closesocket(clientSocket);
    }
    closesocket(serverSocket);

    WSACleanup();
}