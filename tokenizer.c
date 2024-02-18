#include <string.h>

void tokenize(char*  str){
    char* token = strtok(str, " ");

    while(token != NULL){
        printf("%s\n", token);
        token = token = strtok(NULL, " ");
    }
}
