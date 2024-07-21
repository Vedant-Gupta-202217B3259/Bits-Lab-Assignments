#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list node
struct node {
    // Key is string
    char* key;
    // Value is also string
    char* value;
    struct node* next;
};

// Constructor for node
void setNode(struct node* node, char* key, char* value) {
    node->key = strdup(key);  // Duplicate the string to allocate new memory
    node->value = strdup(value);  // Duplicate the string to allocate new memory
    node->next = NULL;
}

struct hashMap {
    // Current number of elements in hashMap
    int numOfElements;
    // Capacity of hashMap
    int capacity;
    // Hold base address array of linked list
    struct node** arr;
};

// Constructor for hashMap
void initializeHashMap(struct hashMap* mp) {
    // Default capacity in this case
    mp->capacity = 100;
    mp->numOfElements = 0;
    // Allocate memory for the array of linked list heads
    mp->arr = (struct node**)calloc(mp->capacity, sizeof(struct node*));
}

int hashFunction(struct hashMap* mp, char* key) {
    int sum = 0;
    int factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        // sum = sum + (ascii value of char * (primeNumber ^ x))... where x = 1,2,3...n
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        // factor = factor * prime number ...(prime number) ^ x
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    return sum;
}

void insert(struct hashMap* mp, char* key, char* value) {
    // Getting bucket index for the given key-value pair
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

void deleteNode(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* preNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                preNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;
            return;
        }
        preNode = currNode;
        currNode = currNode->next;
    }
}

char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL) {
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }

    return "Oops! No data found.\n";
}

int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));
    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion:\n");
    deleteNode(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));

    // Free the allocated memory for hashMap
    for (int i = 0; i < mp->capacity; i++) {
        struct node* currNode = mp->arr[i];
        while (currNode != NULL) {
            struct node* temp = currNode;
            currNode = currNode->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(mp->arr);
    free(mp);

    return 0;
}
