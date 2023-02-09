#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define	FUNCTION_INVOKE_FAILURE	1
#define	FUNCTION_INVOKE_SUCCESS	0

#define Abs(i) ((i) < 0 ? -(i) : (i))
#define AbsM(i, flag) ((i) >= 0 ? (i) : ((i)==(flag) ? (flag) : -(i))) //avoid signed integer overflows

/**
 * Starting from C99, last member of struct can have incomplete array type.
 * We cna  allocate size of the array when allocation dynamic memotry for the struct.
 * See malloc_widget function.
 */
typedef struct {
    size_t num;
    int data[];
} widget;

widget *malloc_widget(size_t array_size);


/**
 * Safe conversion
 * Check the rage of the type into which you are going to cast the given data type.
 */
int can_cast_to_char(signed long value);

void my_swap(size_t *a, size_t *b);

void increment(void);

unsigned int retrieve(void);

int invoke_function(int index);

void print_binary(int n, int len);

int increment_by_one(int val);

// void invoke_func_and_print(int (*func)(void)) is an equivalent definition
int invoke_func_and_print(int func(int), int value);

int f(void);

int g(void);

int max(int a, int b);

bool is_odd(int n);

bool isN(const int* ptr, int n);

int sum_m_elems(void);

int get_m_len(void);

int* get_m_ptr(void);

void *book_memset(void *dest, int val, size_t n);

void *book_memset2(void *dest, int val, size_t n);

void *book_memcopy(void *dest, void *src, size_t n);

int find_element(size_t len, const int arr[len], int key);

long int absolute_value(int a);

int matrix_sum(size_t rows, size_t cols, int matrix[rows][cols]);

#endif