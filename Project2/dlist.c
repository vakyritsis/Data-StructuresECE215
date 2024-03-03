#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
// doubly linked list functions

void dlist_insert(dlist_t** head_ref, int new_data) { //append
    dlist_t* new_node = (dlist_t*)malloc(sizeof(dlist_t)); 
  
    dlist_t* last = *head_ref; 
  
    new_node->data = new_data; 
  
    new_node->next = NULL; 
      
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
  
    while (last->next != NULL) 
        last = last->next; 
  
    last->next = new_node; 
  
    new_node->prev = last; 
  
    return; 
} 

void printList(dlist_t *head) {
    dlist_t *temp = head;
 
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void freeList(dlist_t *head) {
    dlist_t *curr, *next;
    
    for(curr = head; curr != NULL;) {
        next = curr->next;
        free(curr);
        curr = next;
    }
} 

void printSubList(dlist_t *head, int last) { // prints a doublt linked list until last
    dlist_t *temp = head;
    while(temp) {
        printf("%d ", temp->data);
        if(temp->next->data == last) {
            printf("%d ", temp->next->data);
            break;
        }
        temp = temp->next;
      
    }
}
