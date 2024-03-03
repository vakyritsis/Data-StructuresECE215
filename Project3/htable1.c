#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

int find(int *numbers, int n, int size) {
    int i;

    for(i = 0; i < size; i++) {
        if(numbers[i] == n)
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char choice, prev_choice;
    int holder, i, j, k = 0, res, n, f;
    int *matrix;
    int numbers[256];
    
    hashTable htable;

    hash_init(&htable);
    
    for(i = 0; i < 256; i++)
        numbers[i] = 0;

    scanf("%c", &choice); //to get rid of the first -
    do { 
        if(choice != 'p')
            scanf("%c", &choice);
        else
            choice = prev_choice;
        
        switch(choice) {
            case 'i': {
                /*in this piece of code we scan the numbers we want to insert in hash table*/
                i = 0;
                matrix = (int*)malloc(sizeof(int));
                while(1) {
                    n = scanf("%d", &holder);
                    if(n == 0)
                        break;
                    matrix[i] = holder;
                    i++;
                    matrix = (int*)realloc(matrix, sizeof(int) * (i + 1));
                }
                
                for(j = 0; j < i; j++) {
                    f = find(numbers, matrix[j], htable.size);
                    if(f == 0) {
            
                        numbers[k] = matrix[j];
                        if(htable.rehash == 1 && htable.loadFactor >= 0.5) 
                            rehashing(&htable, htable.size * 2);

                        res = hash_add(&htable, &numbers[k]);
                        if(res == 1) {
                            printf("\nINSERTED %d\n", numbers[k]);
                            k++;
                        }
                        else if(res == 0)
                            printf("\nNOT INSERTED %d\n", numbers[k]);
                        }
                    else
                        printf("\nNOT INSERTED %d\n", holder);
                }
                free(matrix);
                break;
                
            }
            case 'd': { 
                i = 0;
                matrix = (int*)malloc(sizeof(int));
                while(1) {
                    n = scanf("%d", &holder);
                    if(n == 0)
                        break;
                    matrix[i] = holder;
                    i++;
                    matrix = (int*)realloc(matrix, sizeof(int) * (i + 1));
                    
                }
                for(j = 0; j < i; j++) {
                    res = hash_delete(&htable, &matrix[j]);
                    if(res == 1)
                        printf("\nDELETED %d\n", matrix[j]);
                    else if(res == 0)
                        printf("\nNOT DELETED %d\n", matrix[j]);
                    if(htable.rehash == 1 && htable.loadFactor <= 0.125 && htable.size > 2)
                        rehashing(&htable, htable.size / 2);
                }
                free(matrix);
                break;
            }
            case 'f': { 
                i = 0;
                matrix = (int*)malloc(sizeof(int));
                while(1) {
                    n = scanf("%d", &holder);
                    if(n == 0)
                        break;
                    matrix[i] = holder;
                    i++;
                    matrix = (int*)realloc(matrix, sizeof(int) * (i + 1));
                }
                for(j = 0; j < i; j++) {
                    res = hash_find(&htable, &matrix[j]);
                    if(res == 1)
                        printf("\nFOUND %d\n", matrix[j]);
                    else if(res == 0)
                        printf("\nNOT FOUND %d\n", matrix[j]);
                }
                free(matrix);
                break;
            }
            case 'p': {
                print(htable);
                
                break;
            }
            case 'r': {
                htable.rehash = !htable.rehash;
                break;
            }
        }
        if(choice == 'i' || choice == 'd' || choice == 'f')
            prev_choice = choice;
        
    }
    while(choice != 'q');
    
    free(htable.table);
    return 0;
}
 
