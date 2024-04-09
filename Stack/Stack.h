#ifndef STACK_H
#define STACK_H

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define NO_VALUE (float) (INFINITY);

typedef struct stack
{
    unsigned int size;
    unsigned int capacity;
    float *data;
} stack_test;

stack_test *createStack(unsigned int capacity);

stack_test *freeStack(stack_test *stack);

void printStack(stack_test *stack);

bool isFull(stack_test *stack);

bool isEmpty(stack_test *stack);

float top(stack_test *stack);

void push(stack_test *stack, float value);

float pop(stack_test *stack);




#endif // STACK_H