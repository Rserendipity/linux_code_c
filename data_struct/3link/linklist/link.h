#ifndef _LINK_H_
#define _LINK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Link {
    Node* head;
    Node* tail;
    int size;
} Link;

Link* linkInit();

void linkPushHead(Link* list, int data);
void linkPopHead(Link* list);

void linkPushTail(Link* list, int data);
void linkPopTail(Link* list);

void linkPirnt(Link* list);
void delLink(Link* list);

#endif