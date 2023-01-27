#include "stdio.h"

#include "test_assert.h"
#include "book.h"

int test_swap()
{
    size_t a = 1;
    size_t b = 2;

    test_assert(a == 1 && b == 2);
    my_swap(&a, &b);
    test_assert(a == 2 && b == 1);

    return 0;
}

int main()
{
    test_swap();
}