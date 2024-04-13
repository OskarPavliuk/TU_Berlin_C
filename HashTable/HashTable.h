#ifndef QUEUE_H
#define QUEUE_H

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define NO_VALUE (float)(INFINITY)

#define TABLE_SIZE (unsigned int)13u
#define MAX_NAME_SIZE (unsigned int)256u
#define DELETED_KEY "DELETED"
#define DELETED_KEY_SIZE (unsigned int)8u

typedef struct item
{
    char key[MAX_NAME_SIZE];
    float value;
} item_t;

typedef struct hash_table
{
    unsigned int size;
    unsigned int capacity;
    item_t *data;
} hash_table_t;

hash_table_t *createHashTable(void);

hash_table_t *freeHashTable(hash_table_t *hash_table);

unsigned int hash(char key[MAX_NAME_SIZE]);

void printHashTable(hash_table_t *hash_table);

void insertItem(hash_table_t *hash_table, item_t *item);

float getValue(hash_table_t *hash_table, char key[MAX_NAME_SIZE]);

float removeItem(hash_table_t *hash_table, char key[MAX_NAME_SIZE]);

#endif // QUEUE_H