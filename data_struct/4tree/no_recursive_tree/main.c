#include "stack.h"
#include "tree.h"

void noRecursivePre(Node *tree) {
    Node *node = tree;
    Stack *s = InitStack();
    while (node || !isEmpty(s)) {
        if (node) {
            printf("%c ", node->data);
            Push(s, node);
            node = node->lch;
        } else {
            node = Pop(s);
            node = node->rch;
        }
    }
}

void noRecursiveIn(Node *tree) {
    Node *node = tree;
    Stack *s = InitStack();
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

int main() {
    Node *tree = NULL;

    /*
            A
          B   C
        D  E F  G
       ## ## ## ##

       ABD##E##CF##G##
    */
    char arr[] = "ABD##E##CF##G##";
    int index = 0;

    Stack *stack = InitStack();

    createTree(&tree, arr, &index);

    // preOrder(tree);

    noRecursivePre(tree);
    printf("\n");

    noRecursiveIn(tree);
    printf("\n");

    return 0;
}
