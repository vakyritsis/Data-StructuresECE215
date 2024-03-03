#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char *argv[]) {
    int input, size = 0;
    int *postOrder = NULL;
    tree_t *root = NULL;
    
    postOrder = (int*)malloc(sizeof(int));
    
    while(1) {
        scanf("%d", &input);
        if(input < 0)
            break;
        else {
            if(size != 0)
                postOrder = (int*)realloc(postOrder, sizeof(int) * (size + 1));
            postOrder[size] = input;
            size++;
        }
    }
    
    root = constructTree(postOrder, size);
    
    printLevelOrder(root);
    freeTree(root);
    free(postOrder);
    
    return 0;
}
