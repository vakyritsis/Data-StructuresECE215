#include <stdio.h>
#include "dlist.h"

void printSubarray(dlist_t *head, int start, int length) {
    dlist_t *curr;
    int i = 0;
    
    for(curr = head; curr->index < start; curr = curr->next);
        
    for(; i < length; curr = curr->next) {
        printf("%d ", curr->data);
        i++;
    }
    printf("\n");
} 

void maxLenZeroSum(dlist_t *head, int size) {
   int maxLen = 0;
   int currSum;
   int startPos = 0, endPos = 0;
   dlist_t *curr1, *curr2;
   
   for(curr1 = head; curr1 != NULL; curr1 = curr1->next) {
        currSum = 0; 
        
        for(curr2 = curr1; curr2 != NULL; curr2 = curr2->next) { 
            currSum += curr2->data; 
            if(currSum == 0) {
                if(maxLen < curr2->index - curr1->index + 1) {
                    endPos = curr2->index;
                    maxLen = curr2->index - curr1->index + 1; 
                }
            }
        } 
    } 
    
    if(maxLen != 0)
        startPos = endPos - maxLen + 1;
    else  
        startPos = 0;
    
    printf("start: %d, stop: %d, size: %d\n", startPos, endPos, maxLen);
    
    printSubarray(head, startPos, maxLen);
}

int main(int argc, char *argv[]) {
    int input, size = 0;
    dlist_t *head = NULL; 
    
    while(1) {
        scanf("%d", &input);
        if(input != 0){
            dlist_insert(&head, input, size);
            size++;
        }
        else
            break;
    }

    maxLenZeroSum(head, size);    
    freeList(head);
    
    return 0;
}
