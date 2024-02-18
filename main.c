#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.c"

#define MAX 1024

int main(){
    printf("Enter in prompt\n");

    char input[MAX];
    fgets(input, MAX, stdin);
    
    printf("\n");

    tokenize(input);
    return 0;
}
