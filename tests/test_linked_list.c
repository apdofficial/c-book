#include "stdio.h"
#include "stdlib.h"
#include "test_assert.h"
#include "../src/linked_list.h"

int test_ll(){
    char data1[2] = {0x41, 0x42}; // { A, B }
    char data2[3] = {0x44, 0x45, 0x46}; // { D, E, F }

    printf("ll_create_node\n");
    LinkedList *list = ll_create_linked_list();
    ll_print(list);

    test_assert(ll_num_items(list) == 0);

    printf("ll_push\n");
    test_assert(ll_push(list, data1, 2));
    ll_print(list);

    test_assert(ll_num_items(list) == 1);

    test_assert(ll_push(list, data2, 3));
    ll_print(list);

    test_assert(ll_num_items(list) == 2);

    printf("ll_pop\n");

    Node *item2 = ll_pop(list);
    test_assert(item2 != NULL);
    test_assert(ll_num_items(list) == 1);

    for (int i = 0; i < item2->size; ++i) {
        test_assert(item2->data[i] == data2[i]);
    }

    Node *item1 = ll_pop(list);
    for (int i = 0; i < item1->size; ++i) {
        test_assert(item1->data[i] == data1[i]);
    }

    ll_print(list);

    test_assert(ll_num_items(list) == 0);

    printf("ll_delete\n");
    ll_delete(list);
    ll_print(list);

    test_assert(ll_num_items(list) == 0);

    test_assert(ll_is_empty(list));
    return EXIT_SUCCESS;
}

int main(){
    int res = EXIT_SUCCESS;

    printf("Testing test_ll.\n");
    if (test_ll()) return 1;

    return res;
}