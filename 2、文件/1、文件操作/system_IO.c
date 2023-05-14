#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define ONE 0x01
#define TWO 0x02
#define TREE 0x04
#define FORE 0x10
#define FIVE 0x20

void BitMap(int flags)
{
    // 拿到第一个标志位的信息
    if (flags & ONE)
        printf("ONE ");
    if (flags & TWO) // 第二个标志位
        printf("TWO ");
    if (flags & TREE) // 依次类推
        printf("TREE ");
    if (flags & FORE)
        printf("FORE ");
    if (flags & FIVE)
        printf("FIVE ");
}

int main()
{
    // 一个int类型，理论上最多可以设置32个状态，在函数里可以位运算拿到这些flag
    // BitMap(ONE | TWO);
    // printf("\n---------------\n");
    // BitMap(FORE | FIVE);
    // printf("\n---------------\n");
    // BitMap(ONE | FIVE);

    // write
    // int fid = open("./test.txt", O_CREAT | O_WRONLY, 0666);
    // const char *p = "this is a test";
    // write(fid, p, strlen(p));
    // close(fid);

    // read
    int fid = open("./test.txt", O_RDONLY);
    char str[128] = {0};
    size_t n = read(fid, str, 128);
    str[n] = 0;
    printf("%s\n", str);

    return 0;
}