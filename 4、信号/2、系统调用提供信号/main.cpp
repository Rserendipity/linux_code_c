#include <iostream>
#include <unistd.h>
#include <signal.h>

typedef void (*hander)(int); // 回调函数

int main(int argc, char const *argv[])
{

    return 0;
}

// long long g_val;
// void myalarm(int signal)
// {
//     std::cout << g_val << std::endl;
//     exit(0);
// }

// int main()
// {
//     // 启动定时，进程会收到14号信号
//     // 这个闹钟是一次性的
//     alarm(1);
//     signal(14, myalarm);

//     // 可以测试一秒钟内，执行多少次，用来测试 CPU 性能
//     while (true)
//         ++g_val;

//     return 0;
// }

// void print(int signal)
// {
//     // 参数：接收到的信号值
//     std::cout << "收到" << signal << "信号" << std::endl;
// }

// int main()
// {
//     /**
//      * 事先约定，把2号信号重新约定成我们自己的动作 --> 由回调函数完成
//      * SIGINT  ->  signal interrupt 中断前台进程，对后台进程无效
//      */
//     signal(SIGINT, print);

//     // 无效，9号命令无法被修改，9号命令是系统杀死进程最后的手段
//     signal(SIGKILL, print);

//     while (true)
//     {
//         std::cout << "正在运行....  pid：" << getpid() << std::endl;
//         sleep(1);
//     }

//     return 0;
// }