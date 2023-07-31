#include "udp_server.hpp"
#include <memory>

using namespace udp_server;
using namespace std;

int main()
{
    unique_ptr<UdpServer> us(new UdpServer(8081));
    us->InitServer();
    us->Start();

    return 0;
}