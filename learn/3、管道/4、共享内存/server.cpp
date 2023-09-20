#include "commen.hpp"

int main()
{
    // 创建共享内存，方式是连接端，大小默认1024
    shared_memory sh(shared_memory::server);

    // 获取到共享内存的地址
    char *sh_buffer = (char *)sh.getMemory();

    // 通讯---获取内容
    for (int i = 0; i < 20; i++)
    {
        std::cout << sh_buffer << std::endl;
        sleep(1);
    }

    // 销毁
    // 由于这是一个局部的变量，出了作用域以后会自动调用销毁函数

    return 0;
}