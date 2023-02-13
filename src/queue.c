#include <stdlib.h>
#include <printf.h>
#include "queue.h"

Queue *queue_create(size_t size) {
    Queue *queue = (Queue *) malloc(sizeof(Queue) * size);
    if (queue == NULL){
        printf("Failed to create new Queue.\n");
        return NULL;
    }
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    return queue;
}


bool queue_enqueue(Queue *queue, Item item) {
    if (queue == NULL) return false;
    if (queue_is_full(queue)) return false;

    if (queue->size == 0){
        queue->items[0] = item;
        queue->size = 1;
        queue->rear = 1;
        queue->front = 1;
    } else {
        queue->front++;
        queue->size++;
        queue->items[queue->front-1] = item;
    }

    return true;
}

Item *queue_dequeue(Queue *queue) {
    if (queue == NULL) return false;
    if (queue_is_empty(queue)) return false;

    if (queue->size == 1){
        queue->items[0] = item;
        queue->size = 1;
        queue->rear = 1;
        queue->front = 1;
    } else {
        queue->front++;
        queue->size++;
        queue->items[queue->front-1] = item;
    }

    printf("%lu", queue->size);
    return NULL;
}

bool queue_is_empty(Queue *queue) {
    return queue->size == 0;
}

bool queue_is_full(Queue *queue) {
    return (unsigned long)queue->front >= queue->size;
}

Item *queue_peek(Queue *queue) {
    printf("%lu", queue->size);
    return NULL;
}


