#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

const char *itos(int n)
{
    static char t[100] = "";
    int i = 0, j = 0;
    while (n)
    {
        t[j++] = n % 10 + '0';
        n /= 10;
    }
    j--;
    for (i = 0; i < j; i++, j--)
    {
        char ch = t[i];
        t[i] = t[j];
        t[j] = ch;
    }
    return t;
}

int main()
{
    pid_t id = fork();
    if (id == 0)
    {
        // child
        int a = 0;
        for (int i = 0; i < 3; i++)
        {
            printf("id: %d, time: %d\n", getpid(), i);
            // a = 100 / a; // 会引发除零错误，系统发出8号信号
            sleep(1);
        }
        exit(123);
    }

    // // 等待成功返回孩子的pid，并把参数设置为孩子的状态
    // // 参数是返回参数，0000 0000    0000 0000
    // // 前8位是返回值，第9位是 core dump标志，剩下的是信号标志
    // // 无信号，则是0，代表程序正常结束
    // // 程序正常，返回0，代表程序结果正确
    // // 有信号的情况下，说明程序直接产生了错误，所以返回值无效
    // // 无信号的情况下，说明程序正常结束，再看返回值
    // int state = 0;
    // char str[100] = "kill -9 ";
    // strcat(str, itos(id));
    // sleep(3);
    // // printf("%s\n", itos(id));
    // system(str);

    // // // 等待函数，等待所有的
    // // pid_t wt_id = wait(&state);
    // // 等待特定pid的
    // pid_t wt_id = waitpid(id, &state, 0); // 阻塞等待

    // printf("father: %d, wait for child: %d, return state: %d, single state %d\n",
    //        getpid(), wt_id, state >> 8 & 0xff, state & 0x7f);

    while (1)
    {
        int state = 0;
        pid_t wait_id = waitpid(id, &state, WNOHANG);
        if (wait_id < 0)
        {
            perror("waitpid:");
            exit(-1);
        }
        else if (wait_id == 0) // 子进程还没有退出
        {
            // 执行自己的任务
            printf("do some thing\n");
            sleep(1);
            continue;
        }
        else // 获取了子进程的pid，说明子进程已退出
        {
            printf("wait success! sign_id:%d, return_id:%d\n", state & 0x7f, state >> 8 & 0xff);
            break;
        }
    }

    return 0;
}