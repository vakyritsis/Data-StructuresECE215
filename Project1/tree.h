#ifndef __TREE_H_
#define __TREE_H_

/* Structs*/
typedef struct tree {
    struct tree *left;
    struct tree *right;
    int data;
} tree_t;


/* Functions*/
tree_t *newNode (int data);//will be used for every program 

tree_t *constructTreeUtil(int post[], int* postIndex, int key, int min, int max, int size);

tree_t *constructTree(int post[], int size);

void printLevel(tree_t *root, int level);

int height(tree_t *root);

void printLevelOrder(tree_t *root);

void freeTree(tree_t *root);//will be used for every program

tree_t *completeTreeLevelOrder(int *levelOrder, tree_t *root, int i, int n);

int isBST(tree_t *root);

int isBSTUtil(tree_t *root, int min, int max);


#endif

