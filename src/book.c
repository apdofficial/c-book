#include <stdio.h>
#include "book.h"

#include <errno.h>
#include <limits.h>


// static storage
static int glob = 0;
static unsigned int counter = 0;
const static int mLen = 2;
static int m[mLen] = {1, 2};


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

void print_binary(int n, int len){
    printf("The binary representation of %d is \t ", n);

    unsigned i;
    for (i = 1 << --len; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");

    printf("\n");
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

int f(void) {
    return glob + 10;
}

int g(void) {
    glob = 42;
    return glob;
}

int max(int a, int b){
    return a > b ? a: b;
}

bool is_odd(int n) {
    // n % 2 == 1 is faulty because reminder sign is determined by the dividend sign, e.g, -n % 2 could be -1 not 1
    return n % 2 != 0;
}

bool isN(const int* ptr, int n){
  return ptr && *ptr == n; // don't dereference a null pointer
}

int get_m_len(){
    return mLen;
}

int* get_m_ptr(void){
    return m;
}

int sum_m_elems(void) {
    int *pi;
    int j = 0;
    for (pi = &m[0]; pi < &m[2]; ++pi) j += *pi;
    return j;
}
