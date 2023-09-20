#include <iostream>
#include <cassert>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
    管道的本质是一个内存文件
    通过pipe函数打开这个特殊的文件
    子进程通过父进程继承下来的，关闭对应的写端和读端，即可实现双方的通信

    存在4种情况：
    已经接受完管道的内容，对方没有发  ----  等待
    管道的缓存区已被占满，对方没有读  ----  停止发送，以免覆盖原有数据
    读取方关闭了管道  ---- 系统不允许资源的浪费，会直接发信号，终止掉写进程
    写入方关闭了管道  ---- 可以继续读，读完以后，再次读取的时候，read会返回0
*/

int main()
{
    int pipefd[2] = {0};
    // agrs：输出型参数，打开一个文件，方式：0下表是读，1下标是写
    // ret： 成功返回0，否则返回-1
    int ret = pipe(pipefd);
    assert(ret != -1); // 打开失败就断言掉

    pid_t id = fork();
    assert(id != -1); // 失败直接断言
    if (id == 0)
    {
        // child
        close(pipefd[0]); // 关闭读，那么就只保留了写功能

        for (int i = 0;; i++)
        {
            char buffer[128];
            snprintf(buffer, 128, "我是子进程，这是第%d次写入，pid为%d", i, getpid());
            write(pipefd[1], buffer, 128);
            sleep(1);
        }

        close(pipefd[1]);
        exit(0);
    }

    // father
    close(pipefd[1]); // 关闭写端，便可以读取管道的内容
    for (int i = 0;; i++)
    {
        char buffer[128];
        read(pipefd[0], buffer, 128);
        std::cout << "这是第" << i << "次读，内容为：" << buffer << std::endl;
    }

    close(pipefd[0]);
    return 0;
}