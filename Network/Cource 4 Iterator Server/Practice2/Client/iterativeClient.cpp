#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <winsock2.h>



void error_handling(const std::string& message)
{
    std::cerr << message << std::endl;
    exit(1);
}

std::string WStringToUTF8(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

std::wstring UTF8ToWString(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}

int main()
{
    WSAData wsaData;
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

    SetConsoleOutputCP(CP_UTF8); // 콘솔 출력 UTF-8 설정
    //setlocale(LC_ALL, ""); // 로케일 설정

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        error_handling("WSAStartup() error");
    }

    SOCKADDR_IN sock_addr{};
    std::string address = "127.0.0.1";
    int port = 9000;

    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = PF_INET;
    sock_addr.sin_addr.s_addr = inet_addr(address.c_str());
    sock_addr.sin_port = htons(port);

    wchar_t buffer[1024] = {0};
    while (true)
    {
        // SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

        // if (sock == INVALID_SOCKET)
        //     error_handling("socket() error");

        // if (connect(sock, (const SOCKADDR*)&sock_addr, sizeof(sock_addr)) == SOCKET_ERROR)
        //     error_handling("connect() error");

        std::wcout << "입력 : ";
        std::wstring strInput;
        std::getline(std::wcin,strInput);

        std::wcout << strInput;
        std::wstring message(buffer);
        // if (message == "Q\n" || message == "q\n") {
        //     closesocket(sock);
        //     break;
        // }

        // send(sock,message.c_str(),message.length(),0);

        // if(recv(sock,message.c_str(),message.length(),0) == SOCKET_ERROR)
        // {
        //     error_handling("recv() error");
        // }

        //수신한 데이터 출력
        

        //closesocket(sock);
    }

    WSACleanup();
    return 0;
}
