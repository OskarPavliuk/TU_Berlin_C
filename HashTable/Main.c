#include <stdio.h>
#include "HashTable.c"

int main(){

    item_t item1 = {"Oskar", 5};
    item_t item2 = {"Mcqueen", 6};
    hash_table_t *new_table = createHashTable();
    insertItem(new_table, &item1);
    insertItem(new_table, &item2);
    printHashTable(new_table);
    printf("\n");
    printf("%f", getValue(new_table, "Oskar"));
    freeHashTable(new_table);
    return 0;
}