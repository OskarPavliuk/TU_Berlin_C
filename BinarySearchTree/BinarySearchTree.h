#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define NO_VALUE (float)(INFINITY)

typedef struct node
{
    float value;
    struct node *left;
    struct node *right;
} node_t;

node_t *createBST(float value);

node_t *freeBST(node_t *node);

void insertNode(node_t *root, node_t *node);

node_t *minValueNode(node_t *node);

node_t *removeNode(node_t *root, float value);

void printBST(node_t *node);

#endif // BINARY_SEARCH_TREE_H