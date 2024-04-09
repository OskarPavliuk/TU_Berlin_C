#ifndef DOUBLE_LINKES_LIST_H
#define DOUBLE_LINKES_LIST_H

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define NO_VALUE (float)(INFINITY)

typedef struct node{
    struct node *prev;
    struct node *next;
    float *value;
} node_t;

typedef struct list{
    node_t *front;
    node_t *back;
    unsigned int size;
} list_t;

node_t *createNode(float value);

node_t *freeNode(node_t *node);

list_t *createList(void);

list_t *freeList(list_t *list);

void pushBack(list_t *list, node_t *node);

float popBack(list_t *list);

void pushFront(list_t *list, node_t *node);

float popFront(list_t *list);

float popNode(list_t *list, unsigned int idx);

void pushNode(list_t *list, node_t *node, unsigned int idx);

void printList(list_t *list);

#endif // DOUBLE_LINKES_LIST_H