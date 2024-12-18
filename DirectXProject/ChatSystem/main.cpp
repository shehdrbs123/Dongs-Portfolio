#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <string>

#pragma comment(lib, "ws2_32.lib")

#define PORT 9000
#define BUFFER_SIZE 1024
#define CLIENT_ID_SIZE 10;

std::vector<std::thread> clientThreads; // 클라이언트별 스레드 관리
std::shared_mutex clientMutex;                 // 동기화를 위한 뮤텍스
std::vector<SOCKET> clientSockets;

void BroadcastMessage(const SOCKET& sender, std::string message) {
    clientMutex.try_lock();
    for (SOCKET client : clientSockets) {
        if(sender == client) continue;
        send(client, message.c_str(), message.length(), 0);
    }
}

void HandleClient(SOCKET clientSocket) {
    char buffer[BUFFER_SIZE] = {0};
    std::string clientID = std::to_string(clientSocket);
    std::cout << "Client connected: " << clientSocket << std::endl;

    while (true) {
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        
        if (bytesReceived > 0) {
            std::string message(buffer, bytesReceived);

            std::cout << "Message from client " << clientSocket << ": " << message << std::endl;
            BroadcastMessage(clientSocket, clientID + " : " + message);

        } else if (bytesReceived == 0 || bytesReceived == SOCKET_ERROR) {
            std::cout << "Client disconnected: " << clientSocket << std::endl;
            closesocket(clientSocket);
            break;
        }
    }
}


int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr = {};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // 모든 네트워크 인터페이스에서 연결 허용
    serverAddr.sin_port = htons(PORT);

    bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, SOMAXCONN);

    std::cout << "Server started on port " << PORT << std::endl;

    while (true) {
        SOCKADDR_IN clientAddr{};
        int clientSize = sizeof(clientAddr);
        SOCKET clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientSize);
        if (clientSocket != INVALID_SOCKET) {
            std::unique_lock<std::shared_mutex> lock(clientMutex);// 동기화
            clientSockets.emplace_back(clientSocket); 
            clientThreads.emplace_back(std::thread(HandleClient, clientSocket));

            char *clientIP = inet_ntoa(clientAddr.sin_addr);
            char port[10];
            itoa(clientSocket,port,10);

            std::string newUserIn(clientIP);
            newUserIn.append(":").append(port).append(" is entered\n");
            
            BroadcastMessage(serverSocket,newUserIn);
            std::cout << newUserIn;
        }
    }

    // 모든 클라이언트 스레드 종료 대기
    for (std::thread& t : clientThreads) {
        if (t.joinable()) {
            t.join();
        }
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
