#ifndef _SEQ_H_
#define _SEQ_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int SeqType;

typedef struct SeqList {
    SeqType* arr;
    int size;
    int nums;
} SeqList;

//
SeqList* SeqInit();

// zeng
void SeqPush(SeqList* list, int pos, SeqType data);
// shan
SeqType SeqPop(SeqList* list, int pos);
// cha
SeqType SeqSearch(SeqList* list, int pos);
// dayin
void SeqPrint(SeqList* list);

void SeqDel(SeqList* list);

#endif