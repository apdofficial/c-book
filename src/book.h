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

void *book_memcopy(void *dest, void *src, size_t n);

#endif