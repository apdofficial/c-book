#include <stdio.h>
#include "book.h"

static unsigned int counter = 0;

void my_swap(size_t *a, size_t *b){
    size_t t = *a;
    *a = *b;
    *b = t;
}

void increment(void) {
    counter++;
}

unsigned int retrieve(void) {
    return counter;
}

void function_1(void) {
    puts("Function 1 invoked.");
}

void function_2(void) {
    puts("Function 2 invoked.");
}

void function_3(void) {
    puts("Function 3 invoked.");
}


int invoke_function(int index) {
    static void (*functions_p[3])() = { &function_1, &function_2, &function_3 };

    if(index < 1 || index > 3)
        return FUNCTION_INVOKE_FAILURE;

    (*functions_p[index-1])();

    return FUNCTION_INVOKE_SUCCESS;
}

void print_binary(int n, int len)
{
    int k = 0;
    char binary[len];

    for (unsigned i = (1 << (len - 1)); i > 0; i = i / 2)
        binary[k++] = (n & i) ? '1' : '0';

    binary[len-1] = '\0';
    printf("The binary representation of %d is \t %s\n", n, binary);
}

int cast_value(signed long value) {
    if ((value < SCHAR_MIN) || (value > SCHAR_MAX)) {
        return ERANGE;
    }
    signed char sc = (signed char) value; // Cast quiets warning
    printf("%c", sc);
    return 0;
}

int increment_by_one(int val) {
    return val + 1;
}

void invoke_func_and_print(int func(int), int value) {
    printf("%d\n", func(value));
}
