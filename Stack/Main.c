#include <stdio.h>

#include "Stack.c"

int main(void) {
    unsigned int capacity = 5U;
    stack_test *stack = createStack(capacity);
    printf("%d\n",isEmpty(stack));
    push(stack, 0.0F);
    push(stack, 1.0F);
    push(stack, 2.0F);
    push(stack, 3.0F);
    push(stack, 4.0F);
    printf("%d\n", isFull(stack));
    printStack(stack);
    printf("\n");
    pop(stack);
    printStack(stack);
    printf("%lf\n", top(stack));
    printf("%d\n",isEmpty(stack));
    printf("%d\n", isFull(stack));
    freeStack(stack);
return 0;
}