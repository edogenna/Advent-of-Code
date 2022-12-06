#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "2022/day4/input.txt"
#define STR_LEN 80


void numbersFromString(char* str, int* n1, int* n2, int* n3, int* n4){
    int i;

    *n1 = 0;
    *n2 = 0;
    *n3 = 0;
    *n4 = 0;

    for(i = 0; str[i] != '-'; i++){
        (*n1) *= 10;
        (*n1) += (int)(str[i] - '0');
    }

    for(i++; str[i] != ','; i++){
        (*n2) *= 10;
        (*n2) += (str[i] - '0');
    }

    for(i++; str[i] != '-'; i++){
        (*n3) *= 10;
        (*n3) += (str[i] - '0');
    }

    for(i++; str[i] != '\0'; i++){
        (*n4) *= 10;
        (*n4) += (str[i] - '0');
    }

}

int isACoupleConteiningAnother(int elfSx1, int elfDx1, int elfSx2, int elfDx2){
    return (elfSx1 <= elfSx2 && elfDx1 >= elfDx2) || (elfSx2 <= elfSx1 && elfDx2 >= elfDx1);
}

int isACoupleOverlappingAnother(int elfSx1, int elfDx1, int elfSx2, int elfDx2){
    return ((elfSx2 <= elfDx1 && elfDx1 <= elfDx2) || (elfSx2 <= elfSx1 && elfSx1 <= elfDx2) ||
            (elfSx1 <= elfDx2 && elfDx2 <= elfDx1) || (elfSx1 <= elfSx2 && elfSx2 <= elfDx1));
}

int partOne(){
    char str[STR_LEN];
    int myScore = 0;
    int elfSx1,elfDx1,elfSx2,elfDx2;

    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fscanf(fp, " %s", str);
    while(!feof(fp)){
        printf("letto:%s\n",str);
        numbersFromString(str, &elfSx1, &elfDx1, &elfSx2, &elfDx2);
        printf("%d %d %d %d\n", elfSx1, elfDx1, elfSx2, elfDx2);

        myScore += isACoupleConteiningAnother(elfSx1, elfDx1, elfSx2, elfDx2);

        fscanf(fp, " %s", str);
    }


    printf("My score: %d", myScore);

    return 0;
}

int partTwo(){
    char str[STR_LEN];
    int myScore = 0;
    int elfSx1,elfDx1,elfSx2,elfDx2;

    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fscanf(fp, " %s", str);
    while(!feof(fp)){
        printf("letto:%s\n",str);
        numbersFromString(str, &elfSx1, &elfDx1, &elfSx2, &elfDx2);
        printf("%d %d %d %d\n", elfSx1, elfDx1, elfSx2, elfDx2);

        myScore += isACoupleOverlappingAnother(elfSx1, elfDx1, elfSx2, elfDx2);

        fscanf(fp, " %s", str);
    }


    printf("My score: %d", myScore);

    return 0;
}


int main(){
    return partTwo();
}
