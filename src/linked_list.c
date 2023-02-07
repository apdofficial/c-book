
#include <stdlib.h>
#include <printf.h>
#include "linked_list.h"
#include <stdio.h>


void ll_delete(LinkedList *list){
    if (list == NULL) return;
    Node *head = list->head;
    while (head != NULL){
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

Node *ll_create_node(char *data, int size){
    Node *node = (Node *) malloc( sizeof (Node));
    if (node == NULL){
        printf("Failed to create new Node.\n");
        return NULL;
    }

    node->next = NULL;
    node->data = data;
    node->size = size;

    return node;
}

bool ll_push(LinkedList *list, char *data, int size) {
    if (list == NULL) return false;
    Node *before_tail = list->head;
    while (before_tail != NULL){
        if (before_tail->next == NULL) break;
        before_tail = before_tail->next;
    }

    if (!ll_is_empty(list) && before_tail == NULL) { // something went wrong, list is not empty but we fail to get node
        return false;
    }

    Node *node = ll_create_node(data, size);
    if (node == NULL) {
        return false;
    }

    if (ll_is_empty(list)) {
        list->head = node;
    } else{
        before_tail->next = node;
    }

    return true;
}

void ll_print(LinkedList *list) {
    if (list == NULL) return;
    Node *head = list->head;
    if (head == NULL){
        printf("The linked list is empty.\n");
        return;
    }
    while (head != NULL){
        printf("[size: %d, next: %p]", head->size, &head->next);
        head = head->next;
        if (head) printf(" -> ");
    }
    printf("\n");
}

LinkedList *ll_create_linked_list() {
    LinkedList *list = malloc(sizeof (LinkedList));
    list->head = NULL;
    return list;
}

Node *ll_pop(LinkedList *list) {
    if (list == NULL) return NULL;
    if (ll_is_empty(list)) return NULL;

    Node *before_tail = list->head;
    while (before_tail != NULL && before_tail->next != NULL){
        if (before_tail->next->next == NULL) break;
        before_tail = before_tail->next;
    }

    if (ll_num_items(list) == 1) { // before_tail is the head
        Node *node = before_tail;
        list->head = NULL;
        return node;
    } else{ // grab next from the before tail
        Node *node = before_tail->next;
        before_tail->next = NULL;
        return node;
    }
}

bool ll_is_empty(LinkedList *list) {
    return ll_num_items(list) == 0;
}

int ll_num_items(LinkedList *list) {
    if (list == NULL) return 0;
    int size = 0;
    Node *tmp = list->head;
    while (tmp != NULL){
        size++;
        if (tmp->next == NULL) break;
        tmp = tmp->next;
    }
    return size;
}
