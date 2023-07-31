#pragma once

#include <cstdint>
#include <iostream>
#include <string>

#include <cstdlib>
#include <cstring>

#include "myerr.hpp"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

namespace udp_server
{

const static uint16_t DEFAULT_PORT = 8081;

class UdpServer
{
public:
    // UdpServer(std::string ip, uint16_t port = DEFALUT_PORT) : _ip(ip),
    // _port(port) {}
    UdpServer(uint16_t port = DEFAULT_PORT)
        : _port(port)
    {
    }
    void InitServer()
    {
        // 1. 创建socket描述符fd
        _sock = socket(AF_INET, SOCK_DGRAM, 0);

        //   socket创建失败
        if (_sock < 0)
        {
            std::cerr << "Create socket fd error:" << strerror(errno) << std::endl;
            exit(myerr::SOCKET_ERR);
        }

        //   socket创建成功
        std::cout << "Create socket fd success：" << _sock << std::endl;

        // 2. 绑定端口号
        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(_port);
        // local.sin_addr.s_addr = inet_addr("1.1.1.2"); // 绑定特定ip
        local.sin_addr.s_addr = INADDR_ANY;

        int n = bind(_sock, reinterpret_cast<const sockaddr *>(&local), sizeof(local));
        if (n < 0)
        {
            std::cerr << "Bind socket error:" << strerror(errno) << std::endl;
            exit(myerr::BIND_ERR);
        }
        std::cout << "Bind socket success:" << n << std::endl;
    }
    void Start()
    {
        char buffer[2048];
        while (true)
        {
            memset(buffer, 0, sizeof(buffer));
            struct sockaddr_in socket;
            socklen_t len = sizeof(socket);
            // 接收信息
            int n = recvfrom(_sock, buffer, sizeof(buffer), 0,
                             reinterpret_cast<struct sockaddr *>(&socket), &len);
            if (n > 0)
                buffer[n] = '\0';
            else
                continue;

            std::string clientIp = inet_ntoa(socket.sin_addr);
            uint16_t clientPort = ntohs(socket.sin_port);
            printf("[%s,%d]# %s\n", clientIp.c_str(), clientPort, buffer);

            sendto(_sock, buffer, sizeof(buffer), 0,
                   reinterpret_cast<struct sockaddr *>(&socket), len);
        }
    }

private:
    int _sock;
    uint16_t _port;
    // std::string _ip;
};
} // namespace udp_server