#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define	FUNCTION_INVOKE_FAILURE	1
#define	FUNCTION_INVOKE_SUCCESS	0

#define Abs(i) ((i) < 0 ? -(i) : (i))
#define AbsM(i, flag) ((i) >= 0 ? (i) : ((i)==(flag) ? (flag) : -(i))) //avoid signed integer overflows

/**
 * Safe conversion
 * Check the rage of the type into which you are going to cast the given data type.
 */
errno_t do_stuff(signed long value) {
    if ((value < SCHAR_MIN) || (value > SCHAR_MAX)) {
        return ERANGE;
    }
    signed char sc = (signed char) value; // Cast quiets warning
    return 0;
}

void my_swap(size_t *a, size_t *b);

void increment(void);

unsigned int retrieve(void);

int invoke_function(int index);

void print_binary(int n, int len);


#endif