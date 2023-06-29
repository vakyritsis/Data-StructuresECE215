#ifndef __DLIST_H_
#define __DLIST_H_


typedef struct dlist {
    struct dlist* next;
    struct dlist* prev;
    int data;
} dlist_t;

void dlist_insert(dlist_t** head_ref, int new_data);

void printList(dlist_t *head);

void freeList(dlist_t *head);

void printSubList(dlist_t *head, int last);

#endif 
