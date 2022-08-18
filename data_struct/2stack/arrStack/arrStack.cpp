#include "arrStack.h"

int Stack::getSize() {
    return this->num;
}

int Stack::Pop() {
    if(this->top != 0) {
        return this->p[this->top--];
    }
    return -1;
}

void Stack::Push(int num) {
    if(this->top == this->num) {
        this->num *= 2;
        this->p = (int*)realloc(this->p, sizeof(int) * this->num);
    }
    this->p[this->top++] = num;
}
