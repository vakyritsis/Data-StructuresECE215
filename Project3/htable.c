#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

void hash_init(hashTable *htable) {
    int i;
    htable->loadFactor = 0;
    htable->rehash = 1; //rehashing active 
    htable->entries = 0;
    htable->size = 2;
    htable->table = (int**)malloc(sizeof(int*) * htable->size);

    /*initialize the hash table with NULL*/

    for(i = 0; i < htable->size; i++)
        htable->table[i] = NULL;

}

void rehashing(hashTable *htable, int newSize) {
    int **curr;
    int i, j;
    int index;
    int placed = 0;;
    curr = (int**)malloc(sizeof(int*) * newSize);

    for(i = 0; i < newSize; i++)
        curr[i] = NULL;

    for(i = 0; i < htable->size; i++) {
        if(htable->table[i] != NULL && htable->table[i] != (int*)0x1) {
            index = *htable->table[i] % newSize; //get index.
            if(curr[index] == NULL) // if empty place it 
                curr[index] = htable->table[i]; 
            else {
                j = index;
                while(j < newSize - 1) {
                    j++;
                  if(curr[j] == NULL) {
                      curr[j] = htable->table[i];
                      placed = 1;
                      break;
                  }
                }
                if(placed == 0) {
                    j = 0;
                    while(j < index) {
                        j++;
                        if(curr[j] == NULL) {
                            curr[j] = htable->table[i];
                            continue;
                        }   
                    }
                }
            }
        }
    }
    free(htable->table);
    htable->table = curr;
    htable->size = newSize;
    htable->loadFactor = (float)htable->entries / (float)htable->size;
}

int hash_add(hashTable *htable, int *data) {
    int index = *data % htable->size;;
    int i;
    
    if(htable->table[index] == NULL || htable->table[index] == (int*)0x1) {
        
        htable->table[index] = data;
        htable->entries++;
        htable->loadFactor = (float)htable->entries / (float)htable->size;

        return 1;
    }
    else { 
        i = index;
        while(i < htable->size - 1) {
            i++;
            if(htable->table[i] == NULL || htable->table[i] == (int*)0x1) {
        
                htable->table[i] = data;
                htable->entries++;
                htable->loadFactor = (float)htable->entries / (float)htable->size;

                return 1;
            }
        }
        i = 0;
        
        while(i < index) {
            
            if(htable->table[i] == NULL || htable->table[i] == (int*)0x1) {
        
                htable->table[i] = data;
                htable->entries++;
                htable->loadFactor = (float)htable->entries / (float)htable->size;

                return 1;
            }
            i++;
        }
        return 0;
    }
}

int hash_delete(hashTable *htable, int *data) {
    int index;
    int i;
    index = *data % htable->size;
    
    if(htable->table[index] != NULL && htable->table[index] != (int*)0x1 && *htable->table[index] == *data) {
        htable->table[index] = (int*)0x1;
        htable->entries--;
        htable->loadFactor = (float)htable->entries / (float)htable->size;

        if(htable->rehash == 1 && htable->loadFactor <= 0.125 && htable->size > 2)
            rehashing(htable, htable->size / 2);
        return 1;
    }
    else {
        i = index;
        while(i < htable->size - 1) {
            i++;
            if(htable->table[i] != NULL && htable->table[i] != (int*)0x1 && *htable->table[i] == *data) {

                htable->table[i] = (int*)0x1;
                htable->entries--;
                htable->loadFactor = (float)htable->entries / (float)htable->size;

                if(htable->rehash == 1 && htable->loadFactor <= 0.125 && htable->size > 2)
                    rehashing(htable, htable->size / 2);
                return 1;
            }
        }
        i = 0;
        while(i < index) {
            i++;
            if(htable->table[i] != NULL && htable->table[i] != (int*)0x1 && *htable->table[i] == *data) {

                htable->table[i] = (int*)0x1;
                htable->entries--;
                htable->loadFactor = (float)htable->entries / (float)htable->size;

                if(htable->rehash == 1 && htable->loadFactor <= 0.125 && htable->size > 2)
                    rehashing(htable, htable->size / 2);
                return 1;
            }

        }
    }
    return 0;
}

int hash_find(hashTable *htable, int *data) {
    int index, i;

    index = *data % htable->size;

    if(htable->table[index] != NULL && *htable->table[index] == *data)
        return 1;
    else {
        i = index;
        while(i < htable->size - 1) {
            i++;
            if(htable->table[i] != NULL && *htable->table[i] == *data)
                return 1;
        }
        i = 0;
        while(i < index) {
            i++;
            if(htable->table[i] != NULL && *htable->table[i] == *data)
                return 1;
        }
        return 0;
    }
}

void print(hashTable htable) {
    int i;
    int inserted = 0, deleted = 0;
    
    for(i = 0; i < htable.size; i++){
        if(htable.table[i] != NULL && htable.table[i] != (int*)0x1)
            inserted++;
        if(htable.table[i] == (int*)0x1)
            deleted++;
    }

    printf("\nSIZE: %d, INSERTED: %d, DELETED: %d\n", htable.size,  inserted, deleted);

    for(i = 0; i < htable.size; i++)
        printf("%3d ", i);
    printf("\n");

    for(i = 0; i < htable.size; i++) {
        if(htable.table[i] != NULL && htable.table[i] != (int*)0x1)
            printf("%3d ", *htable.table[i]);
        else if(htable.table[i] == NULL)
            printf("  * ");
        else if(htable.table[i] == (int*)0x1)
            printf("  # ");
    }
    printf("\n");
}
 
