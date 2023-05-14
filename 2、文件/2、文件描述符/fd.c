#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    // 默认从3开始
    // 0 1 2 分别被stdin，stdout，stderr占用，
    // 于是我们可以关闭stdout，然后再打开文件，此时的stdout就会被转移至打开的文件
    close(1); // 关闭stdout
    int fd = open("./test.txt", O_CREAT | O_APPEND | O_WRONLY, 0666);
    printf("%d\n", fd);

    const char *p = "hello world\n";
    write(fd, p, strlen(p)); // 会直接输出到文件中

    close(fd);
    return 0;
}