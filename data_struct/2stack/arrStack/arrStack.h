#ifndef _ARRSTACK_H_
#define _ARRTSTACK_H_

#include <iostream>

typedef class Stack {
public:
    Stack() : num(2), top(0), p(new int[2]()) {}
    int Pop();
    void Push(int data);
    int getSize();

private:
    int num;
    int top;
    int* p;
} Stack;

#endif