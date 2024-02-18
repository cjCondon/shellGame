#include <string.h>
#include <stdio.h>
#include "hashmap.c"

#define MAX_WORD_COUNT 26
#define MAX_WORD_LENGTH 41

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

void processInput(char* input){
    char tokenArr[MAX_WORD_COUNT][MAX_WORD_LENGTH];
    tokenize(input, tokenArr);
}

