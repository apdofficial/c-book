#ifndef CBOOK_STACK_H
#define CBOOK_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"


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


struct Stack {
    int top;
    StackResizeStrategyType resizeStrategy;
    unsigned long size;
    Item *items;
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
#define stack_create_auto()        stack_create(STACK_RESIZE_STRATEGY_AUTO, 0)

/**
 * Add an item to the top of a stack
 * @param stack
 * @param data
 * @param size
 * @return
 */
bool stack_push(Stack *stack, char *data, int size);

/**
 * Remove an item from the top of a stack
 * @param stack
 * @return
 */
Item *stack_pop(Stack *stack);

/**
 * Check if the stack is empty
 * @param stack
 * @return
 */
bool stack_is_empty(Stack * stack);

/**
 * Get the value of the top item without removing it
 * @param stack
 * @return
 */
Item *stack_peek(Stack * stack);

/**
 * Get number of item in a given stack.
 * @param stack
 * @return
 */
int stack_num_items(Stack *stack);

#endif //CBOOK_STACK_H
