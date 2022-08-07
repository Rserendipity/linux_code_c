#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

typedef struct Stack {
    Node *data;
    struct Stack *next;
} Stack;

Stack *InitStack();
void Push(Stack *stack, Node *node);
Node *Pop(Stack *stack);
int isEmpty(Stack *stack);

#endif