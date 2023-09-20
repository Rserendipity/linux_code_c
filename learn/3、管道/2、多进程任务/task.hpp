#include <iostream>
#include <vector>
#include <unistd.h>

typedef void (*func_t)();

void PrintLog()
{
    std::cout << "子进程:" << getpid() << " 正在执行PrintLog" << std::endl;
}

void SendMessage()
{
    std::cout << "子进程:" << getpid() << " 正在执行SendMessage" << std::endl;
}

void LinkMySql()
{
    std::cout << "子进程:" << getpid() << " 正在执行LinkMySql" << std::endl;
}

class Task
{
public:
    Task()
    {
        t.push_back(PrintLog);
        t.push_back(SendMessage);
        t.push_back(LinkMySql);
    }
    void Execute(int command)
    {
        // command合法，调用对应的函数
        if (command >= 0 && command < t.size())
            t[command]();
    }

private:
    std::vector<func_t> t;
};