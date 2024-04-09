#include <stdio.h>
#include <stdlib.h>

#include "DoubleLinkedList.h"

node_t *createNode(const float value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (NULL == node)
    {
        return NULL;
    }

    float *p_value = (float *)malloc(sizeof(float));

    if (NULL == p_value)
    {
        free(node);

        return NULL;
    }

    *p_value = value;

    node->next = NULL;
    node->prev = NULL;
    node->value = p_value;

    return node;
}

node_t *freeNode(node_t *node){
if (NULL == node)
{
return NULL;
}

if (node->value != NULL)
{
free(node->value);
}

free(node);

return NULL;
}

list_t *createList(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));

    if (NULL == list)
    {
        return NULL;
    }

    list->front = NULL;
    list->back = NULL;
    list->size = 0u;

    return list;
}

list_t *freeList(list_t *list)
{
    if (NULL == list)
    {
        return NULL;
    }

    free(list);

    return NULL;
}


void pushBack(list_t *list, node_t *node)
{
    if (NULL == list || NULL == node)
    {
        return;
    }

    if (list->size > 0u)
    {
        node->next = NULL;
        node->prev = list->back;
        list->back->next = node;
        list->back = node;
    }
    else
    {
        node->next = NULL;
        node->prev = NULL;
        list->back = node;
        list->front = node;
    }

    list->size++;
}


void pushFront(list_t *list, node_t *node)
{

    if (list->size > 0u){
        node->next = list->front;
        node->prev = NULL;
        list->front->prev = node;
        list->front = node;
    }
    else {
        node->next = NULL;
        node->prev = NULL;
        list->back = node;
        list->front = node;
    }

list->size++;
}


float popBack(list_t *list)
{
if (NULL == list)
{
return NO_VALUE;
}

node_t *node = list->back;
float value = *(node->value);

if (list->size > 1u)
{
list->back = node->prev;
list->back->next = NULL;
}
else
{
list->back = NULL;
list->front = NULL;
}

list->size--;

return value;
}


float popFront(list_t *list)
{
    if (NULL == list)
    {
        return NO_VALUE;
    }

    node_t *node = list->front;
    float value = *(node->value);

    if (list->size > 1u)
    {
        list->front = node->next;
        list->front->prev = NULL;
    }
    else
    {
        list->back = NULL;
        list->front = NULL;
    }

    list->size--;

    return value;
}

void printList(list_t *list)
{
    if (NULL == list)
    {
        return;
    }

    printf("\nList contains %u elements.\n", list->size);

    unsigned int current_idx = 0u;
    node_t *node_at_idx = list->front;

    while (current_idx < list->size)
    {
        printf("Index: %u, Value: %f\n", current_idx, *(node_at_idx->value));

        node_at_idx = node_at_idx->next;
        current_idx++;
    }
}

float popNode(list_t *list, unsigned int idx)
{
    if (NULL == list || idx >= list->size)
    {
        return NO_VALUE;
    }

    if (0u == idx)
    {
        return popFront(list);
    }

    if ((list->size - 1u) == idx)
    {
        return popBack(list);
    }

    unsigned int current_idx = 0u;
    node_t *node_at_idx = list->front;

    while (current_idx < idx)
    {
        node_at_idx = node_at_idx->next;

        current_idx++;
    }

    float value = *(node_at_idx->value);

    node_at_idx->next->prev = node_at_idx->prev;
    node_at_idx->prev->next = node_at_idx->next;

    list->size--;

    return value;
}


void pushNode(list_t *const list, node_t *const node, const uint32_t idx)
{
    if (NULL == list || NULL == node || idx >= list->size)
    {
        return;
    }

    if (0u == idx)
    {
        pushFront(list, node);
    }

    if ((list->size - 1u) == idx)
    {
        pushBack(list, node);
    }

    unsigned int current_idx = 0u;
    node_t *node_at_idx = list->front;

    while (current_idx < idx)
    {
        node_at_idx = node_at_idx->next;

        current_idx++;
    }

    node->prev = node_at_idx->prev;
    node->next = node_at_idx;
    node_at_idx->prev->next = node;
    node_at_idx->prev = node;

    list->size++;
}

float valueAtIdx(list_t *list, unsigned int idx)
{
    if (NULL == list || idx >= list->size)
    {
        return NO_VALUE;
    }

    if (0u == idx)
    {
        return *(list->front->value);
    }

    if ((list->size - 1u) == idx)
    {
        return *(list->back->value);
    }

    unsigned int current_idx = 0u;
    node_t *node_at_idx = list->front;

    while (current_idx < idx)
    {
        node_at_idx = node_at_idx->next;

        if (current_idx == idx)
        {
            break;
        }

        current_idx++;
    }

    return *(node_at_idx->value);
}



