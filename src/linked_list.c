
#include <stdlib.h>
#include <printf.h>
#include "linked_list.h"

void ll_delete(linked_list_t **list){
    if ((*list) == NULL) return;
    node_t **head = &(*list)->head;

    while ((*head) != NULL){
        node_t **tmp = head;
        *head = (*head)->next;
        free(*tmp);
    }
}

node_t *ll_create_node(){
    return malloc(sizeof (node_t));
}

node_t *ll_get_tail(linked_list_t * list){
    if (list == NULL) return NULL;
    node_t *tail = list->head;
    while (tail != NULL){
        if (tail->next == NULL) break;
        tail = tail->next;
    }
    return tail;
}

bool ll_push(linked_list_t *head, int value) {
    node_t *tail = ll_get_tail(head);
    // return early if tail is not available
    if (tail == NULL) return false;
    tail->next = ll_create_node();
    tail->data = value;
    return true;
}

void ll_print(linked_list_t *list) {
    if (list == NULL) return;
    node_t *head = list->head;
    while (head != NULL){
        printf("[data: %d, next: %p]", head->data, &head->next);
        head = head->next;
        if (head) printf(" -> ");
    }
    printf("\n");
}

linked_list_t *ll_create_linked_list() {
    linked_list_t *list = malloc(sizeof (linked_list_t));
    list->head = ll_create_node();
    return list;
}

int ll_pop(linked_list_t **list) { // reference to a pointer, to manipulate the original pointer
    if ((*list) == NULL) return 0;
    node_t **before_tail = &(*list)->head;
    while (before_tail != NULL){
        if ((*before_tail)->next == NULL) break;
        *before_tail = (*before_tail)->next;
    }
    if (before_tail == NULL) return 0;

    int data = (*before_tail)->data;
    free((*before_tail)->next);
    (*before_tail)->next = NULL;
    return data;
}

bool ll_is_empty(linked_list_t *list) {
    return ll_size(list) == 0;
}

int ll_size(linked_list_t *list) {
    if (list == NULL) return 0;
    int size = 0;
    node_t *tmp = list->head;
    while (tmp != NULL){
        size++;
        if (tmp->next == NULL) break;
        tmp = tmp->next;
    }
    return size;
}
