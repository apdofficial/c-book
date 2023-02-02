#include <limits.h>
#include "book.h"
#include <stddef.h>
#include <stdalign.h>
#include <assert.h>

/**
 * Chapter 4
 * Expressions and Operators
 */
int main() {
    // Passing one function to another function
    // in math we denote it as f o g (f after g), it is call a function composition
    invoke_func_and_print(increment_by_one, 10); // call g with function-pointer argument

    /** Increment and Decrement Operators **/
    int i = 5;
    int e;    // result of the expression
    e = i++;  // postfix increment, unary operation (because it takes  single operand)
    printf("e=%d, i=%d\n", e, i);
    e = i--;  // postfix decrement
    printf("e=%d, i=%d\n", e, i);
    e = ++i;  // prefix increment
    printf("e=%d, i=%d\n", e, i);
    e = --i;  // prefix decrement
    printf("e=%d, i=%d\n", e, i);

    /** Operator Precedence and Associativity **/

    /**
     * Operator Precedence = order of operations
     * Associativity = how operators of the same precedence are group
     * when no explicit parentheses are used.
     * Left associative/ Right associative
     * e.g, if p is a pointer, then *p++ is equivalent to *(p++), and ++*p is equivalent to ++(*p)
     * **/

    char abc[] = "abc";
    char xyz[] = "xyz";
    char *p = abc;

    printf("++*p=%c\n", ++*p);

    p = xyz;
    printf("*p++=%c\n", *p++);

    /** Oder of evaluation **/
    int max_value = max(f(), g()); // compiler dos not guarantee order of evaluation f and g

    printf("max_value=%d\n", max_value);

    size_t int_bits = CHAR_BIT * sizeof(int);

    printf("int_bits=%zu\n", int_bits);

    //  The expression !E is equivalent to (0 == E)

    unsigned char uc = UCHAR_MAX; // 0xFF
    printf("uc=%X\n", uc);
    int uc_neg = ~uc; // 0xFFFFFF00,  unary complement
    printf("~uc=%X\n", uc_neg);

    static_assert(alignof(max_align_t) == 8, "Alignment of max_align_t");
    assert(alignof(max_align_t) == 8); // runtime assertion
    printf("Alignment of max_align_t = %zu\n", alignof(max_align_t));

    int arr[100];
    int *arrp1 = &arr[40];
    int *arrp2 = arrp1 + 20;      // arrp2 points to arr[60]
    printf("arrp2-arrp1=%td\n", arrp2-arrp1); // prints 20

    printf("m={");
    for (int j = 0; j < get_m_len(); ++j) {
        int *m_ptr = get_m_ptr();
        printf("%d", m_ptr[j]);
        if (j < get_m_len() - 1) printf(",");
    }
    printf("}\n");

    int sum = sum_m_elems();
    printf("sum=%d\n", sum);


    printf("arrp2-arrp1=%td\n", arrp2-arrp1); // prints 20

}
