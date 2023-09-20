#include "udp_server.hpp"
#include "myerr.hpp"
#include <iostream>
#include <memory>

using namespace udp_server;
using namespace std;

void usage(const char *name)
{
    cout << "Usage:\n\t" << name << " [port]" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        usage(argv[0]);
        return myerr::USE_ERR;
    }
    int port = atoi(argv[1]);

    unique_ptr<UdpServer> us(new UdpServer(port));
    us->InitServer();
    us->Start();

    return 0;
}