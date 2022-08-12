#define _CRT_SECURE_NO_WARNINGS 1
#include "readInfo.h"

// ��ʼ��w,��ʼ��ʧ��ʱֱ���˳�����
void wordInit(Word** w) {
    // Ϊw����ռ�
    *w = calloc(1, sizeof(Word));
    // ���ļ�
    (*w)->pf_ch = fopen("./data/ch.txt", "r");
    (*w)->pf_en = fopen("./data/en.txt", "r");
    (*w)->pf_mem = fopen("./data/info.txt", "r");
    if ((*w)->pf_en == NULL || (*w)->pf_ch == NULL || (*w)->pf_mem == NULL) {
        printf("��Ҫ�ļ���ʧ���޸ģ�\n");
        getchar();
        exit(-1);
    }

    // ƫ���ļ�ָ��,�ָ���¼
    fscanf((*w)->pf_mem, "%lld %lld", &(*w)->seek_en, &(*w)->seek_ch);
    fseek((*w)->pf_ch, (*w)->seek_ch, 0);
    fseek((*w)->pf_en, (*w)->seek_en, 0);
    // �ı�ƫ�����Ժ�Ϳ����ͷŵ���ǰ��info.txt���ļ�ָ���ˣ��ͷ���Դ
    fclose((*w)->pf_mem);
}
void bufferInit(Buffer** buffer) {
    // ���Ի�����
    *buffer = (Buffer*)calloc(1, sizeof(Buffer));
    (*buffer)->en_buffer = (char*)calloc(1, EN_BUFFER);
    (*buffer)->ch_buffer = (char*)calloc(1, CH_BUFFER);
    (*buffer)->usr_buffer = (char*)calloc(1, USR_BUFFER);
}

// ��w���pf_en��ȡһ�����ʣ�д�뵽buffer->en_buffer
void getEnglish(Buffer* b, Word** w) {
    char ch = 0;
    for (int i = 0; (ch = fgetc((*w)->pf_en)) != '\n'; i++) {
        b->en_buffer[i] = ch;
        // ÿ��ȡ��һ���ֽڣ�ƫ�����ͼ�һ
        (*w)->seek_en += 1;
    }
    // �ѵ���ת���ɴ�Сд
    b->en_buffer = _strlwr(b->en_buffer);
    // ����ʱ���������ֽڣ������س��ͻ���
    (*w)->seek_en += 2;
}

// �ж�����ַ��Ƿ�Ϊ��ĸ
int isWord(char ch) {
    // ����ĸ������
    return (ch >= 'a' && ch <= 'z');
}

// ��w���pf_ch��ȡһ��������˼��д�뵽buffer->ch_buffer
void getChinese(Buffer* b, Word** w) {
    char ch = 0;
    for (int i = 0; (ch = fgetc((*w)->pf_ch)) != '\n'; i++) {
        // ������Ԫ��  �ҵ�ǰ��ȡ��������ĸ  ��ǰһ��Ԫ�ز�����ĸ
        if (i > 0 && isWord(ch) && !isWord(b->ch_buffer[i - 1])) {
            // �ڻ����������һ������
            b->ch_buffer[i++] = '\n';
        }
        b->ch_buffer[i] = ch;
        // ÿ��ȡ��һ���ֽڣ�ƫ�����ͼ�һ
        (*w)->seek_ch += 1;
    }
    // ����ʱƫ�������ֽڣ������س��ͻ���
    (*w)->seek_ch += 2;
}

// ������ȣ��ر��ļ������ͷ�w��ָ��Ŀռ�
void wordDel(Word* w) {
    // �ѵ�ǰ���ֽ�ƫ����Ϣд�뵽�ļ�����¼��ǰ����������
    w->pf_mem = fopen("./data/info.txt", "w");
    fprintf(w->pf_mem, "%lld %lld", w->seek_en, w->seek_ch);

    // �ͷ��ļ���
    fclose(w->pf_en);
    fclose(w->pf_ch);
    fclose(w->pf_mem);
    free(w);
}

// �ͷŵ�ȫ���Ļ�����
void bufferDel(Buffer* buffer) {
    free(buffer->ch_buffer);
    free(buffer->en_buffer);
    free(buffer->usr_buffer);
    free(buffer);
}
