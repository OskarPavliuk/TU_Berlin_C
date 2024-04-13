#include<stdio.h>

#include"BinarySearchTree.c"

int main(){
    node_t *bst = createBST(5);
    node_t *node_1 = createBST(4);
    node_t *node_2 = createBST(6);
    insertNode(bst, node_1);
    insertNode(bst, node_2);
    printBST(bst);
    freeBST(bst);
    return 0;
}