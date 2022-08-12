#define _CRT_SECURE_NO_WARNINGS 1
#include "readInfo.h"

// 初始化w,初始化失败时直接退出程序
void wordInit(Word** w) {
    // 为w分配空间
    *w = calloc(1, sizeof(Word));
    // 打开文件
    (*w)->pf_ch = fopen("./data/ch.txt", "r");
    (*w)->pf_en = fopen("./data/en.txt", "r");
    (*w)->pf_mem = fopen("./data/info.txt", "r");
    if ((*w)->pf_en == NULL || (*w)->pf_ch == NULL || (*w)->pf_mem == NULL) {
        printf("必要文件丢失或被修改！\n");
        getchar();
        exit(-1);
    }

    // 偏移文件指针,恢复记录
    fscanf((*w)->pf_mem, "%lld %lld", &(*w)->seek_en, &(*w)->seek_ch);
    fseek((*w)->pf_ch, (*w)->seek_ch, 0);
    fseek((*w)->pf_en, (*w)->seek_en, 0);
    // 改变偏移量以后就可以释放掉当前的info.txt的文件指针了，释放资源
    fclose((*w)->pf_mem);
}
void bufferInit(Buffer** buffer) {
    // 各自缓冲区
    *buffer = (Buffer*)calloc(1, sizeof(Buffer));
    (*buffer)->en_buffer = (char*)calloc(1, EN_BUFFER);
    (*buffer)->ch_buffer = (char*)calloc(1, CH_BUFFER);
    (*buffer)->usr_buffer = (char*)calloc(1, USR_BUFFER);
}

// 从w里的pf_en获取一个单词，写入到buffer->en_buffer
void getEnglish(Buffer* b, Word** w) {
    char ch = 0;
    for (int i = 0; (ch = fgetc((*w)->pf_en)) != '\n'; i++) {
        b->en_buffer[i] = ch;
        // 每读取到一个字节，偏移量就加一
        (*w)->seek_en += 1;
    }
    // 把单词转换成纯小写
    b->en_buffer = _strlwr(b->en_buffer);
    // 结束时便宜两个字节，跳过回车和换行
    (*w)->seek_en += 2;
}

// 判断这个字符是否为字母
int isWord(char ch) {
    // 是字母返回真
    return (ch >= 'a' && ch <= 'z');
}

// 从w里的pf_ch获取一组中文意思，写入到buffer->ch_buffer
void getChinese(Buffer* b, Word** w) {
    char ch = 0;
    for (int i = 0; (ch = fgetc((*w)->pf_ch)) != '\n'; i++) {
        // 不是首元素  且当前读取到的是字母  且前一个元素不是字母
        if (i > 0 && isWord(ch) && !isWord(b->ch_buffer[i - 1])) {
            // 在缓冲区内添加一个换行
            b->ch_buffer[i++] = '\n';
        }
        b->ch_buffer[i] = ch;
        // 每读取到一个字节，偏移量就加一
        (*w)->seek_ch += 1;
    }
    // 结束时偏移两个字节，跳过回车和换行
    (*w)->seek_ch += 2;
}

// 保存进度，关闭文件流，释放w所指向的空间
void wordDel(Word* w) {
    // 把当前的字节偏移信息写入到文件，记录当前背到哪里了
    w->pf_mem = fopen("./data/info.txt", "w");
    fprintf(w->pf_mem, "%lld %lld", w->seek_en, w->seek_ch);

    // 释放文件流
    fclose(w->pf_en);
    fclose(w->pf_ch);
    fclose(w->pf_mem);
    free(w);
}

// 释放掉全部的缓冲区
void bufferDel(Buffer* buffer) {
    free(buffer->ch_buffer);
    free(buffer->en_buffer);
    free(buffer->usr_buffer);
    free(buffer);
}
