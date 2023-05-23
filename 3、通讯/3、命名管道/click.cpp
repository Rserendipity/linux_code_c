#include "commen.hpp"
#include <cassert>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    // 写的方式打开文件描述符
    int fd = open(path.c_str(), O_WRONLY);
    assert(fd != -1);

    // 进行通讯
    char buffer[NUM] = {0};

    while (true)
    {
        std::cout << "发送信息段# ";
        fgets(buffer, sizeof(buffer), stdin);
        // 去除末尾的\n
        buffer[strlen(buffer) - 1] = 0;

        ssize_t n = write(fd, buffer, sizeof(buffer));
    }

    close(fd);

    return 0;
}