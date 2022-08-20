#ifndef CODE_TREE_H
#define CODE_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *lch;
    struct Node *rch;
} Node;

void createTree(Node **tree, char *s, int *index);
void preOrder(Node *tree);

#endif  // CODE_TREE_H
