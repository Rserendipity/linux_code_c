/*
    使用命令 mkfifo 可以创建一个有名的管道文件
    一个进程w，另一个进程r，就可以实现不相关的进程之间的通信
    可以类似于匿名管道

    man 3 里也有对应的代码库函数 int mkfifo(const char *pathname, mode_t mode);
    第一个参数是路径，第二个参数是文件的权限
    成功返回0，失败返回-1，并设置全局errno标志
*/
#include <unistd.h>

int main()
{
    unlink("./pipe");
    return 0;
}