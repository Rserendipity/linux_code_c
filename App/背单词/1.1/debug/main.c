#define _CRT_SECURE_NO_WARNINGS 1
#include "readInfo.h"

int main() {
    Word* w = NULL;
    Buffer* b = NULL;
    wordInit(&w);
    bufferInit(&b);

    // ��ʱ������ת���û�������Ϣ
    char ch = 0;
    // ������
    while (1) {
        // ������������뵱ǰ�ĵ��ʺ�������˼
        getEnglish(b, &w);
        getChinese(b, &w);

        // printf("%s\n", en_buffer);
        //������ĵ�ʾ��
        printf("��ǰ����������˼����, ����������next, �˳�������end\n\n");
        printf("%s\n\n", b->ch_buffer);
        printf("����Ӣ��:>");
        while (1) {
            // �û�����
            for (int i = 0; (ch = getchar()) != '\n'; i++) {
                b->usr_buffer[i] = ch;
            }
            // ����next������������һ��
            if (strcmp(b->usr_buffer, "next") == 0) {
                printf("��������ǣ�%s\n", b->en_buffer);
                printf("3�������\n");
                Sleep(3000);
                system("cls");
                break;
            } else if (strcmp(b->usr_buffer, b->en_buffer) == 0) {
                // ������ȷ
                printf("��ϲ������ȷ��\n");
                printf("2�������\n");
                Sleep(2000);
                system("cls");
                break;
            } else if (strcmp(b->usr_buffer, "end") == 0) {
                printf("2����˳�!\n");
                Sleep(2000);
                goto end;
            } else {
                // ����û�������
                printf("����Ŷ,��������:>");
                memset(b->usr_buffer, 0, USR_BUFFER);
                continue;
            }
        }
        // ��յ�ǰ�Ļ�����
        memset(b->en_buffer, 0, EN_BUFFER);
        memset(b->ch_buffer, 0, CH_BUFFER);
        memset(b->usr_buffer, 0, USR_BUFFER);
    }

end:

    wordDel(w);
    bufferDel(b);

    return 0;
}