//
// Created by Andrej Pistek on 13/02/2023.
//

#ifndef CBOOK_ITEM_H
#define CBOOK_ITEM_H


struct Item {
    int size;
    char *data;
};

typedef struct Item Item;

/**
 * Allocate heap memory for new item.
 * @param data
 * @param size
 * @return
 */
Item *item_create(char *data, int size);

#endif //CBOOK_ITEM_H
