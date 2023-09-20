#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    // 没有换行，不会刷新缓冲区
    printf("abcabc");

    // exit(0); // 是C语言封装的函数，会进行清理工作，比如刷新stdout的缓冲区、文件缓冲区等

    _exit(0); // 系统提供的函数，不会进行任何清理工作，直接回收进程的pcb（process control block）
    return 0;
}