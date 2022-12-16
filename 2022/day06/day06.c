#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define FILE_NAME "2022/day06/input.txt"
#define STR_LEN 5000
#define WIN_LEN 14

int noDuplicates(char* str, int dim){
   for(int i = 1; i < dim; i++){
        for(int j = 0; j < i; j++){
            if(str[i] == str[j])
                return 0;
        }
    }

    return 1;
}

int analizeString(char* str){
    for(int i = 0; str[i+WIN_LEN] != '\0'; i++){
        if(noDuplicates(str+i, WIN_LEN)){
            return i + WIN_LEN;
        }
    }

    return -1;
}

int main(){
    char str[STR_LEN];

    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fgets(str, STR_LEN, fp);
    while(!feof(fp)){
        printf("Result: %d", analizeString(str));

        fgets(str, STR_LEN, fp);
    }

    fclose(fp);

    return 0;
}