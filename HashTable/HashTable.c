#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

hash_table_t *createHashTable(void)
{
    hash_table_t *hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

    if (NULL == hash_table)
    {
        return NULL;
    }

    const size_t data_size = TABLE_SIZE * sizeof(item_t);
    item_t *data = (item_t *)malloc(data_size);

    if (NULL == data)
    {
        free(hash_table);

        return NULL;
    }

    for (unsigned int i = 0; i < TABLE_SIZE; i++)
    {
        strncpy(data[i].key, DELETED_KEY, DELETED_KEY_SIZE);
        data[i].value = NO_VALUE;
    }

    hash_table->size = 0u;
    hash_table->capacity = TABLE_SIZE;
    hash_table->data = data;

    return hash_table;
}

hash_table_t *freeHashTable(hash_table_t *hash_table)
{
    if (NULL != hash_table)
    {
        if (NULL != hash_table->data)
        {
            free(hash_table->data);
        }

        free(hash_table);
    }

    return NULL;
}

unsigned int hash(char key[MAX_NAME_SIZE])
{
    unsigned int hash_value = 0u;

    for (unsigned int i = 0; i < MAX_NAME_SIZE; i++)
    {
        if ('\0' != key[i])
        {
            hash_value = ((unsigned int)(hash_value * 128U) + (unsigned int)(key[i])) %
                         TABLE_SIZE;
        }
        else
        {
            break;
        }
    }

    return hash_value;
}

void printHashTable(hash_table_t *hash_table)
{
    if (NULL == hash_table)
    {
        return;
    }

    printf("\nHashTable contains %u elements with a capcity of %u.\n",
           hash_table->size,
           hash_table->capacity);

    for (unsigned int i = 0u; i < TABLE_SIZE; i++)
    {
        item_t *item = &hash_table->data[i];
        printf("Index: %u, Key: %s, Value %f\n", i, item->key, item->value);
    }
}

void insertItem(hash_table_t *hash_table, item_t *item)
{
    if (hash_table->size == hash_table->capacity)
    {
        return;
    }

    unsigned int hash_value = hash(item->key);
    int compare = strncmp(hash_table->data[hash_value].key, item->key, MAX_NAME_SIZE);

    while (NO_VALUE != hash_table->data[hash_value].value)
    {
        if (0 == compare)
        {
            break;
        }

        hash_value = (hash_value + 1u) % TABLE_SIZE;
        compare = strncmp(hash_table->data[hash_value].key, item->key, MAX_NAME_SIZE);
    }

    hash_table->data[hash_value] = *item;

    if (0 != compare)
    {
        hash_table->size++;
    }
}

float getValue(hash_table_t *hash_table,char key[MAX_NAME_SIZE])
{
    if (0u == hash_table->size)
    {
        return NO_VALUE;
    }

    size_t key_len = strlen(key);

    unsigned int hash_value = hash(key);
    item_t *item = &hash_table->data[hash_value];

    unsigned int cnt = 0U;
    while (0 != strncmp(item->key, key, key_len))
    {
        hash_value = (hash_value + 1u) % TABLE_SIZE;
        item = &hash_table->data[hash_value];

        if (cnt >= TABLE_SIZE)
        {
            break;
        }

        ++cnt;
    }

    return item->value;
}

float removeItem(hash_table_t *hash_table, char key[MAX_NAME_SIZE])
{
    if (0u == hash_table->size)
    {
        return NO_VALUE;
    }

    size_t key_len = strlen(key);

    unsigned int hash_value = hash(key);
    item_t *item = &hash_table->data[hash_value];

    unsigned int cnt = 0U;
    while (0 != strncmp(item->key, key, key_len))
    {
        hash_value = (hash_value + 1u) % TABLE_SIZE;
        item = &hash_table->data[hash_value];

        if (cnt >= TABLE_SIZE)
        {
            break;
        }

        ++cnt;
    }

    float value = item->value;

    hash_table->data[hash_value].value = NO_VALUE;
    strncpy(hash_table->data[hash_value].key, DELETED_KEY, DELETED_KEY_SIZE);
    hash_table->size--;

    return value;
}