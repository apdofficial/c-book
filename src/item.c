#include "stdio.h"
#include "stdlib.h"
#include "item.h"


Item *item_create(char *data, int size){
    Item *item = (Item *) malloc(sizeof (Item));
    if (item == NULL){
        printf("Failed to create new Stack.\n");
        return NULL;
    }
    item->size = size;
    item->data = data;
    return item;
}