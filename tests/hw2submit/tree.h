#ifndef __TREE_H_
#define __TREE_H_

typedef struct tree {
    int data;
    struct tree *left, *right;
} tree_t; 

tree_t *newNode(int data);

tree_t *BST_preOrderUtil(int pre[], int* preIndex, int key, int min, int max, int size);

tree_t *BST_preOrder(int pre[], int size);

int getLevelUtil(tree_t *root, int data, int level);

int getLevel(tree_t *root, int data);

void printGivenLevel(tree_t *root, int level);

void freeTree(tree_t *root);

void printPreOrder(tree_t *root) ;

tree_t * BSTfromArray(int arr[], int start, int end);


#endif
