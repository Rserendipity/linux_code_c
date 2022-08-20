#define _CRT_SECURE_NO_WARNINGS 1
#include "readInfo.h"

int main() {
    Word* w = NULL;
    Buffer* b = NULL;
    wordInit(&w);
    bufferInit(&b);

    // 临时变量，转存用户输入信息
    char ch = 0;
    // 主程序
    while (1) {
        // 往缓冲区里放入当前的单词和中文意思
        getEnglish(b, &w);
        getChinese(b, &w);

        // printf("%s\n", en_buffer);
        //输出中文的示意
        printf("当前单词中文意思如下, 不会请输入next, 退出请输入end\n\n");
        printf("%s\n\n", b->ch_buffer);
        printf("输入英文:>");
        while (1) {
            // 用户输入
            for (int i = 0; (ch = getchar()) != '\n'; i++) {
                b->usr_buffer[i] = ch;
            }
            // 输入next跳过，进行下一个
            if (strcmp(b->usr_buffer, "next") == 0) {
                printf("这个单词是：%s\n", b->en_buffer);
                printf("3秒后清屏\n");
                Sleep(3000);
                system("cls");
                break;
            } else if (strcmp(b->usr_buffer, b->en_buffer) == 0) {
                // 输入正确
                printf("恭喜输入正确！\n");
                printf("2秒后清屏\n");
                Sleep(2000);
                system("cls");
                break;
            } else if (strcmp(b->usr_buffer, "end") == 0) {
                printf("2秒后退出!\n");
                Sleep(2000);
                goto end;
            } else {
                // 清空用户的输入
                printf("不是哦,重新输入:>");
                memset(b->usr_buffer, 0, USR_BUFFER);
                continue;
            }
        }
        // 清空当前的缓冲区
        memset(b->en_buffer, 0, EN_BUFFER);
        memset(b->ch_buffer, 0, CH_BUFFER);
        memset(b->usr_buffer, 0, USR_BUFFER);
    }

end:

    wordDel(w);
    bufferDel(b);

    return 0;
}