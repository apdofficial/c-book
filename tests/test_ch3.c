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
    for (int i = SCHAR_MIN; i < SCHAR_MAX; ++i) {
        test_assert(can_cast_to_char(i) == 1);
    }
    // Remaining test to check boundary
    int can_cast = can_cast_to_char(SCHAR_MAX+1);
    test_assert(can_cast == 0);
    can_cast = can_cast_to_char(SCHAR_MIN-1);
    test_assert(can_cast == 0);

    return EXIT_SUCCESS;
}

int main()
{
    int res = EXIT_SUCCESS;

    printf("Testing Abs.\n");
    if (test_abs()) return 1;
    printf("Testing can cast to char.\n");
    if (test_cast_to_char()) return 1;

    return res;
}