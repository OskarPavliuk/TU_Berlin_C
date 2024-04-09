#include <stdio.h>

#include "DoubleLinkedList.c"

int main(){
    node_t *a = createNode(5.0f);
    node_t *b = createNode(6.0f);
    node_t *c = createNode(7.0f);
    node_t *d = createNode(8.0f);
    node_t *e = createNode(6.5f);
    list_t *list = createList();
    pushFront(list, a);
    pushFront(list, b);
    printList(list);
    popBack(list);
    printList(list);
    pushBack(list, c);
    pushBack(list, d);
    printList(list);
    pushNode(list, e, 1);
    printList(list);
    printf("%f", valueAtIdx(list, 3));


    // Clean-Up
    freeNode(a);
    freeNode(b);
    freeNode(c);
    freeNode(d);
    freeNode(e);
    freeList(list);
    return 0;
}