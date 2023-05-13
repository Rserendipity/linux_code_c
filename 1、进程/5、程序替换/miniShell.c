#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENTH 1024
#define MAX_COMMAND_ARGS 64

void spilt(char *command, char *args[])
{
    int i = 0;
    for (args[i] = strtok(command, " "); args[i]; args[i] = strtok(NULL, " "))
        i++;
}

int main()
{
    while (1)
    {
        printf("[cjj@miniShell]# "); // 输出命令提示符
        fflush(stdout);

        char commandStr[MAX_COMMAND_LENTH] = "";
        char *commandArgs[MAX_COMMAND_ARGS] = {NULL};
        fgets(commandStr, sizeof(commandStr), stdin); // 获取一行命令
        commandStr[strlen(commandStr) - 1] = 0;       // 去除换行
        spilt(commandStr, commandArgs);               // 把命令进行拆分

        pid_t id = fork();
        assert(id >= 0);
        if (id == 0)
        {
            // child，执行程序替换
            execvp(commandArgs[0], commandArgs);
            exit(0);
        }

        // father, 等待子进程结束
        int state = 0;
        pid_t wt_id = waitpid(id, &state, 0);
        // printf("single:%d, exit_code:%d\n", state & 0x7f, (state >> 8) & 0xff);
    }

    return 0;
}