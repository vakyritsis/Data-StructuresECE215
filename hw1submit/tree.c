#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "tree.h"

tree_t *newNode(int data) { 
    tree_t* temp = (tree_t *)malloc(sizeof(tree_t)); 
    
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
   
tree_t *constructTreeUtil(int postOrder[], int *postIndex, int key, int min, int max, int size) { 
    if (*postIndex < 0) {
        return NULL; 
    }
    
    tree_t *new = NULL; 
  
    if (key > min && key < max) { 
        new = newNode(key); 
        *postIndex = *postIndex - 1;  
  
        if (*postIndex >= 0) { 
          new->right = constructTreeUtil(postOrder, postIndex, postOrder[*postIndex], key, max, size); 
          new->left = constructTreeUtil(postOrder, postIndex, postOrder[*postIndex],  min, key, size); 
        } 
    } 
    return new; 
} 
  
tree_t *constructTree(int postOrder[], int size) { 
    int postIndex = size - 1; 
    
    return constructTreeUtil(postOrder, &postIndex, postOrder[postIndex], INT_MIN, INT_MAX, size); 
}  

void printLevel(tree_t *root, int level) {
     
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else if(level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int height(tree_t *root) {
    int lheight, rheight;
    
    if(root == NULL)
        return 0;
    else {
        lheight = height(root->left);
        rheight = height(root->right);
    }
    if(lheight > rheight)
        return lheight + 1;
    else
        return rheight + 1;
    
}

void printLevelOrder(tree_t *root) {
    int h = height(root);
    int i;
    
    for(i = 0; i <= h; i++) 
        printLevel(root, i);
    
    printf("\n");

}

void freeTree(tree_t *root) {
    if(root != NULL) {
        freeTree(root->right);
        freeTree(root->left);
        free(root);
    }
}

tree_t *completeTreeLevelOrder(int *levelOrder, tree_t *root, int i, int n) {
     if (i < n) { 
        tree_t* temp = newNode(levelOrder[i]); 
        root = temp; 
    
        root->left = completeTreeLevelOrder(levelOrder, root->left, 2 * i + 1, n); 

        root->right = completeTreeLevelOrder(levelOrder, root->right, 2 * i + 2, n); 
    } 
    return root; 
}

int isBST(tree_t *root)  {  
  return(isBSTUtil(root, INT_MIN, INT_MAX));  
}  
  
int isBSTUtil(tree_t *root, int min, int max) {  
    
  if (root == NULL)  
     return 1; 
    
  if (root->data < min || root->data > max)  
     return 0;  

  return 
    isBSTUtil(root->left, min, root->data-1) &&  isBSTUtil(root->right, root->data+1, max);  
}  

