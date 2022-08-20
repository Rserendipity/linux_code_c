#include "seq.h"
SeqList* SeqInit() {
    SeqList* s = (SeqList*)malloc(sizeof(SeqList));
    s->arr = (SeqType*)malloc(sizeof(SeqType) * 2);
    s->nums = 0;
    s->size = 2;
    return s;
}

void addSize(SeqList* list) {
    int newSize = list->size * 2;
    list->arr = (SeqType*)realloc(list->arr, sizeof(SeqType) * newSize);
    list->size = newSize;
}

void SeqPush(SeqList* list, int pos, SeqType data) {
    assert(pos <= list->nums);
    if (list->nums == list->size)
        addSize(list);
    for (int i = list->nums; i > pos; i--) {
        list->arr[i] = list->arr[i - 1];
    }
    list->arr[pos] = data;
    list->nums += 1;
}

SeqType SeqPop(SeqList* list, int pos) {
    assert(pos < list->nums);
    SeqType temp = list->arr[pos];
    for (int i = pos; i < list->nums - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }
    list->nums -= 1;
    return temp;
}

SeqType SeqSearch(SeqList* list, int pos) {
    assert(pos >= list->nums);
    return list->arr[pos];
}

void SeqPrint(SeqList* list) {
    for (int i = 0; i < list->nums; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

void SeqDel(SeqList* list) {
    free(list->arr);
    free(list);
}