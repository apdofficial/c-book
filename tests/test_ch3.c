#include <limits.h>
#include "stdio.h"
#include "stdlib.h"
#include "test_assert.h"
#include "book.h"

int test_abs(){
    test_assert(Abs(-25) == 25);
    test_assert(Abs(25) == 25);
    test_assert(Abs(0) == 0);

    return EXIT_SUCCESS;
}

int test_cast_to_char(){
    // happy flow
    for (int i = SCHAR_MIN; i < SCHAR_MAX; ++i) {
        test_assert(can_cast_to_char(i) == 1);
    }

    // sad flow
    // Remaining test to check boundary
    test_assert(can_cast_to_char(SCHAR_MAX+1) == 0);
    test_assert(can_cast_to_char(SCHAR_MIN-1) == 0);

    return EXIT_SUCCESS;
}

int main(){
    printf("Testing test_abs.\n");
    if (test_abs()) return EXIT_FAILURE;
    printf("Testing test_cast_to_char.\n");
    if (test_cast_to_char()) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}