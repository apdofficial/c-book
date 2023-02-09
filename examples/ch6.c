#include "book.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Chapter 6
 * Dynamically allocated memory
 * reallloc, calloc
 */
int main() {
    /**
     * Flexible array members.
     */
    widget *widget1 = malloc_widget(10);
    free(widget1);

    /**
    * Variable length array (VLA).
    * Verify the provided size. Can overflow in the stack frame.
    * In GCC you cna use -Wvla-larger-than=size to detect stack frame overflow.
    */

    size_t size = 12;
    printf("%zu\n", size); // prints 12
    (void) sizeof(int[size++]);
    printf("%zu\n", size); // prints 13
    typedef int foo[size++];
    printf("%zu\n", size); // prints 14
    foo a;
    printf("%d\n", a[0]);

    int rows = 2;
    int columns = 2;
    int matrix[rows][columns]; // VLA can not be initialized because the size is not known at the compile time.
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 2;
    matrix[1][1] = 1;

    int sum = matrix_sum(2, 2, matrix);
    printf("Matrix sum = %d\n", sum);
}
