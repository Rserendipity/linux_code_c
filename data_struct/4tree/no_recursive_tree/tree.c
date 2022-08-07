#include "tree.h"

void createTree(Node **tree, char *s, int *index) {
    char ch = s[(*index)++];
    if (ch == '#') {
        *tree = NULL;
    } else {
        *tree = (Node *)malloc(sizeof(Node));
        (*tree)->data = ch;
        createTree(&((*tree)->lch), s, index);
        createTree(&((*tree)->rch), s, index);
    }
}

void preOrder(Node *tree) {
    if (tree) {
        printf("%c ", tree->data);
        preOrder(tree->lch);
        preOrder(tree->rch);
    }
}
