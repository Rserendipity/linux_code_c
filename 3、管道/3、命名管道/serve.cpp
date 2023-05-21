#include "commen.hpp"
#include <cassert>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * 由服务端提供管道
 * 然后服务端接收消息并回显
 *
 */
int main()
{
    // 创建管道
    int ret = mkfifo(path.c_str(), mode);
    assert(ret != -1);
    std::cout << "管道创建成功，等待建立连接....." << std::endl;

    // 打开管道，对方没有write的时候，这里会阻塞
    int fd = open(path.c_str(), O_RDONLY);
    std::cout << "连接成功....." << std::endl;

    assert(fd != -1);

    // 进行通讯
    char buffer[NUM] = {0};
    while (true)
    {
        std::cout << "收到的信息是：";
        std::cout.flush();
        ssize_t n = read(fd, buffer, sizeof(buffer));
        if (n > 0)
        {
            std::cout << buffer << std::endl;
        }
        else if (n == 0)
        {
            std::cout << "关闭连接" << std::endl;

            // 关闭聊天以后，清楚管道文件
            unlink(path.c_str());
            break;
        }
        else
        {
            // error
            break;
        }
    }
    close(fd);

    return 0;
}