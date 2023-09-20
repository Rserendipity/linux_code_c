#include "myFile.h"

myFILE *myfopen(const char *path, const char *mode)
{
    // 创建文件指针并给成员初始化
    myFILE *fp = (myFILE *)malloc(sizeof(myFILE));
    // fp->fd = open();
    fp->size = 0;
    memset(fp->_buffer, 0, sizeof(fp->_buffer));

    // 分析模式
    if (strcmp(mode, "w") == 0)
        fp->fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0666);
    else if (strcmp(mode, "a") == 0)
        fp->fd = open(path, O_CREAT | O_APPEND | O_WRONLY, 0666);
    else if (strcmp(mode, "r") == 0)
        fp->fd = open(path, O_RDONLY);

    assert(fp->fd >= 0);

    // 返回
    return fp;
}
size_t myfwrite(const void *dest, size_t size, size_t nsize, myFILE *file)
{
    size_t total_size = size * nsize;
    // 可以直接放入缓冲区
    if (total_size + file->size < BUFF_MAX - 1)
    {
        memcpy(file->_buffer + file->size, dest, total_size);
        file->size += total_size;
    }
    else // 放不下，只能放部分
    {
        memcpy(file->_buffer + file->size, dest, BUFF_MAX - file->size - 1);
        total_size -= BUFF_MAX - file->size - 1;
        file->size = BUFF_MAX;
    }

    // 刷新策略
    if (file->_buffer[file->size - 1] == '\n') // 行刷新
    {
        myfflush(file);
    }
    if (file->size == BUFF_MAX) // 全缓冲
    {
        myfflush(file);
    }

    return total_size;
}
void myfclose(myFILE *file)
{
    close(file->fd);
}

void myfflush(myFILE *file)
{
    write(file->fd, file->_buffer, file->size);
}