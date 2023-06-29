#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#include "sort.h"

/* 1)insertion sort*/

void insertionSort(dlist_t **head) {
    dlist_t *temp, *curr;
    int key, step = 1;

    for(temp = (*head)->next; temp != NULL; temp = temp->next) {
        key = temp->data;
        curr = temp->prev;
            
        while(curr != NULL && curr->data > key) {
            curr->next->data = curr->data;
            if(curr->prev == NULL)
                break;
            curr = curr->prev;
        }
        if(curr->prev == NULL && curr->data > key)
            curr->data = key;//correct
        else 
            curr->next->data = key;
        printf(" [%d]: ", step++);
        printList(*head);
        printf("\n");
    }
}

/* 2)selection sort */

void selectionSort(dlist_t *head, int size) {
    dlist_t *temp = head;
    int step = 1;
    while(temp) {
        dlist_t *min = temp;
        dlist_t *r = temp->next;

        
        while(r) {
            if(min->data > r->data)
                min = r;
            r = r->next;
        }
        int x = temp->data; 
        temp->data = min->data; 
        min->data = x; 
        temp = temp->next;
        if(step > size - 1)
            break;
        printf(" [%d]: ", step++); 
        printList(head);
        printf("\n");
    }
}

/* 3)quick sort*/

void swap ( int* a, int* b ) { 
    int t = *a; *a = *b; *b = t; 
} 
  

dlist_t *lastNode(dlist_t *head) { 
    while (head && head->next) 
        head = head->next; 
    return head; 
} 

dlist_t *partition(dlist_t *head, dlist_t *last) { 
    int o = last->data; // o is equal to the last element of the list
  
    dlist_t *i = head; // pointer i is equal to the first element
    dlist_t *j = last->prev; //pointer j is equal to the previous of last element
    int var = 0; //variable to chech if i and j met
    while(1) {
        while(i != NULL && i->data < o) {
            i = i->next;
            if(i == j)
                var = 1;
        }

        while(j != NULL && o < j->data) {
            if(j == head)
                break;
            j = j->prev;
            if(j == i)
                var = 1;
        }
        if(var == 1) // main statement to break the loop
            break;

        /*contition if the list has only 2 elements*/
        if(last->prev == head) {
            if(head->data > last->data){
                swap(&(head->data), &(last->data));
                return last;
            }
        }
        swap(&(i->data), &(j->data)); // swap i and j
    }
    swap(&(i->data), &(last->data)); 
    
    return i; 
} 
  
void quickSort(dlist_t *head, dlist_t *last, int level) { 
    int i;
    if (last != NULL && head != last && head != last->next) { 
        for(i = 0; i < level; i++)
            printf("== ");
        printf("[%d >] ", level);
        printSubList(head, last->data);
        printf("\n");
        
        dlist_t *p = partition(head, last); 

        if(last->prev != head) {
            for(i = 0; i < level; i++)
                printf("== ");
            printf("[%d -] ", level);
            printSubList(head, last->data);
            printf("\n");
            
            
        }
        level++;
        quickSort(head, p->prev, level); 
        quickSort(p->next, last, level); 

        level--;
        for(i = 0; i < level; i++)
            printf("== ");
        printf("[%d <] ", level);
        printSubList(head, last->data);
        printf("\n");
        
    } 
} 

/* 4)merge sort */

dlist_t *merge(dlist_t *first, dlist_t *second) { 
    if (!first) 
        return second; 
      
    if (!second) 
        return first; 
      
    if (first->data < second->data) { 
        first->next = merge(first->next,second); 
        first->next->prev = first; 
        first->prev = NULL; 
        return first; 
    } 
    else { 
        second->next = merge(first,second->next); 
        second->next->prev = second; 
        second->prev = NULL;
        return second; 
    } 
} 

dlist_t *split(dlist_t *head) { 
    dlist_t *fast = head->next, *slow = head; 

    while (fast->next && fast->next->next) { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 

    dlist_t *temp = slow->next; 
    slow->next = NULL; 

    return temp; 
}

dlist_t *mergeSort(dlist_t *head, int level) { 
    dlist_t *ret;
    int i;
    
    
    if (!head || !head->next) 
        return head;
    
    for(i = 0; i < level; i++)
        printf("== ");
    printf("[%d >] ", level);
    printList(head);
    printf("\n");
    

    dlist_t *second = split(head); 

    level++;
    //in case of one element of list, we consider it as sorted sublist
    if(head->next == NULL && second->next != NULL) {
        for(i = 0; i < level; i++)
            printf("== "); 
        printf("[%d >] ", level);    
        printList(head);
        printf("\n");

        for(i = 0; i < level; i++)
            printf("== "); 
        printf("[%d <] ", level);    
        printList(head);
        printf("\n");
    }
    
    head = mergeSort(head, level);
    
    second = mergeSort(second, level);

    ret = merge(head, second);

    level--;

    for(i = 0; i < level; i++)
        printf("== ");
    printf("[%d <] ", level);
    printList(ret);
    printf("\n");

    return ret;
} 
