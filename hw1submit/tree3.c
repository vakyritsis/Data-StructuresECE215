#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <limits.h>

int  getPath(tree_t *root, int path[], int n, int *size) {
    if(root == NULL)
        return 0; 
    path[*size] = root->data;
    (*size)++;
    if(root->data == n)
      return 1;
    
    if(getPath(root->left, path, n, size) == 1 || getPath(root->right, path, n, size) == 1)
      return 1;

    (*size)--;
    return 0;
}

void printPath(tree_t *root, int x, int y) {
    int path1[height(root)];
    int path2[height(root)];
    int size1 = 0, size2 = 0;
    int res1, res2;
    
    res1 = getPath(root, path1, x, &size1);
    if(res1 == 0) {
      printf("%d not found!\n", x);
      return;
    }
    
    res2 = getPath(root, path2, y, &size2);
    if(res2 == 0) {
      printf("%d not found!\n", y);
      return;
    }

    int intersection = -1;
    int i = 0, j = 0;
    
    while(i != size1 || j != size2) {
      if(i == j && path1[i] == path2[j]) {
        i++;
        j++;
      }
      else {
        intersection = j - 1;
        break;
      }
    }
    
    printf("\nPath is: ");
    for(i = size1 - 1; i > intersection; i--)
      printf("%d ", path1[i]);

    for(i = intersection; i < size2; i++)
      printf("%d ", path2[i]);

    printf("\n");
}

tree_t* BSTpreOrderUtil(int preOrder[], int* preIndex, int key, int min, int max, int size){
    if (*preIndex >= size)
        return NULL;
 
    tree_t* root = NULL;
 
    if (key > min && key < max) {
        
        root = newNode(key);
        *preIndex = *preIndex + 1;
 
        if (*preIndex < size) {
            root->left = BSTpreOrderUtil(preOrder, preIndex, preOrder[*preIndex], min, key, size);
        }
        if (*preIndex < size) {
            root->right = BSTpreOrderUtil(preOrder, preIndex, preOrder[*preIndex], key, max, size);
        }
    }
    return root;
}
 
tree_t *BSTpreOrder(int preOrder[], int size){
    int preIndex = 0;
    return BSTpreOrderUtil(preOrder, &preIndex, preOrder[0], INT_MIN, INT_MAX, size);
}

int main(int agrc, char *argv[]) {
    // 50 33 12 5 18 37 35 72 65 88 -1| 35 88|   35 37 33 50 72 88

    int input, size = 0;
    int *preOrder;
    tree_t *root;
    int x, y;
    preOrder = (int*)malloc(sizeof(int));

    while(1) {
        scanf("%d", &input);
        if(input < 0)
            break;
        else {
            preOrder = (int*)realloc(preOrder, sizeof(int) * (size + 1));
            preOrder[size] = input;
            size++;
            }
        }
  
    root = BSTpreOrder(preOrder, size);
    
    printf("Enter 2 integers: ");
    scanf("%d %d", &x, &y);
    
    printPath(root, x, y);
  
    freeTree(root);
    free(preOrder);
  return 0;
}
