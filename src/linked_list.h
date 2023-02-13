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

/**
 * Delete the entire linked list.
 * @param list
 */
void ll_delete(LinkedList *list);

/**
 * Create new linked list.
 * @return
 */
LinkedList *ll_create_linked_list();

/**
 * Allocate memory for new linked list node.
 * @param data
 * @param size
 * @return
 */
Node *ll_create_node(char *data, int size);

/**
 * Print items inside of the linked lsit.
 * @param list
 */
void ll_print(LinkedList *list);

/**
 * Add item to the end of the linked list.
 * @param head
 * @param data
 * @param size
 * @return
 */
bool ll_push(LinkedList *head, char *data, int size);

/**
 * Remove and get item from the end of the list.
 * @param list
 * @return
 */
Node *ll_pop(LinkedList *list);

/**
 * Get number of item in the given list.
 * @param list
 * @return
 */
int ll_num_items(LinkedList *list);

/**
 * Check if the linked list is empty.
 * @param list
 * @return
 */
bool ll_is_empty(LinkedList *list);

#endif //CBOOK_LINKED_LIST_H
