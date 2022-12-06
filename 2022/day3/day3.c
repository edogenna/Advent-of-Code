#include <stdio.h>
#include <string.h>

#define FILE_NAME "2022/day3/input.txt"
#define STR_LEN 80


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

char commonItemIn3Rucksack(char* str1, char* str2, char* str3){
    int count1[128] = {0};
    int count2[128] = {0};
    int count3[128] = {0};

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);

    for(int i = 0; i < len1; i++)
        count1[str1[i]]++;

    for(int i = 0; i < len2; i++)
        count2[str2[i]]++;

    for(int i = 0; i < len3; i++)
        count3[str3[i]]++;

    for(int i = 0; i < 128; i++){
        if(count1[i] != 0 && count2[i] != 0 && count3[i] != 0){
            return (char)i;
        }
    }
}



int partOne(){
    char str[STR_LEN];
    int myScore = 0;

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

    fclose(fp);

    printf("My score: %d", myScore);

    return 0;
}

int partTwo(){
    char str1[STR_LEN];
    char str2[STR_LEN];
    char str3[STR_LEN];
    int myScore = 0;

    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fscanf(fp, " %s", str1);
    fscanf(fp, " %s", str2);
    fscanf(fp, " %s", str3);
    while(!feof(fp)){
        myScore += itemToPriority(commonItemIn3Rucksack(str1,str2,str3));

        fscanf(fp, " %s", str1);
        fscanf(fp, " %s", str2);
        fscanf(fp, " %s", str3);
    }

    fclose(fp);

    printf("My score: %d", myScore);

    return 0;
}


int main(){
    return partTwo();
}
