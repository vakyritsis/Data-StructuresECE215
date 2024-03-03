#ifndef __HBTREE_
#define __HBTREE_

typedef struct hbtree {
    int key;
    struct hbtree *left;
    struct hbtree *right;
    int height;
    int weight;
}hbtree;

int count_nodes(hbtree *root); 

int height(hbtree *node);

int max(int a, int b);

hbtree *newNode(int key);

hbtree *rightRotation(hbtree *y);

hbtree *leftRotation(hbtree *x);

int getBalance(hbtree *node);

hbtree *insert_tree(hbtree *node, int key);

hbtree *minValueNode(hbtree *node);

hbtree *check(hbtree *root);

hbtree *delete_tree(hbtree *root, int key);

hbtree *search(hbtree *root, int key);

void printPreOrder(hbtree *root);

void freeTree(hbtree *root);

#endif
