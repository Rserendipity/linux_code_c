#include <iostream>
#include <vector>
#include <cassert>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "task.hpp"

using namespace std;

Task t;

struct ChildPoress
{
    ChildPoress(int pid, int fd) : _pid(pid), _pipefd(fd) {}
    ~ChildPoress() {}

    int _pid;
    int _pipefd;
};

void WaitCommand()
{
    while (true)
    {
        // 等待任务的下发
        int command = 0;
        int ret = read(0, &command, sizeof(command));

        if (ret == sizeof(command)) // 正确的读取到了任务
        {
            t.Execute(command);
        }
        else if (ret == 0) // 写方已经关闭，子进程要终止了
        {
            break;
        }
        else // 出错
        {
            break;
        }
    }
}

void CreateProcesses(vector<ChildPoress> &vChild, int childNum)
{
    vector<int> cfds;
    for (int i = 0; i < childNum; i++)
    {
        // 创建管道
        int pipeArr[2] = {0};
        int id = pipe(pipeArr);
        assert(id != -1);

        // 创建进程
        id = fork();
        assert(id != -1);
        if (id == 0)
        {
            // child，接受指令，所以关闭写端，只读
            close(pipeArr[1]);

            // 关闭掉从父进程哪里继承过来的、其他子进程的w段
            for (auto &fd : cfds)
                close(fd);

            // 把标准输入替换成管道，以后就可以直接从标准输入读取即可
            dup2(pipeArr[0], 0);

            // 等待命令
            WaitCommand();

            close(pipeArr[0]);
            exit(0);
        }

        // father，发送指令，所以关闭读端，只写
        close(pipeArr[0]);

        // 记录父进程打开的管道，在创建更多的子进程的时候，让子进程继承下来的w段关闭掉
        cfds.push_back(pipeArr[1]);
        vChild.push_back(move(ChildPoress(id, pipeArr[1])));
    }
}

int main()
{
    const int childNum = 5;
    vector<ChildPoress> vChild;
    CreateProcesses(vChild, childNum);

    while (true)
    {
        // 选择任务
        int command = rand() % 3;

        // 选择哪一个子进程执行
        int index = rand() % vChild.size();

        // 发送消息，让对应的子进程执行
        write(vChild[index]._pipefd, &command, sizeof(command));

        sleep(1);
    }

    return 0;
}