#include "book.h"
#include "stdlib.h"

int main(void){
    size_t a = 0;
    size_t b = 1;

    printf("Before the swap: a=%zu, b=%zu\n", a, b);
    my_swap(&a, &b);
    printf("After the swap: a=%zu, b=%zu\n", a, b);

    printf("The counter initial value is %d\n", retrieve());
    for (int i = 0; i < 5; ++i) {
        increment();
    }
    printf("The counter incremented value is %d\n", retrieve());

    return EXIT_SUCCESS;
}