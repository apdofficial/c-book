#include "stdio.h"
#include "stdlib.h"
#include "test_assert.h"
#include "book.h"

int test_max(){
    test_assert(max(1,2) == 2);
    test_assert(max(2,1) == 2);

    test_assert(max(-1,-2) == -1);
    test_assert(max(-2,-1) == -1);

    test_assert(max(0,1) == 1);
    test_assert(max(0,-1) == 0);

    return EXIT_SUCCESS;
}

int test_sum_m(){
    int expected_sum = 0;

    for (int j = 0; j < get_m_len(); ++j)
        expected_sum += get_m_ptr()[j];

    int actual_sum = sum_m_elems();

    test_assert(expected_sum == actual_sum);

    return EXIT_SUCCESS;
}

int test_increment(){
    test_assert(increment_by_one(1) == 2);
    test_assert(increment_by_one(-1) == 0);
    test_assert(increment_by_one(0) == 1);

    return EXIT_SUCCESS;
}

int test_invoke(){
    test_assert(invoke_func_and_print(increment_by_one, 1) == 2);
    test_assert(invoke_func_and_print(increment_by_one, -1) == 0);
    test_assert(invoke_func_and_print(increment_by_one, 0) == 1);

    return EXIT_SUCCESS;
}

int main(){
    printf("Testing test_max.\n");
    if (test_max()) return EXIT_FAILURE;
    printf("Testing test_sum_m.\n");
    if (test_sum_m()) return EXIT_FAILURE;
    printf("Testing test_increment.\n");
    if (test_increment()) return EXIT_FAILURE;
    printf("Testing test_invoke.\n");
    if (test_invoke()) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}