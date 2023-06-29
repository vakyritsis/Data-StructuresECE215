#ifndef __HTABLE_
#define __HTABLE_

typedef struct hashTable {
    int **table;
    float loadFactor;
    int rehash; 
    int entries;
    int size;
} hashTable;

void hash_init(hashTable *htable);

void rehashing(hashTable *htable, int newSize);

int hash_add(hashTable *htable, int *data);

int hash_delete(hashTable *htable, int *data);

int hash_find(hashTable *htable, int *data);

void print(hashTable htable);

#endif
