#ifndef CBOOK_STACK_H
#define CBOOK_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * Stack.
 *
 * Time Complexity:
 *  Insert/ Delete: O(1)
 *  Peek: O(n)
 *
 * Space Complexity:
 *  Space: O(n)
 */

typedef enum{
    STACK_RESIZE_STRATEGY_FIXED,
    STACK_RESIZE_STRATEGY_AUTO,
} StackResizeStrategyType;

struct StackItem {
    int size;
    char *data;
};

typedef struct StackItem StackItem;

struct Stack {
    unsigned long size;
    StackItem *items;
    int top;
    StackResizeStrategyType resizeStrategy;
};

typedef struct Stack Stack;

Stack *stack_create(StackResizeStrategyType resizeStrategy, int size);

/**
 * Create stack that contains fixed size.
 */
#define stack_create_fixed(size)    stack_create(STACK_RESIZE_STRATEGY_FIXED, size)

/**
 * Create stack that can automatically resize.
 */
#define stack_create_auto()         stack_create(STACK_RESIZE_STRATEGY_AUTO, 0)

//Push:     Add an item to the top of a stack
bool stack_push(Stack *stack, char *data, int size);

//Pop:      Remove an item from the top of a stack
StackItem *stack_pop(Stack *stack);

//IsEmpty:  Check if the stack is empty
bool stack_is_empty(Stack * stack);

//Peek:     Get the value of the top item without removing it
StackItem *stack_peek(Stack * stack);

int stack_num_items(Stack *stack);

#endif //CBOOK_STACK_H
