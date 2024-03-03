#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"


void dlist_insert(dlist_t **head, int n, int i) {
    dlist_t *new, *last;
    
    last = *head;
    new = (dlist_t*)malloc(sizeof(dlist_t));
    if(new == NULL)
        exit(-1);
    
    new->data = n;
    new->index = i;
    new->next = NULL;
    
    if(*head == NULL) {
        new->prev = NULL;
        *head = new;
        return;
    }
    
    while(last->next != NULL) {
        last = last->next;
    }
    
    last->next = new;
    new->prev = last;
}

void freeList(dlist_t *head) {
    dlist_t *curr, *next;
    
    for(curr = head; curr != NULL;) {
        next = curr->next;
        free(curr);
        curr = next;
    }
}
