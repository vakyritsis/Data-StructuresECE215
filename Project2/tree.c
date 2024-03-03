#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tree.h"

tree_t *newNode(int data) {
    tree_t *temp = (tree_t*)malloc(sizeof(tree_t));

    temp->data = data;
    temp->right = temp->left = NULL;

    return temp;
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

int getLevelUtil(tree_t *root, int data, int level) { 
    if (root == NULL) 
        return 0; 
  
    if (root->data == data) 
        return level; 
  
    int downlevel = getLevelUtil(root->left, data, level + 1); 
    if (downlevel != 0) 
        return downlevel; 
  
    downlevel = getLevelUtil(root->right, data, level + 1); 
    return downlevel; 
} 
  
int getLevel(tree_t *root, int data) { 
    return getLevelUtil(root,data,1); 
} 

void printGivenLevel(tree_t *root, int level) {
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) { 
        printGivenLevel(root->left, level - 1); 
        printGivenLevel(root->right, level - 1); 
    } 
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

void printPreOrder(tree_t *root) {
    if(root == NULL)
        return;
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

tree_t * BSTfromArray(int arr[], int start, int end) {
    if(start > end)
        return NULL;

    int mid = (start + end) / 2;
    tree_t *root = newNode(arr[mid]);

    root->left = BSTfromArray(arr, start, mid - 1);

    root->right = BSTfromArray(arr, mid + 1, end);

    return root;
}
