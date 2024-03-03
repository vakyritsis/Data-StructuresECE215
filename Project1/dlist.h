#ifndef __DLIST_H_
#define __DLIST_H_

/* Structs*/

typedef struct dlist {
    struct dlist* next;
    struct dlist* prev;
    int data;
    int index;
} dlist_t;

/* Functions*/

void dlist_insert(dlist_t **head, int n, int i);

void freeList(dlist_t *head);

#endif
