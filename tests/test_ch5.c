#include <stdlib.h>
#include <stdio.h>
#include "test_assert.h"
#include "book.h"
#include <limits.h>
#include <stdint.h>

int test_absolute_value(){
    test_assert(absolute_value(-1) == 1);
    test_assert(absolute_value(0) == 0);
    test_assert(absolute_value(1) == 1);
    test_assert(absolute_value(INT32_MAX) == INT32_MAX);
    test_assert(absolute_value(INT32_MIN) == (long)INT32_MAX + 1);

    return EXIT_SUCCESS;
}


int test_memset(){
    char data[2] = {0x41, 0x42}; // { A, B }

    book_memset(data, (int)0x00, 2);

    for (int i = 0; i < 2; ++i) {
        test_assert(data[i] == 0x00);
    }

    return EXIT_SUCCESS;
}

int test_memcopy(){
    char src_data[2] = {0x41, 0x42}; // { A, B }
    char dest_data[2] = {0x44, 0x45}; // { D, E }

    book_memcopy(dest_data, src_data, 2);

    for (int i = 0; i < 2; ++i) {
        test_assert(src_data[i] == dest_data[i]);
    }

    return EXIT_SUCCESS;
}

int test_find_element(){
    int elements[2] = {10, 20};

    int element_index = find_element(2, elements, 10);
    test_assert(element_index == 0);
    
    element_index = find_element(2, elements, 20);
    test_assert(element_index == 1);

    element_index = find_element(2, elements, 5);
    test_assert(element_index == -1);

    return EXIT_SUCCESS;
}

int main(){
    printf("int is %lu bytes, and %lu bits\n", sizeof(int), CHAR_BIT * sizeof (int));

    printf("Testing test_absolute_value.\n");
    if (test_absolute_value()) return EXIT_FAILURE;
    printf("Testing test_memset.\n");
    if (test_memset()) return EXIT_FAILURE;
    printf("Testing test_memcopy.\n");
    if (test_memcopy()) return EXIT_FAILURE;
    printf("Testing test_find_element.\n");
    if (test_find_element()) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}