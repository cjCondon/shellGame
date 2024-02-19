#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "hashmap.c"

#define MAX_WORD_COUNT 26
#define MAX_WORD_LENGTH 40
#define HASH_TABLE_CAPACITY 25

void tokenize(char*  str, char tokenArr[MAX_WORD_COUNT][MAX_WORD_LENGTH]){
    char* token = strtok(str, " ");
    
    int i = 2;

    while(token != NULL){
        strcpy(tokenArr[i], token);
        printf("%s\n", token);
        token = token = strtok(NULL, " ");

        i++;
    }
}

void processTokens(HashTable* table, char tokens[MAX_WORD_COUNT][MAX_WORD_LENGTH]){
    int i = 0;

    while(strlen(tokens[i]) != 0){

        int tokenAction = hashTableRetrive(table, tokens[i]);
        switch (tokenAction){
        
            case 0:
                exit(0);
            case 1:
                printf("hello world!\n");
                break;
            default:
                printf("ERROR: command \" %s \" was not recognized", tokens[i]);
        }

        i++;
    }
}

void initHashTable(HashTable* table){
    hashTableInsert(table, "exit", 0);
}

void processInput(char* input){
    char tokenArr[MAX_WORD_COUNT][MAX_WORD_LENGTH];
    tokenize(input, tokenArr);
    
    HashTable* table = malloc(sizeof(HashTable));
    
    if(table == NULL){
        perror("Table was NULL at allocatio");
        exit(EXIT_FAILURE);
    }
    
    initHashTable(table);
    printf("hello there\n");
    
    processTokens(table, tokenArr);
    
}

