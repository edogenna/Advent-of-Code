#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "2022\\day1\\input.txt"
#define BASE 10
#define STR_LEN 30
#define TOP_LEN 3

int strToInt(char* str){
    int num = 0;

    if(str == NULL)
        return INT_MIN;

    while(*str != '\0'){
        if(*str == '\n'){
            str++;
            continue;
        }

        num = num*BASE + (*str - '0');
        str++;
    }

    return num;
}

void setIntArToZero(int* ar, int dim){
    for(int i = 0; i < dim; i++)
        ar[i] = 0;
}

void insertIntoMaxAr(int* ar, int dim, int elem){
    int tmp = elem;
    int swap;
    for(int i = 0; i < dim; i++){
        if(tmp > ar[i]){
           swap = ar[i];
           ar[i] = tmp;
           tmp = swap;
        }
    }
}

int sumInArray(int* ar, int dim){
    int sum = 0;
    for(int i = 0; i < dim; i++){
        sum += ar[i];
    }

    return sum;
}


int main(){
    int maxCalories[TOP_LEN];
    setIntArToZero(maxCalories, TOP_LEN);

    int currCalories = 0;
    char str[STR_LEN];

    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fgets(str,STR_LEN, fp);
    while(!feof(fp)){
        //new Elf
        if(*str == '\n'){
            insertIntoMaxAr(maxCalories, TOP_LEN, currCalories);
            currCalories = 0;
        }else{
            currCalories += strToInt(str);
        }

        fgets(str,STR_LEN, fp);
    }

    for(int i = 0; i < TOP_LEN; i++){
        printf("Top %d: %d\n", i, maxCalories[i]);
    }

    printf("Sum of top %d is: %d", TOP_LEN, sumInArray(maxCalories,TOP_LEN));


    return 0;
}
