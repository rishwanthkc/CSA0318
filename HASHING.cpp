#include <stdio.h>

#define SIZE 10

// Hash Function
int hash(int key) {
    return key % SIZE;
}

// Insertion using Linear Probing
void insert(int hashTable[], int key) {
    int index = hash(key);

    // Linear Probing
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

// Search using Linear Probing
int search(int hashTable[], int key) {
    int index = hash(key);

    // Linear Probing
    while (hashTable[index] != key) {
        if (hashTable[index] == -1) {
            return -1; // Key not found
        }
        index = (index + 1) % SIZE;
    }

    return index; // Index where key is found
}

// Display the Hash Table
void display(int hashTable[]) {
    printf("Hash Table: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // Initialize all slots with -1 indicating empty
    }

    insert(hashTable, 5);
    insert(hashTable, 15);
    insert(hashTable, 25);

    display(hashTable);

    int keyToSearch = 15;
    int result = search(hashTable, keyToSearch);

    if (result != -1) {
        printf("Key %d found at index %d\n", keyToSearch, result);
    } else {
        printf("Key %d not found\n", keyToSearch);
    }

    return 0;
}

