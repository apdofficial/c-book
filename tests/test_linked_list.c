#include "stdio.h"
#include "stdlib.h"
#include "test_assert.h"
#include "../src/linked_list.h"

int test_ll(){
    printf("ll_create_node\n");
    linked_list_t *list = ll_create_linked_list();
    ll_print(list);

    test_assert(ll_size(list) == 1);

    printf("ll_push\n");
    ll_push(list, 1);
    ll_print(list);

    test_assert(ll_size(list) == 2);

    ll_push(list, 2);
    ll_print(list);

    printf("ll_pop\n");
    ll_pop(&list);
    ll_pop(&list);
    ll_print(list);

    test_assert(ll_size(list) == 1);

    printf("ll_delete\n");
    ll_delete(&list);
    ll_print(list);

    test_assert(ll_size(list) == 0);

    test_assert(ll_is_empty(list));
    return EXIT_SUCCESS;
}

int main(){
    int res = EXIT_SUCCESS;

    printf("Testing test_ll.\n");
    if (test_ll()) return 1;

    return res;
}