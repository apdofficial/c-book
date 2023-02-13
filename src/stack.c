#include "stack.h"
#include <string.h>
#include <assert.h>

Stack *stack_create(StackResizeStrategyType resizeStrategy, int size) {
    if (resizeStrategy == STACK_RESIZE_STRATEGY_FIXED && size < 1){
        printf("Invalid stack size %d. Failed to create new Stack.\n", size);
        return NULL;
    }

    Stack *stack = (Stack *) malloc( sizeof (Stack) * size);
    if (stack == NULL){
        printf("Failed to create new Stack.\n");
        return NULL;
    }

    stack->top = -1;
    stack->size = size;
    stack->resizeStrategy = resizeStrategy;

    return stack;
}

bool double_stack_memory(Stack *stack){
    size_t new_size = stack->size * 2;
    if (new_size == 0) new_size = 1;
    assert(new_size != 0);
    if (stack->size == 0)  assert(new_size == stack->size + 1);
    printf("Automatically resizing the stack from %lu to %zu items\n", stack->size, new_size);
    Item *new_items = (Item *) malloc(sizeof (Item) * (new_size));
    if (new_items == NULL){
        printf("Failed to resize given Stack.\n");
        return false;
    }
    memcpy(new_items, stack->items, stack->size);
    free(stack->items);
    stack->items = new_items;
    stack->size = new_size;
    return true;
}

bool stack_push(Stack *stack, char *data, int size) {
    // handle error cases first
    if (((unsigned long) (stack->top + 1)) >= stack->size) { // not enough memory in the stack
        if (stack->resizeStrategy == STACK_RESIZE_STRATEGY_AUTO) {
            bool stackResized = double_stack_memory(stack);
            if (stackResized == false) {
                printf("Failed to resize the stack memory. Failed to push new item to the stack.\n");
                return false;
            }
        } else if (stack->resizeStrategy == STACK_RESIZE_STRATEGY_FIXED) {
            printf("No enough memory in the stack. Failed to push new item to the stack.\n");
            return false;
        } else {
            printf("Unknown error. Failed to push new item to the stack.\n");
            return false;
        }
    }

    Item *item = item_create(data, size);
    if (item == NULL) {
        return false;
    }

    if (stack_is_empty(stack)) { // empty stack
        stack->items = item;
        stack->top = 0;
    } else{ // we have enough stace in the stack here
        stack->top++;
        stack->items[stack->top] = *item;
    }

    return true;
}

Item *stack_pop(Stack *stack) {
    // TODO instead of allocation heap memory, return struct with error enum anv value
    //  we use dynamic memory to indicate error with a NULL pointer
    if (stack_is_empty(stack)){
        printf("Failed to pop Item. Stack is empty.\n");
        return NULL;
    }
    Item item = stack->items[stack->top];
    Item *item_p = item_create(item.data, item.size);
    stack->top--;
    return item_p;
}

bool stack_is_empty(Stack *stack) {
    return stack->top == -1;
}


Item *stack_peek(Stack *stack) {
    // TODO instead of allocation heap memory, return struct with error enum anv value
    //  we use dynamic memory to indicate error with a NULL pointer
    if (stack_is_empty(stack)){
        printf("Failed to peak Item. Stack is empty.\n");
        return NULL;
    }
    return &stack->items[stack->top];
}

int stack_num_items(Stack *stack){
    return stack->top + 1;
}