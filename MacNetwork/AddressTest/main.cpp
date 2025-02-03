#include <arpa/inet.h>
#include <string.h>

int main()
{
    struct sockaddr_in sockaddr{};

    memset(&sockaddr,0,sizeof(sockaddr));

    unsigned long conv_addr;

    inet_pton(AF_INET,);
    inet_addr(INADDR_ANY);
}