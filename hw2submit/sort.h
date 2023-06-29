#ifndef __SORT_H_
#define __SORT_H_

void insertionSort(dlist_t **head);

void selectionSort(dlist_t *head, int size);

//funcs for quick sort//

void swap ( int* a, int* b );

dlist_t *lastNode(dlist_t *head);

dlist_t *partition(dlist_t *head, dlist_t *last);

void quickSort(dlist_t *head, dlist_t *last, int level);

//functs for merge sort

dlist_t *merge(dlist_t *first, dlist_t *second);

dlist_t *split(dlist_t *head) ;

dlist_t *mergeSort(dlist_t *head, int level);


#endif
