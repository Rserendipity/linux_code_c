#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *lch;
    struct Node *rch;
} Node;

void createTree(Node **tree, char *s, int *index) {
    char ch = s[(*index)++];
    if (ch == '#')
        *tree = NULL;
    else {
        *tree = (Node *) malloc(sizeof(Node));
        (*tree)->data = ch;
        createTree(&((*tree)->lch), s, index);
        createTree(&((*tree)->rch), s, index);
    }
}

void preOrder(Node *node) {
    if (node) {
        printf("%c ", node->data);
        preOrder(node->lch);
        preOrder(node->rch);
    }
}

int main() {
    Node *tree = NULL;
    char arr[] = "ABD##E##CF##G##";
    int index = 0;

    createTree(&tree, arr, &index);
    preOrder(tree);

    return 0;
}