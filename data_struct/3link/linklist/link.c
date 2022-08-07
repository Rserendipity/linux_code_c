#include "link.h"

Link* linkInit() {
    Link* list = (Link*)malloc(sizeof(Link));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void linkPushHead(Link* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        newNode->next = list->head;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size += 1;
}

void linkPopHead(Link* list) {
    if (list->head == NULL)
        return;
    Node* temp = list->head;
    list->head = temp->next;
    free(temp);
    list->size -= 1;
}

void linkPushTail(Link* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        newNode->next = list->head;
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size += 1;
}

void linkPopTail(Link* list) {
    Node* temp = list->head;
    for (int i = 0; i < list->size - 1; i++) {
        temp = temp->next;
    }
    free(list->tail);
    list->tail = temp;
    list->size -= 1;
}

void linkPirnt(Link* list) {
    Node* temp = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delLink(Link* list) {
    Node* temp = list->head->next;
    for (int i = 0; i < list->size - 1; i++) {
        free(list->head);
        list->head = temp;
        temp = temp->next;
    }
    free(list);
}
