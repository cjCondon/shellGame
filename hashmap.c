#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 40
#define MAX_WORD_COUNT 26

 typedef struct Bucket{

    char key[MAX_WORD_LENGTH];
    int value;    
    struct Bucket* next;

}Bucket;

typedef struct HashTable{
   
   int capacity;
   struct Bucket bucketArr[MAX_WORD_COUNT];

}HashTable;

//polynomial hash function (same one java uses for strings)

int getStringHashCode(char str[]){
    const int prime = 31;
    int hashCode = 0;

    for(int i = 0; i<strlen(str); i++){
        char ch = str[i];
        hashCode = prime * hashCode + ch;
    }
    printf("hello there\n");

    return hashCode;
}

void hashTableInsert(HashTable* table, char* key, int value){
    int hashIndex = getStringHashCode(key);
    hashIndex %= table->capacity;

    Bucket *currentBucket = &table->bucketArr[hashIndex];
    Bucket *newBucket = malloc(sizeof(Bucket));

    if (newBucket == NULL) {
        perror("Failed to allocate memory for new bucket");
        exit(EXIT_FAILURE);
    }

    strcpy(newBucket->key, key);
    newBucket->value = value;
    newBucket->next = NULL;

    if (currentBucket->next == NULL) {
        currentBucket->next = newBucket;
        return;
    }

    // Traverse to end of chain in event of collisions
    while (currentBucket->next != NULL) {
        currentBucket = currentBucket->next;
    }

    currentBucket->next = newBucket;
}

int hashTableRetrive(HashTable* table, char key[]){
    
    int hashIndex = getStringHashCode(key);
    hashIndex %= table->capacity;

    Bucket* targetBucket = &table->bucketArr[hashIndex];

    while(targetBucket->key != key && targetBucket->next != NULL){
        targetBucket = targetBucket->next;
    }

    if(targetBucket->key != key){
        perror("ERROR: key was not found in HashTable upon retrival request");
        exit(EXIT_FAILURE);
    }

    return targetBucket->value;
}
