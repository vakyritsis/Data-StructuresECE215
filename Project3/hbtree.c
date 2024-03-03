#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hbtree.h"
/* Calculated the weight of a node */
int count_nodes(hbtree *root) {
    if(root == NULL) 
        return 0;
    else 
        return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int height(hbtree *node) {
    if(node == NULL)
        return 0;
    else
        return node->height;
}

int max(int a, int b) {
    return (a > b)? a : b;
}

hbtree *newNode(int key) {
    hbtree *node = (hbtree*)malloc(sizeof(hbtree));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->weight = 1;

    return node;
}

hbtree *rightRotation(hbtree *y) {
    hbtree *x = y->left;
    hbtree *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
   
    return x; 
}

hbtree *leftRotation(hbtree *x) {
    hbtree *y = x->right;
    hbtree *T2 = y->left;

    y->left = x; 
    x->right = T2; 
  
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    return y;
}

int getBalance(hbtree *node) {
    if(node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

hbtree *insert_tree(hbtree *node, int key) {
    if(node == NULL)
        return(newNode(key));
    
    if(key < node->key)
        node->left = insert_tree(node->left, key);
    else if(key > node->key)
        node->right = insert_tree(node->right, key);
    else         
        return node;
    

    node->height = 1 + max(height(node->left), height(node->right));
    node->weight = count_nodes(node);

    int balance = getBalance(node);
    int b = max(1, floor(log2(node->weight)));

    if(balance > b && key < node->left->key)
        return rightRotation(node);
    
    if(balance < -b && key > node->right->key)
        return leftRotation(node);

    if(balance > b && key > node->left->key) {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    if(balance < -b && key < node->right->key) {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}

/* finds the node with smallest key without search the entire tree */
hbtree *minValueNode(hbtree *node) {
    hbtree *curr = node;

    while(curr->left != NULL)
        curr = curr->left;
    
    return curr;
}

hbtree *check(hbtree *root) {
    if(root == NULL)
        return root;

    root->weight = count_nodes(root);
    int balance = getBalance(root);
    int b = max(1, floor(log2(root->weight)));

    if(balance > b && getBalance(root->left) >= 0)
        return rightRotation(root);

    if (balance > b && getBalance(root->left) < 0) { 
        root->left =  leftRotation(root->left); 
        return rightRotation(root); 
    } 
  
    if (balance < -b && getBalance(root->right) <= 0) 
        return leftRotation(root); 
  
    if (balance < -b && getBalance(root->right) > 0) { 
        root->right = rightRotation(root->right); 
        return leftRotation(root); 
    } 

    root->left = check(root->left);
    root->right = check(root->right);
    return root;
}

hbtree *delete_tree(hbtree *root, int key) {
    if(root == NULL)
        return root;

    if(key < root->key)
        root->left = delete_tree(root->left, key);
    else if(key > root->key)
        root->right = delete_tree(root->right, key);
    // same as root
    else {
        // one child or no child
        if((root->left == NULL) || (root->right == NULL)) {
            hbtree *temp = root->left ? root->left : root->right;
            // no child
            if(temp == NULL) {
                temp = root;
                root = NULL;
            }
            else // one child
                *root = *temp;
            free(temp);
        }
        // two children
        else {
            hbtree *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = delete_tree(root->right, temp->key);
        }
    }

    if(root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right)); 
    root->weight = count_nodes(root);

    int balance = getBalance(root);
    int b = max(1, floor(log2(root->weight)));

    if (balance > b && getBalance(root->left) >= 0) 
        return rightRotation(root); 
  
    if (balance > b && getBalance(root->left) < 0) { 
        root->left =  leftRotation(root->left); 
        return rightRotation(root); 
    } 
  
    if (balance < -b && getBalance(root->right) <= 0) 
        return leftRotation(root); 
  
    if (balance < -b && getBalance(root->right) > 0) { 
        root->right = rightRotation(root->right); 
        return leftRotation(root); 
    } 
  
    return root;
}

hbtree *search(hbtree *root, int key) {
    if(root == NULL || root->key == key)
        return root;
    if (root->key < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
}

void printPreOrder(hbtree *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void freeTree(hbtree *root) {
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
