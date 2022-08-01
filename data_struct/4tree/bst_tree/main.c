#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* lch;
    struct Node* rch;
} Node;

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

void preOrder(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preOrder(root->lch);
        preOrder(root->rch);
    }
}

int main(int agrs, char* argv[]) {
    Node* tree = NULL;
    int index = 0;

    createTree(&tree, argv[1], &index);

    preOrder(tree);
    printf("\n");

    return 0;
}
