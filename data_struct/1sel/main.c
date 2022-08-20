#include "seq.h"

void test1() {
    SeqList* list = SeqInit();
    SeqPush(list, 0, 1);
    SeqPush(list, 0, 2);
    SeqPush(list, 0, 3);
    SeqPush(list, 0, 4);
    SeqPush(list, 0, 5);
    SeqPush(list, 0, 6);
    SeqPrint(list);

    SeqPop(list, 1);
    SeqPop(list, 2);

    SeqPrint(list);
    SeqDel(list);
}

int main() {
    test1();
    return 0;
}