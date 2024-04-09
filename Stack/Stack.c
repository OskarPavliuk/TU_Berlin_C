#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

stack_test *createStack(unsigned int capacity)
{
    stack_test *stack = (stack_test *)malloc(sizeof(stack_test));

    if (NULL == stack)
    {
        return NULL;
    }

    unsigned int data_size = capacity * sizeof(float);

    float *data = (float *)malloc(data_size);

    if (NULL == data)
    {
        free(stack);

        return NULL;
    }

    stack->size = 0U;
    stack->capacity = capacity;
    stack->data = data;

    return stack;
}


stack_test *freeStack(stack_test *stack)
{
    if (NULL == stack)
    {
        return NULL;
    }

    if (NULL != stack->data)
    {
        free(stack->data);
    }

    free(stack);

    return NULL;
}

void printStack(stack_test *stack)
{
    if (NULL == stack)
    {
        return;
    }

    printf("Stack has a size of %u and a capacity of: %u\n",
           stack->size,
           stack->capacity);

    for (unsigned int i = stack->size; i > 0; i--)
    {
        printf("Index: %d, Value: %f\n", i - 1u, stack->data[i - 1u]);
    }
}

bool isFull(stack_test *stack)
{
    return stack->size >= stack->capacity;
}

bool isEmpty(stack_test *stack)
{
    return stack->size == 0u;
}

float top(stack_test *stack)
{
    if (isEmpty(stack))
    {
        return NO_VALUE;
    }

    unsigned int top_idx = stack->size - 1u;
    return stack->data[top_idx];
}

void push(stack_test *stack, float value)
{
    if (isFull(stack))
    {
        return;
    }

    stack->data[stack->size] = value;
    stack->size++;
}

float pop(stack_test *stack)
{
    if (isEmpty(stack))
    {
        return NO_VALUE;
    }

    float top_value = top(stack);
    stack->size--;
    return top_value;
}

