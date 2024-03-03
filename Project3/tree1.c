#include <stdio.h>
#include <stdlib.h>
#include "hbtree.h"

int main(int argc, char *argv[]) {
    char choice, prev_choice;
    int holder, i, j, n;
    int *matrix;
    hbtree *root = NULL;
    hbtree *curr;
    
    scanf("%c", &choice);

    do {
        if(choice != 'p')
            scanf("%c", &choice);
        else 
            choice = prev_choice;
        
        switch(choice) {
            case 'i': {
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
                        curr = search(root, matrix[j]);
                        if(curr != NULL && curr->key == matrix[j])
                            printf("\nNOT INSERTED %d\n", matrix[j]);
                        else {
                        root = insert_tree(root, matrix[j]);
                        
                            printf("\nINSERTED %d\n", matrix[j]);
                        }
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

                    for(j = 0; j < i; j++) {
                        curr = search(root, matrix[j]);
                        if(curr != NULL && curr->key == matrix[j]) {
                        root = delete_tree(root, matrix[j]);
                        root = check(root);
                        root = check(root);
                        printf("\nDELETED %d\n", matrix[j]);
                        }
                        else    
                            printf("\nNOT DELETED %d\n", matrix[j]);
                    }
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
                        
                        curr = search(root, matrix[j]);
                        if(curr != NULL && curr->key == matrix[j])
                            printf("\nFOUND %d\n", matrix[j]);
                        else if(curr == NULL)  
                            printf("\nNOT FOUND %d\n", matrix[j]);
                    }
                free(matrix);
                break;
            }
            case 'p': {
                printf("\n");
                printPreOrder(root);
                printf("\n");
                break;
            }
            case 'q': {
                break;
            }
        }
        if(choice == 'i' || choice == 'd' || choice == 'f')
            prev_choice = choice;
        
    }
    while(choice != 'q');
    freeTree(root);
    return 0;
} 
