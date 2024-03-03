#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void insertionSort(int arr[], int n) {
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

int main(int argc, char *argv[]) {
    int input, size = 0;
    int *arr;
    tree_t *root;

    arr = (int*)malloc(sizeof(int));

    while(1) {
        scanf("%d", &input);
        if(input < 0)
            break;
        if(size != 0)
            arr = (int*)realloc(arr, sizeof(int) * (size + 1));
        arr[size] = input;
        size++;
    }

    insertionSort(arr, size);
    root = BSTfromArray(arr, 0, size - 1);
    printPreOrder(root);

    freeTree(root);
    free(arr);
    return 0;
} 
