#ifndef CBOOK_LINKED_LIST_H
#define CBOOK_LINKED_LIST_H

#include <stdbool.h>

/**
 * Linked list.
 *
 * Time Complexity:
 *  Insert/ Delete:
 *               Start:  O(1)
 *               Middle: Peek time + O(1)
 *               End:    O(1), known end element/ O(n), unknown end element
 *  Peek: O(n)
 *
 * Space Complexity:
 *  Space: O(n)
 */

struct Node {
  struct Node *next;
  int size;
  char *data;
};

typedef struct Node Node;

struct LinkedList {
  struct Node *head;
};

typedef struct LinkedList LinkedList;


void ll_delete(LinkedList *list);

LinkedList *ll_create_linked_list();

Node *ll_create_node(char *data, int size);

void ll_print(LinkedList *list);

bool ll_push(LinkedList *head, char *data, int size);

Node *ll_pop(LinkedList *list);

int ll_num_items(LinkedList *list);

bool ll_is_empty(LinkedList *list);

#endif //CBOOK_LINKED_LIST_H
