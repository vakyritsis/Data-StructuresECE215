#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char *argv[]) {
    int input, size = 0;
    int *levelOrder = NULL;
    tree_t *root = NULL;
    int res;
    
    levelOrder = (int*)malloc(sizeof(int));
    
    while(1) {
        scanf("%d", &input);
        if(input < 0)
            break;
        else {
            levelOrder = (int*)realloc(levelOrder, sizeof(int) * (size + 1));
            levelOrder[size] = input;
            size++;
        }
    }
    
    root = completeTreeLevelOrder(levelOrder, root, 0, size); // 0 for the first call of the recursion function
    
    res = isBST(root); 
    if(res == 1)
        printf("Binary Search Tree\n");
    else
        printf("Binary Tree\n");
    
    freeTree(root);
    free(levelOrder);
    
    return 0;
}
