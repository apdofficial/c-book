#include "stdio.h"
#include "stdlib.h"
#include "test_assert.h"
#include "book.h"

int test_swap(void){
    size_t a = 1;
    size_t b = 2;

    test_assert(a == 1 && b == 2);
    my_swap(&a, &b);
    test_assert(a == 2 && b == 1);

    return EXIT_SUCCESS;
}

int test_counter(void){
    test_assert(retrieve() == 0);
    for (int i = 0; i < 5; ++i) {
        increment();
    }
    test_assert(retrieve() == 5);

    return EXIT_SUCCESS;
}

int test_functions_p(void){
    test_assert(invoke_function(0) == FUNCTION_INVOKE_FAILURE);

    test_assert(invoke_function(1) == FUNCTION_INVOKE_SUCCESS);
    test_assert(invoke_function(2) == FUNCTION_INVOKE_SUCCESS);
    test_assert(invoke_function(3) == FUNCTION_INVOKE_SUCCESS);

    test_assert(invoke_function(4) == FUNCTION_INVOKE_FAILURE);

    return EXIT_SUCCESS;
}

int main(){
    int res = EXIT_SUCCESS;

    printf("Testing test_swap.\n");
    if (test_swap()) return 1;
    printf("Testing test_functions_p.\n");
    if (test_functions_p()) return 1;
    printf("Testing test_counter.\n");
    if (test_counter()) return 1;

    return res;
}