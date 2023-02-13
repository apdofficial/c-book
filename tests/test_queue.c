#include "stdio.h"
#include "stdlib.h"
#include "test_assert.h"
#include "queue.h"

int test_queue() {
    char data1[2] = {0x41, 0x42}; // { A, B }
    char data2[3] = {0x44, 0x45, 0x46}; // { D, E, F }
    Item *item1 = item_create(data1, 2);
    Item *item2 = item_create(data2, 3);

    Queue *queue = queue_create(5);

    queue_enqueue(queue, *item1);
    queue_enqueue(queue, *item2);

    test_assert(queue_is_empty(queue) == false);

    return EXIT_SUCCESS;
}

int main(){
    printf("Testing test_queue.\n");
    if (test_queue()) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
