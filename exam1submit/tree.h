#ifndef __TREE_
#define __TREE_

typedef struct tree_t {
    struct tree_t *left, *right;
    int data;
} tree_t; 

tree_t* newNode(int data);

tree_t *BST_preOrderUtil(int pre[], int* preIndex, int key, int min, int max, int size);

tree_t *BST_preOrder(int pre[], int size);

void freeTree(tree_t *root);

void printLeafNodes(tree_t *root);

int getHeight(tree_t *Node);

void printPreorder(tree_t *node);

int max(int a, int b);

int height(tree_t *node);

int isBalanced(tree_t *root, int *matrix, int *i);

#endif
