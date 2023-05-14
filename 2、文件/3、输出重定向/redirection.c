#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd = open("./dup2.txt", O_CREAT | O_APPEND | O_WRONLY, 0666);
    dup2(fd, 1); // 使用当前打开的文件，覆盖掉stdout
    const char *p = "redirection test\n";
    write(1, p, strlen(p));

    close(fd);
    return 0;
}