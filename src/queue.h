#ifndef CBOOK_QUEUE_H
#define CBOOK_QUEUE_H

#include <stdbool.h>
#include "item.h"

/**
 * Queue.
 *
 * Time Complexity:
 *  Insert/ Delete: O(1)
 *  Peek:
 *
 * Space Complexity:
 *  Space:
 */
struct Queue {
    int front;
    int rear;
    unsigned long size;
    Item items[];
};

typedef struct Queue Queue;

/**
 * Create Queue.
 * @return
 */
Queue *queue_create(size_t size);

/**
 * Add an element to the end of the queue
 * @param item
 * @return
 */
bool queue_enqueue(Queue *queue, Item item);

/**
 * Remove an element from the front of the queue
 * @return
 */
Item *queue_dequeue(Queue *queue);

/**
 * Check if the queue is empty
 * @return
 */
bool queue_is_empty(Queue *queue);

/**
 * Check if the queue is full
 * @return
 */
bool queue_is_full(Queue *queue);

/**
 * Get the value of the front of the queue without removing it
 * @return
 */
Item *queue_peek(Queue *queue);


#endif //CBOOK_QUEUE_H
