#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    while (1)
    {
        printf("进程pid：%d，父进程ppid：%d\n", getpid(), getppid());
        sleep(1);
    }
    return 0;
}