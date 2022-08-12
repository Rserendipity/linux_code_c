#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define CH_BUFFER   300
#define EN_BUFFER   50
#define USR_BUFFER  50

typedef struct Word {
	FILE* pf_en;
	FILE* pf_ch;
	FILE* pf_mem;
	long long seck_en;
	long long seck_ch;
} Word;
typedef struct Buffer {
	char* en_buffer;
	char* ch_buffer;
	char* usr_buffer;
} Buffer;

void wordInit(Word** w);
void bufferInit(Buffer** buffer);
void getEnglish(Buffer* b, Word** w);
void getChinese(Buffer* b, Word** w);
int isWord(char ch);
void wordDel(Word* w);
void bufferDel(Buffer* buffer);
