#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char *argv[]) {
    int input, size = 0, x, level;
    int *pre;
    tree_t *root;

    pre = (int*)malloc(sizeof(int));

    while(1) {
        scanf("%d", &input);
        if(input < 0)
            break;
        else {
            if(size != 0)
                pre = (int*)realloc(pre, sizeof(int) * (size + 1));
            pre[size] = input;
            size++;
        }
    }

    root = BST_preOrder(pre, size);
    printf("Enter integer: ");
    scanf("%d", &x);
    level = getLevel(root, x);
    if(level == 0)
        printf("%d not found\n", x);
    else {
        printf("\nIntegers in level %d are: ", level-1);
        printGivenLevel(root, level);
        printf("\n");
    }
    
    freeTree(root);
    free(pre);
    
    return 0;
} 
