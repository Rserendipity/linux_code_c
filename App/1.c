#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int isword(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

int main() {
    // 打开文件
    FILE* pf_en = fopen("./en.txt", "r");
    FILE* pf_ch = fopen("./ch.txt", "r");
    FILE* pf_mem = fopen("./info.txt", "r");

    // 记录当前定位的位置信息,方便下次打开的时候直接读取
    // 相当于是保存记录
    unsigned long long seck_en = 0;
    unsigned long long seck_ch = 0;

    // 各自缓冲区
    char en_buffer[30] = {0};
    char ch_buffer[100] = {0};

    // 偏移文件指针,即恢复记录
    fscanf(pf_mem, "%lld %lld", &seck_en, &seck_ch);
    fseek(pf_ch, seck_ch, 0);
    fseek(pf_en, seck_en, 0);

    char ch = 0;
    for (int j = 0; j < 5; j++) {
        for (int i = 0; (ch = fgetc(pf_en)) != '\n'; i++) {
            en_buffer[i] = ch;
        }
        for (int i = 0; (ch = fgetc(pf_ch)) != '\n'; i++) {
            if (i > 0 && isword(ch) && !isword(ch_buffer[i - 1])) {
                ch_buffer[i++] = '\n';
            }
            ch_buffer[i] = ch;
        }
        printf("%s\n", en_buffer);
        printf("%s\n", ch_buffer);
        memset(en_buffer, 0, 30);
        memset(ch_buffer, 0, 100);
    }

    // 释放文件流
    fclose(pf_en);
    fclose(pf_ch);
    fclose(pf_mem);
    return 0;
}