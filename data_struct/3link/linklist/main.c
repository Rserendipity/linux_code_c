#include "link.h"

void test1() {
    Link* list = linkInit();
    linkPushHead(list, 1);
    linkPushHead(list, 2);
    linkPushHead(list, 3);
    linkPushHead(list, 4);
    linkPushHead(list, 5);
    
    linkPirnt(list);
    delLink(list);
}

int main() {
    test1();
    return 0;
}
