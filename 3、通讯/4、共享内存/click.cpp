#include "commen.hpp"

int main()
{
    // 创建共享内存，方式是连接端，大小默认1024
    shared_memory sh(shared_memory::click);

    // 获取到共享内存的地址
    char *const sh_buffer = (char *)sh.getMemory();

    // 通讯
    char buffer[1024];
    while (true)
    {
        fgets(buffer, sizeof(buffer) - 1, stdin);
        buffer[strlen(buffer) - 1] = 0;
        if (strcmp(buffer, "break") == 0)
            break;
        else
            strcpy(sh_buffer, buffer);
    }

    // 销毁
    // 由于这是一个局部的变量，出了作用域以后会自动调用销毁函数

    return 0;
}