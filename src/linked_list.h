#ifndef CBOOK_LINKED_LIST_H
#define CBOOK_LINKED_LIST_H

#include <stdbool.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct linked_list {
  struct node *head;
} linked_list_t;

void ll_delete(linked_list_t **list);

linked_list_t *ll_create_linked_list();

node_t *ll_create_node();

void ll_print(linked_list_t *list);

node_t *ll_get_tail(linked_list_t * list);

bool ll_push(linked_list_t *list, int value);

int ll_pop(linked_list_t **list);

int ll_size(linked_list_t *list);

bool ll_is_empty(linked_list_t *list);

#endif //CBOOK_LINKED_LIST_H
