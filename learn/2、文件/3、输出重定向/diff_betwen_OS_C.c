#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    // 正常运行，会输出两行，分别是通过C语言和系统调用写入的
    // 输出重定向后，会输出三行，C语言的接口会写入两次，系统写入一次
    //
    // 正常运行，会向标准输出写入，标准输出的写入的刷新策略是行缓冲，所以会直接刷新
    // 子进程继承的C语言缓冲区是空白的
    //
    // 输出重定向以后，实际是写入文件，文件写入的刷新策略是全缓冲
    // 写满以后才会刷新，所以fork以后，子进程会继承父进程的C语言缓冲区内容
    // 在其进程生命周期结束后，父子进程都会刷新至文件，导致被写入两次
    const char *p = "this is a test\n";
    fprintf(stdout, p);

    write(1, p, strlen(p));

    fork();
    return 0;
}