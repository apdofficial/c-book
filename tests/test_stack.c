#include "stdio.h"
#include "stdlib.h"
#include "test_assert.h"
#include "stack.h"

int test_stack_auto() {
    char data[2] = {0x41, 0x42}; // { A, B }
    char data2[2] = {0x44, 0x45}; // { D, E }

    Stack *auto_stack = stack_create_auto();

    test_assert(auto_stack->size == 0);
    test_assert(auto_stack->resizeStrategy == STACK_RESIZE_STRATEGY_AUTO);
    test_assert(stack_is_empty(auto_stack));

    test_assert(stack_push(auto_stack, data, 2));
    test_assert(stack_push(auto_stack, data, 2));

    Item *item2 = stack_peek(auto_stack);
    for (int i = 0; i < item2->size; ++i) {
        test_assert(item2->data[i] == data[i]);
    }

    test_assert(stack_push(auto_stack, data, 2));
    test_assert(stack_push(auto_stack, data2, 2));

    Item *item4 = stack_peek(auto_stack);
    for (int i = 0; i < item4->size; ++i) {
        test_assert(item4->data[i] == data2[i]);
    }

    test_assert(stack_pop(auto_stack));
    test_assert(stack_num_items(auto_stack) == 3);
    test_assert(stack_is_empty(auto_stack) == false);

    test_assert(stack_pop(auto_stack));
    test_assert(stack_pop(auto_stack));
    test_assert(stack_pop(auto_stack));

    test_assert(stack_num_items(auto_stack) == 0);
    test_assert(stack_pop(auto_stack) == false);

    test_assert(stack_is_empty(auto_stack));

    return EXIT_SUCCESS;
}

int test_stack_fixed() {
    char data[2] = {0x41, 0x42}; // { A, B }
    char data2[2] = {0x44, 0x45}; // { D, E }

    Stack *fixed_stack = stack_create_fixed(3);

    test_assert(fixed_stack->size == 3);
    test_assert(fixed_stack->resizeStrategy == STACK_RESIZE_STRATEGY_FIXED);
    test_assert(stack_is_empty(fixed_stack));

    test_assert(stack_push(fixed_stack, data, 2));
    test_assert(stack_push(fixed_stack, data, 2));

    Item *item2 = stack_peek(fixed_stack);
    for (int i = 0; i < item2->size; ++i) {
        test_assert(item2->data[i] == data[i]);
    }

    test_assert(stack_push(fixed_stack, data2, 2));
    test_assert(stack_push(fixed_stack, data, 2) == false);

    Item *item3 = stack_peek(fixed_stack);
    for (int i = 0; i < item3->size; ++i) {
        test_assert(item3->data[i] == data2[i]);
    }

    test_assert(fixed_stack->size == 3);
    test_assert(stack_num_items(fixed_stack) == 3);


    test_assert(stack_pop(fixed_stack));
    test_assert(stack_num_items(fixed_stack) == 2);
    test_assert(stack_is_empty(fixed_stack) == false);

    test_assert(stack_pop(fixed_stack));
    test_assert(stack_pop(fixed_stack));
    test_assert(stack_pop(fixed_stack) == false);

    test_assert(stack_num_items(fixed_stack) == 0);
    test_assert(stack_pop(fixed_stack) == false);

    test_assert(stack_is_empty(fixed_stack));

    return EXIT_SUCCESS;
}

int main() {
    printf("Testing test_stack_auto.\n");
    if (test_stack_auto()) return EXIT_FAILURE;
    printf("Testing test_stack_fixed.\n");
    if (test_stack_fixed()) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}