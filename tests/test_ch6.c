#include "test_assert.h"
#include "book.h"
#include <stdlib.h>
#include <stdio.h>

int test_malloc_widget(){
    widget *widget1 = malloc_widget(10);
    test_assert(widget1->size == 10);

    return EXIT_SUCCESS;
}

int test_matrix_sum(){
    int matrix[3][2] = { {1,2}, {2,3}, {3,4}};
    int sum = matrix_sum(3,2, matrix);
    test_assert(sum == 15);

    return EXIT_SUCCESS;
}

int main(){
    printf("Testing test_malloc_widget.\n");
    if(test_malloc_widget()) return 1;
    printf("Testing test_matrix_sum.\n");
    if(test_matrix_sum()) return 1;
    return EXIT_SUCCESS;
}