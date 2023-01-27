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


