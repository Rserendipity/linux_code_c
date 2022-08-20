#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int isword(char ch) {
    // 是字母返回真
    return (ch >= 'a' && ch <= 'z');
}

void getEnglish(char* en_buffer, FILE* pf_en, long long* seck_en) {
    char ch = 0;
    for (int i = 0; (ch = fgetc(pf_en)) != '\n'; i++) {
        en_buffer[i] = ch;
        // 每读取到一个字节，偏移量就加一
        *seck_en += 1;
    }
    // 把单词转换成纯小写
    en_buffer = strlwr(en_buffer);
    // 结束时便宜两个字节，跳过回车和换行
    *seck_en += 2;
}

void getChinese(char* ch_buffer, FILE* pf_ch, long long* seck_ch) {
    char ch = 0;
    for (int i = 0; (ch = fgetc(pf_ch)) != '\n'; i++) {
        // 不是首元素  且当前读取到的是字母  且前一个元素不是字母
        if (i > 0 && isword(ch) && !isword(ch_buffer[i - 1])) {
            // 在缓冲区内添加一个换行
            ch_buffer[i++] = '\n';
        }
        ch_buffer[i] = ch;
        // 每读取到一个字节，偏移量就加一
        *seck_ch += 1;
    }
    // 结束时偏移两个字节，跳过回车和换行
    *seck_ch += 2;
}

int main() {
    // 打开文件
    FILE* pf_en = fopen("./data/en.txt", "r");
    FILE* pf_ch = fopen("./data/ch.txt", "r");
    FILE* pf_mem = fopen("./data/info.txt", "r");
    if (pf_en == NULL || pf_ch == NULL || pf_mem == NULL) {
        printf("必要文件丢失或被修改！\n");
        getchar();
        return -1;
    }

    // 记录当前定位的位置信息,方便下次打开的时候直接读取
    // 相当于是保存记录
    unsigned long long seck_en = 0;
    unsigned long long seck_ch = 0;

    // 各自缓冲区
    char* en_buffer = (char*)calloc(50, 1);
    char* ch_buffer = (char*)calloc(300, 1);
    char* usr_buffer = (char*)calloc(50, 1);

    // 偏移文件指针,恢复记录
    fscanf(pf_mem, "%lld %lld", &seck_en, &seck_ch);
    fseek(pf_ch, seck_ch, 0);
    fseek(pf_en, seck_en, 0);
    // 改变偏移量以后就可以释放掉当前的info.txt的文件指针了，释放资源
    fclose(pf_mem);

    // 临时变量，转存用户输入信息
    char ch = 0;
    // 主程序
    while (1) {
        // 往缓冲区里放入当前的单词和中文意思
        getEnglish(en_buffer, pf_en, &seck_en);
        getChinese(ch_buffer, pf_ch, &seck_ch);

        // printf("%s\n", en_buffer);
        //输出中文的示意
        printf("当前单词中文意思如下, 不会请输入next, 退出请输入end\n");
        printf("%s\n", ch_buffer);
        printf("输入英文:>");
        while (1) {
            // 用户输入
            for (int i = 0; (ch = getchar()) != '\n'; i++) {
                usr_buffer[i] = ch;
            }
            // 输入next跳过，进行下一个
            if (strcmp(usr_buffer, "next") == 0) {
                printf("这个单词是：%s\n", en_buffer);
                printf("3秒后清屏\n");
                Sleep(3000);
                system("cls");
                break;
            } else if (strcmp(usr_buffer, en_buffer) == 0) {
                // 输入正确
                printf("恭喜输入正确！\n");
                printf("2秒后清屏\n");
                Sleep(2000);
                system("cls");
                break;
            } else if (strcmp(usr_buffer, "end") == 0) {
                printf("2秒后退出!\n");
                Sleep(2000);
                goto end;
            } else {
                // 清空用户的输入
                printf("不是哦,重新输入:>");
                memset(usr_buffer, 0, 50);
                continue;
            }
        }
        // 清空当前的缓冲区
        memset(en_buffer, 0, 50);
        memset(ch_buffer, 0, 300);
        memset(usr_buffer, 0, 50);
    }

end:
    // 把当前的字节偏移信息写入到文件，记录当前背到哪里了
    pf_mem = fopen("./data/info.txt", "w");
    fprintf(pf_mem, "%lld %lld", seck_en, seck_ch);

    // 释放文件流
    fclose(pf_en);
    fclose(pf_ch);
    fclose(pf_mem);

    // 释放开辟的空间
    free(en_buffer);
    free(ch_buffer);
    free(usr_buffer);
    return 0;
}