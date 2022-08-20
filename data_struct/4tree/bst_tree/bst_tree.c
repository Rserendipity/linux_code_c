#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* lch;
    struct Node* rch;
} Node;

void preOrder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrder(root->lch);
        preOrder(root->rch);
    }
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->lch);
        printf("%d ", root->data);
        inOrder(root->rch);
    }
}

void insert(Node** tree, int num) {
    if (*tree == NULL) {
        *tree = (Node*)malloc(sizeof(Node));
        (*tree)->data = num;
        (*tree)->lch = NULL;
        (*tree)->rch = NULL;
    } else if ((*tree)->data > num) {
        insert(&((*tree)->lch), num);
    } else {
        insert(&((*tree)->rch), num);
    }
}

int main(int agrs, char* argv[]) {
    Node* tree = NULL;
    int arr[] = {5, 3, 2, 7, 9, 1, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
        insert(&tree, arr[i]);

    preOrder(tree);
    printf("\n");

    inOrder(tree);
    printf("\n");

    return 0;
}
