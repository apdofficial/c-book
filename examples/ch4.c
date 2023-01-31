#include <limits.h>
#include "book.h"
#include "stdlib.h"
#include <stdint.h>

int main() {
    // Passing one function to another function
    invoke_func_and_print(increment_by_one, 10); // call g with function-pointer argument
}
