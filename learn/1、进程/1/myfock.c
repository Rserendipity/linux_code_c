#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t ret = fork();
    int val = 0;
    printf("%p\n", &val);

    if (ret == 0)
    {
        // 子进程
        // 子进程的返回值为0
        while (1)
        {
            val = 10;
            printf("子，pid：%d，ppid：%d val:%d, &val:%p\n", getpid(), getppid(), val);
            sleep(1);
        }
    }
    else if (ret > 0)
    {
        // 父进程
        // 父进程的返回值是子进程的pid
        while (1)
        {
            val = 20;
            printf("父，pid：%d，ppid：%d val:%d, &val:%p\n", getpid(), getppid(), val, &val);
            sleep(1);
        }
    }
    return 0;
}