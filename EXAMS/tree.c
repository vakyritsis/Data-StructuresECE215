#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>
#include "tree.h"

tree_t* newNode(int data) { 
    tree_t* new = (tree_t*)malloc(sizeof(tree_t)); 
    new->data = data; 
    new->left = NULL; 
    new->right = NULL; 
  
    return (new); 
}  

tree_t *BST_preOrderUtil(int pre[], int* preIndex, int key, int min, int max, int size) {
    if (*preIndex >= size)
        return NULL;
 
    tree_t *root = NULL;
 
    if (key > min && key < max) {
        root = newNode(key);
        *preIndex = *preIndex + 1;
 
        if (*preIndex < size)  {
            root->left = BST_preOrderUtil(pre, preIndex, pre[*preIndex], min, key, size);
        }
        if (*preIndex < size) {
            root->right = BST_preOrderUtil(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }
 
    return root;
}

tree_t *BST_preOrder(int pre[], int size) {
    int preIndex = 0;
    return BST_preOrderUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
}

void freeTree(tree_t *root) {
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

void printLeafNodes(tree_t *root) {
    if (!root)
        return;
     
    if (!root->left && !root->right) {
        printf("%d ", root->data);
        return;
    }
 
    if (root->left)
       printLeafNodes(root->left);
         
    if (root->right)
       printLeafNodes(root->right);
} 

int getHeight(tree_t *Node) {
    if (Node == NULL)
        return 0;
    else {
        int lHeight = getHeight(Node->left);
        int rHeight = getHeight(Node->right);
 
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}

void printPreorder(tree_t *node) { 
     if (node == NULL) 
          return; 
     printf("%d#%d ", node->data, getHeight(node));   
     printPreorder(node->left);   
     printPreorder(node->right); 
}   

int max(int a, int b) { 
    return (a >= b) ? a : b; 
} 

int height(tree_t *node) { 
    if (node == NULL) 
        return 0; 
  
    return 1 + max(height(node->left), height(node->right)); 
} 


int isBalanced(tree_t *root, int *matrix, int *i) { 
    int leftHeight;
    int rightHeight; 
  
    
    if (root == NULL) 
        return 1; 
  
    leftHeight = height(root->left); 
    rightHeight = height(root->right); 
  
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left, matrix, i) && isBalanced(root->right, matrix, i)) 
        return 1; 
    (matrix[*i]) = root->data;
    (*i)++;
    
    return 0; 
} 
