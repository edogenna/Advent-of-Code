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

int isOneInsideTheOther(int conteiner1, int conteiner2, int content1, int content2){
    return content1 < conteiner1 || content2 > conteiner2)
}

int isACoupleConteiningAnother(int elfSx1, int elfDx1, int elfSx2, int elfDx2){
    return ()


    if(isOneInsideTheOther(n1,n2,n3,n4) || isOneInsideTheOther(n3,n4,n1,n2))

}

int partOne(){
    char str[STR_LEN];
    int myScore = 0;
    int n1,n2,n3,n4;


    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fscanf(fp, " %s", str);
    while(!feof(fp)){
        printf("letto:%s\n",str);
        numbersFromString(str, &n1, &n2, &n3,&n4);
        printf("%d %d %d %d\n", n1,n2,n3,n4);


        fscanf(fp, " %s", str);
    }


    printf("My score: %d", myScore);

    return 0;
}

int partTwo(){


    return 0;
}


int main(){
    return partOne();
}
