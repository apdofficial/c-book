#include <stdio.h>
#include "book.h"

void my_swap(size_t *a, size_t *b){
    size_t t = *a;
    *a = *b;
    *b = t;
}

