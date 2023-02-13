//
// Created by Andrej Pistek on 13/02/2023.
//

#ifndef CBOOK_QUEUE_H
#define CBOOK_QUEUE_H

#include <stdbool.h>
#include "item.h"

/**
 * Queue.
 *
 * Time Complexity:
 *  Insert/ Delete: O(1)
 *  Peek: O(n)
 *
 * Space Complexity:
 *  Space: O(n)
 */
struct Queue {
    unsigned long size;
    Item *items;
    int top;
};

typedef struct Queue Queue;

/**
 * Add an element to the end of the queue
 * @param item
 * @return
 */
bool enqueue(Item *item);

/**
 * Remove an element from the front of the queue
 * @return
 */
Item *dequeue();

/**
 * Check if the queue is empty
 * @return
 */
bool is_empty();

/**
 * Check if the queue is full
 * @return
 */
bool is_full();

/**
 * Get the value of the front of the queue without removing it
 * @return
 */
Item *peek();


#endif //CBOOK_QUEUE_H
