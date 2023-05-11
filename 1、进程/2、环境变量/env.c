#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int agrc, char *argv[], char *env[])
{
    // 环境变量很多，我们不需要自己来分割，有一个库函数用来做这件事
    // char* getenv(const char*) 接受字符串，通过这个字符串k，在环境变量里找对应的v
    // 不存在就会返回 NULL
    printf("%s\n", getenv("USER"));

    // 环境变量可以继承自父进程
    // shell: export abc=123
    // 导入一个abc变量，值为123
    printf("%s\n", getenv("abc"));

    // shell添加变量，但不导入，此变量不会被子进程继承
    // shell: cjj=123
    printf("%s\n", getenv("cjj")); // NULL
    return 0;
}