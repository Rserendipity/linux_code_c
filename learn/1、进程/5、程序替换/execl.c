#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

// 以下是库函数原型
// exec --- execute的缩写
// l    --- list的缩写，列表的方式传入参数
// v    --- vector的缩写，数组的方式传入参数
// p    --- path的缩写，默认带路径，第一个参数可以直接传可执行程序
// e    --- environ的缩写，导入环境变量
// int execl(const char *path, const char *arg, ...);
// int execlp(const char *file, const char *arg, ...);
// int execle(const char *path, const char *arg, ..., char *const envp[]);
// int execv(const char *path, char *const argv[]);
// int execvp(const char *file, char *const argv[]);
// int execvpe(const char *file, char *const argv[], char *const envp[]);

// 上述的库函数，都是对这个系统接口的封装
// int execve(const char *filename, char *const argv[], char *const envp[]);

int main()
{
    // 1、创建子进程
    // 2、使用exec系列函数，替换子进程的代码和数据
    // 3、子进程执行代码，父进程等待子进程的结果返回
    // 即父进程把任务交给子进程执行
    // 执行程序替换以后的pid不会改变
    // 程序替换只是替换了代码和数据，不会更改内核的pcb结构
    pid_t id = fork();
    assert(id >= 0);
    if (id == 0)
    {
        // child
        char *const parr[] = {
            "ls",
            "-al",
            NULL};
        execvp("ls", parr);
        exit(-1);
    }

    // father
    waitpid(id, NULL, 0); // 阻塞等待子进程结束

    return 0;
}