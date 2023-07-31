#pragma once

#include <iostream>
#include <string>

#include <cstring>
#include <cstdlib>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "myerr.hpp"

namespace udp_server
{

    const static uint16_t DEFALUT_PORT = 8081;

    class UdpServer
    {
    public:
        // UdpServer(std::string ip, uint16_t port = DEFALUT_PORT) : _ip(ip), _port(port) {}
        UdpServer(uint16_t port = DEFALUT_PORT) : _port(port) {}
        void InitServer()
        {
            // 1. 创建socket描述符fd
            _sock = socket(AF_INET, SOCK_DGRAM, 0);

            //   socket创建失败
            if (_sock < 0)
            {
                std::cerr << "Socket error:" << strerror(errno) << std::endl;
                exit(myerr::SOCKET_ERR);
            }

            //   socket创建成功
            std::cout << "create socket fd success：" << _sock << std::endl;

            // 2. 绑定端口号
            struct sockaddr_in local;
            memset(&local, 0, sizeof(local));
            local.sin_family = AF_INET;
            local.sin_port = htons(_port);
            // local.sin_addr.s_addr = inet_addr(_ip.c_str()); // 绑定特定ip
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
            
        }

    private:
        int _sock;
        uint16_t _port;
        // std::string _ip;
    };
}