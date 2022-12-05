#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "2022/day3/input.txt"
#define STR_LEN 80

int strLen(char *str){

}

int itemToPriority(char item){
    if(item >= 'a' && item <= 'z')
        return (int)(item - 'a' + 1);

    return (int)(item - 'A' + 27);
}

char itemInBothRucksack(char *str){
    int firstHalf[128] = {0};
    int secondHalf[128] = {0};
    int len = strlen(str);

    for(int i = 0; i < len/2; i++){
        firstHalf[str[i]]++;
    }

    for(int i = len/2; i < len; i++)
        secondHalf[str[i]]++;

    for(int i = 0; i < 128; i++){
        if(firstHalf[i] != 0 && secondHalf[i] != 0){
            return (char)i;
        }
    }

    return 0;
}



int partOne(){
    char str[STR_LEN];
    int myScore = 0;
    int po;

    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fscanf(fp, " %s", str);
    while(!feof(fp)){
        myScore += itemToPriority(itemInBothRucksack(str));

        fscanf(fp, " %s", str);
    }


    printf("My score: %d", myScore);

    return 0;
}



int main(){
    return partOne();
}
