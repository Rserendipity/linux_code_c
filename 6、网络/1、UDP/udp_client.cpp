#include "udp_client.hpp"
#include "myerr.hpp"
#include <iostream>
#include <netinet/in.h>
#include <ostream>
#include <string>
#include <sys/socket.h>

void usage(const char *name)
{
    std::cout << "Usage:\n\t" << name << " [ip] [port]" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        usage(argv[0]);
        return myerr::USE_ERR;
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        std::cout << "Create socket fail:" << std::endl;
        return myerr::SOCKET_ERR;
    }

    while (true)
    {
        std::string message;
        std::cin >> message;
        if (message == "exit")
        {
            std::cout << "bye" << std::endl;
            return 0;
        }

        struct sockaddr_in sock;
        sock.sin_addr.s_addr = inet_addr(argv[1]);
        sock.sin_port = htons(atoi(argv[2]));
        sock.sin_family = AF_INET;

        socklen_t len = sizeof(sock);

        sendto(sockfd, message.c_str(), message.size(), 0, reinterpret_cast<struct sockaddr *>(&sock), len);

        char buffer[2048] = {0};
        recvfrom(sockfd, buffer, sizeof(buffer), 0, reinterpret_cast<struct sockaddr *>(&sock), &len);

        printf("> %s\n", buffer);
    }

    return 0;
}