#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* lch;
    struct Node* rch;
} Node;

typedef struct Stack {
    Node* data;
    struct Stack* next;
} Stack;

Stack* creatStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = NULL;
    s->next = NULL;
    return s;
}

void Push(Stack* s, Node* node) {
    Stack* newStack = creatStack();
    newStack->next = s->next;
    newStack->data = node;
    s->next = newStack;
}

int isEmpty(Stack* s) {
    if (s->next == NULL)
        return 1;
    else
        return 0;
}

Node* Pop(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
    } else {
        Stack* temp = s->next;
        Node* node = temp->data;
        s->next = temp->next;
        free(temp);
        return node;
    }
}

void preOrder(Node* node) {
    if (node) {
        printf("%c ", node->data);
        preOrder(node->lch);
        preOrder(node->rch);
    }
}

void noRecursiveOrder(Node* tree) {
    Node* node = tree;
    Stack* s = creatStack();
    while (node || !isEmpty(s)) {
        if (node) {
            Push(s, node);
            node = node->lch;
        } else {
            node = Pop(s);
            printf("%c ", node->data);
            node = node->rch;
        }
    }
}

void createTree(Node** tree, char* s, int* index) {
    char ch = s[*index];
    *index += 1;
    if (ch == '#') {
        *tree = NULL;
    } else {
        *tree = (Node*)malloc(sizeof(Node));
        (*tree)->data = ch;
        createTree(&((*tree)->lch), s, index);
        createTree(&((*tree)->rch), s, index);
    }
}

int main() {
    Node* tree = NULL;
    int index = 0;
    char arr[] = "ABD##E##CF##G##";

    createTree(&tree, arr, &index);

    preOrder(tree);
    printf("\n");

    noRecursiveOrder(tree);
    printf("\n");

    return 0;
}
