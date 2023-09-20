#include <stdio.h>
#include <unistd.h>

// main函数的参数，有三个
// agrc 接受 参数有几个
// argv 接受 每一个参数
// ebv  接受 用户的环境变量
int main(int agrc, char *argv[], char *env[])
{
    for (int i = 0; i < agrc; i++)
        printf("%d:%s\n", i, argv[i]);

    for (int i = 0; env[i]; i++)
        printf("%d:%s\n", i, env[i]);

    return 0;
}