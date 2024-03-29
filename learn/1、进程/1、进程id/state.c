#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // // 这里如果什么都没有，即为空语句的时候
    // // 可以查看到进程运行的状态是 R+ ---- 运行状态
    // // 没有 IO 占用时间，该进程可以一直处于运行队列中
    // while (1)
    // {
    // }

    // // 这里有 printf 函数
    // // 可以查看到进程运行的状态大概率是 S ---- 等待状态
    // // 需要等待屏幕/磁盘 IO 的时间
    // // CPU的速度太快，以至于执行while的时间太短，等待IO设备就绪的时间太长
    // // 等待IO设备的时候，肯定不能让这个进程继续占用CPU时间片了
    // // 因此，我们查看状态大概率是 S
    // while (1)
    // {
    //     // printf需要等待屏幕设备就绪，然后刷新到屏幕，时间太久（相较于CPU来说）
    //     printf("this is a process!\n");
    // }

    // 创建子进程，让子进程和父进程都进入死循环
    // 如果我们发出 kill -9 给子进程，那么子进程就会挂掉
    // 从而进入 D/Z ---- 死亡/僵尸状态
    // D状态持续时间太短，很难看到，重点是 Z 状态
    // 由于进程退出会产生退出码返回给父进程，所以在子进程死亡后，会进入 Z 状态
    // 不会释放子进程的 pcd，等待父进程读取后，再进行回收，在等待父进程的过程中，状态就是 Z
    pid_t ret = fork();
    if (ret == 0) // 子进程，ret为0
    {
        while (1)
        {
            printf("%d\n", getpid());
            sleep(2);
        }
    }
    else if (ret > 0) // 父进程，ret为子进程的pid
    {
        while (1)
        {
            printf("%d\n", getpid());
            sleep(2);
        }
    }

    return 0;
}