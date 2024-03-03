#include <stdio.h>
#include <stdlib.h> 

typedef struct tree {
    struct tree *right, *left;
    int data;
} tree;


int max(int a, int b){
    return (a>b)?a:b;
}

int min(int a, int b){
    return (a>b)?b:a;
}

tree *newNode(int data) {
    tree *temp = (tree*)malloc(sizeof(tree));
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

tree *BST_preOrderUtil(int pre[], int* preIndex, int low, int high, int size) {
    // Base case
    if (*preIndex >= size || low > high)
        return NULL;
 
    tree *root = newNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;
 
    // If the current subarry has only one element, no need to recur
    if (low == high)
        return root;
 
    // Search for the first element greater than root
    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;
 
    // Use the index of element found in preorder to divide
    // preorder array in two parts. Left subtree and right
    // subtree
    root->left = BST_preOrderUtil(pre, preIndex,  *preIndex, i - 1, size);
    root->right = BST_preOrderUtil(pre, preIndex, i, high, size);
 
    return root;
}
 

tree *BST_preOrder(int pre[], int size) {
    int preIndex = 0;
    return BST_preOrderUtil(pre, &preIndex, 0, size - 1, size);
}

int isRedBlack(tree *root, int *maxroot) {
    if(root == NULL){
        return 1;
    }
    
    int lmax=0,rmax=0;
    if(isRedBlack(root->left, &lmax) && isRedBlack(root->right, &rmax)) {
        
        int minroot=min(lmax, rmax)+1;
        (*maxroot)=max(lmax, rmax)+1;
        
        return ((*maxroot)<=2*minroot);
    }
    return 0;
}

void freeTree(tree *root) {
    while(1){
        if(root == NULL){
            break;
        }
        else if(root->left != NULL){
            freeTree(root->left);
            root->left = NULL;
        }
        else if(root->right != NULL){
            freeTree(root->right);
            root->right = NULL;
        }
        else{ 
            free(root);
            return;
        }
    }

}



 int main(int argc, char *argv[]) {
    int input, size = 0, isRB, maxroot = 0;
    int *preOrder = malloc(sizeof(int));
    tree *root = NULL;
    
    /* store in preOrder the numbers to construct the red black tree */
    while(1) {
        scanf("%d", &input);
        if(input < 0)
            break;
        else {
            preOrder[size] = input;
            size++;
            preOrder = (int*)realloc(preOrder, sizeof(int) * (size + 1));
        }
    }
    root = BST_preOrder(preOrder, size);
    isRB = isRedBlack(root, &maxroot);
    if(isRB == 0)
        printf("RB NOK\n\n");
    else 
        printf("RB OK\n\n");
    free(preOrder);
    freeTree(root);
    return 0;
}
