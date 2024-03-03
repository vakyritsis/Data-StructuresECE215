#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char *argv[]) {
    tree_t *root = NULL;
    int input, size = 0;
    int *arr;
    char choice[2];
    
    arr = (int*)malloc(sizeof(int));
    
    while(1) {
        scanf("%d", &input);
        if(input < 0)
            break;
        else {
            if(size != 0)
                arr = (int*)realloc(arr, sizeof(int) * (size + 1));
            arr[size] = input;
            size++;
        }
    }
    root = BST_preOrder(arr, size);
    
    scanf("%s", choice);
    switch(choice[1]) {
        case 'f' : {
            printf("\n");
            printLeafNodes(root);
            printf("\n");
            printf("\n");
            break;
        }
        case 'h' : {
            printPreorder(root);
            printf("\n");
            break;
        }
        case 'a' : {
            int matrix[10];
            int i = 0;
            if(isBalanced(root, matrix, &i))
                printf("AVL OK\n");
            else {
                printf("AVL NOT OK in node ");
                printf("%d\n", matrix[0]);
            }
            break;
        }
        
    }
    free(arr);
    freeTree(root);
    return 0;
}
