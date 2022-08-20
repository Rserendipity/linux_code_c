#include "stack.h"

Stack *InitStack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->data = NULL;
    newStack->next = NULL;
    return newStack;
}
void Push(Stack *stack, Node *node) {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));

    newStack->data = node;
    newStack->next = stack->next;
    stack->next = newStack;
}

Node *Pop(Stack *stack) {
    if (!isEmpty(stack)) {
        Node *temp = stack->next->data;
        Stack *next = stack->next;
        stack->next = next->next;
        free(next);
        return temp;
    } else
        return NULL;
}

int isEmpty(Stack *stack) {
    if (stack->next == NULL) {
        return 1;
    } else
        return 0;
}