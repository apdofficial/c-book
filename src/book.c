#include <stdio.h>
#include "book.h"
#include <limits.h>

#define mLen 6


// static storage
static int glob = 0;
static unsigned int counter = 0;
static int m[mLen] = {1, 2};


void my_swap(size_t *a, size_t *b) {
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
    static void (*functions_p[3])() = {&function_1, &function_2, &function_3};

    if (index < 1 || index > 3)
        return FUNCTION_INVOKE_FAILURE;

    (*functions_p[index - 1])();

    return FUNCTION_INVOKE_SUCCESS;
}

void print_binary(int n, int len) {
    printf("The binary representation of %d is \t ", n);

    unsigned i;
    for (i = 1 << --len; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");

    printf("\n");
}

int can_cast_to_char(signed long value) {
    if ((value < SCHAR_MIN) || (value > SCHAR_MAX)) {
        return 0;
    }
    return 1;
}

int increment_by_one(int val) {
    return val + 1;
}

int invoke_func_and_print(int func(int), int value) {
    int res = func(value);
    printf("%d\n", res);
    return res;
}

int f(void) {
    return glob + 10;
}

int g(void) {
    glob = 42;
    return glob;
}

int max(int a, int b) {
    return a > b ? a : b;
}

bool is_odd(int n) {
    // n % 2 == 1 is faulty because reminder sign is determined by the dividend sign, e.g, -n % 2 could be -1 not 1
    return n % 2 != 0;
}

bool isN(const int *ptr, int n) {
    return ptr && *ptr == n; // don't dereference a null pointer
}

int get_m_len() {
    return mLen;
}

int *get_m_ptr(void) {
    return m;
}

int sum_m_elems(void) {
    int *pi;
    int j = 0;
    for (pi = &m[0]; pi < &m[2]; ++pi) j += *pi;
    return j;
}

void *book_memset(void *dest, int val, size_t n) {
    unsigned char *ptr = (unsigned char *) dest; // cast to pointer to bytes
    while (n-- > 0)
        *ptr++ = (unsigned char) val;
    return dest;
}


void *book_memset2(void *dest, int val, size_t n) {
    unsigned char *ptr = (unsigned char *) dest; // cast to pointer to bytes
    for (size_t i = 0; i < n; ++i) {
        ptr[i] = (unsigned char )val;
    }
    return dest;
}

void *book_memcopy(void *dest, void *src, size_t n) {
    // cast to pointer to bytes
    unsigned char *dest_ptr = (unsigned char *) dest;
    unsigned char *src_ptr = (unsigned char *) src;

    while (n-- > 0)
        *dest_ptr++ = (unsigned char) *src_ptr++;

    return dest;
}


int find_element(size_t len, const int arr[len], int key) {
    size_t pos = (size_t) -1;
    // traverse arr and search for key
    for (size_t i = 0; i < len; ++i) {
        if (arr[i] == key) {
            pos = i;
            break; // terminate loop
        }
    }
    return pos;
}

/**
 * Suppose we work with 8-bit two's complement,
 * then integer overflow occurs if INT32_MIN is given as argument.
 * The reason is that in 8-bit two's complement INT32_MIN == INT32_MAX+1.
 *  * if (a < 0) {
 *     return -a;
 * }
 *
 * Example for 1 byte integer value:
 *  INT8_MIN == -128 (10000000)
 *  INT8_MAX ==  127 (01111111)
 * to fix it return long int instead to fir the value
 */
long int absolute_value(int a) {
    if (a < 0) {
        return -(long int)a;
    }
    return a;
}