#ifndef BOOK_H
#define BOOK_H

#include<stdio.h>

#define	FUNCTION_INVOKE_FAILURE	1
#define	FUNCTION_INVOKE_SUCCESS	0

void my_swap(size_t *a, size_t *b);

void increment(void);

unsigned int retrieve(void);

int invoke_function(int index);

#endif