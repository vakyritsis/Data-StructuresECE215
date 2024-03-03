#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#include "sort.h"

int main(int argc, char *argv[]) {
    int input, size = 0, choice, bits;
    dlist_t *head = NULL;
    
    while(1) {
        scanf("%d", &input);
        if(input < 0)
            break;
        dlist_insert(&head, input);
        size++;
    }
    printList(head);
    printf("\n");
    
    if(argc < 2) {
        printf("Invalid argument\n");
        return 0;
    } 
    
    choice = atoi(argv[1]);
    
    if(choice < 1 || choice > 6) {
        printf("Invalid argument\n");
        return 0;
    }
    
    if((choice == 5 || choice == 6) && argc != 3) {
        printf("Invalid argument\n");
        return 0;
    }
    else if(argc == 3) {
        bits = atoi(argv[2]);
    
        if(bits != 1 && bits != 2 && bits != 4 && bits != 8 && bits != 16) {
            printf("Invalid argument\n");
            return 0;
        }
    }
    printf("\n");
    switch(choice) {
        case 1: {
            insertionSort(&head);
            break;
        }
        case 2: {
            selectionSort(head, size);
            break;
        }
        case 3: {
            quickSort(head, lastNode(head), 0);
            break;
        }
        case 4: {
            head = mergeSort(head, 0);
            break;
        }
        case 5: {
            //radixSortMSD
            break;
        }
        case 6: {
            //radixSortLSD
            break;
        }
    }
    printf("\n");
    printList(head);
    printf("\n");
    
    freeList(head);
    return 0;
}

