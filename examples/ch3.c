#include <limits.h>
#include "book.h"
#include "stdlib.h"
#include <stdint.h>

int main()
{
    unsigned int ui = UINT_MAX;  // 4,294,967,295 on x86
    ui++; // wraparound to 0
    printf("ui = %u\n", ui); // ui is 0
    ui--;  // wraparound to UINT_MAX
    printf("ui = %u\n", ui); // ui is 4,294,967,295

    // The sign weight of the ones' complement is given by -(2^{N-1}-1)
    // The sign weight of the two's complement is given by -(2^{N-1})

    print_binary(INT8_MAX, 8);
    print_binary(INT8_MIN, 8);

    print_binary(INT16_MAX, 16);
    print_binary(INT16_MIN, 16);

    print_binary(CHAR_MAX, 8);
    print_binary(CHAR_MIN, 8);

    signed int si = -25;
    signed int abs_si = Abs(si); // abs_si = ((si) < 0 ? -(si) : (si))
    printf("%d\n", abs_si); // prints 25

    int err = cast_value(123456);
    if (err == ERANGE)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}