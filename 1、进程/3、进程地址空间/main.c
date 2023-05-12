#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int g_val = 10;

int main()
{
    pid_t id = fork();

    // 父子进程打出的g_val结果不同，但是地址相同
    // 原因：父子进程都有独立的进程地址空间，在各自的进程空间上，对应的地址是相同的
    // 但是通过页表映射的真实物理地址不同
    if (id == 0)
    {
        // child
        g_val = 100;
        while (1)
        {
            printf("%d %d %p\n", getpid(), g_val, &g_val);
            sleep(1);
        }
    }
    else
    {
        // fahter
        g_val = 200;
        while (1)
        {
            printf("%d %d %p\n", getpid(), g_val, &g_val);
            sleep(1);
        }
    }

    return 0;
}