#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define FILE_NAME "2022/day7/input.txt"
#define FOLDERS_NUM 500
#define STR_LEN 80

int dimFolders[FOLDERS_NUM] = {0};
char str[STR_LEN];
int numFolders = 0;
FILE *fp;


int isDigit(char c){
    return '0' <= c && c <= '9';
}


int calculateDimensionFolder(){
    int currentFolder = numFolders;
    numFolders++;


    while(!feof(fp)){
        if(isDigit(str[0])){  //file
            dimFolders[currentFolder] += atoi(str);
        }else if(str[0] == '$' && str[5] == '.'){ //out of the level
            return dimFolders[currentFolder];
        }else if(str[0] == '$' && str[5] != '.'){
            dimFolders[currentFolder] += calculateDimensionFolder();
        }

        fgets(str, STR_LEN, fp);
    }

    return dimFolders[currentFolder];

}


int main(){
    fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }


    while(!feof(fp)){


        fgets(str, STR_LEN, fp);
    }

    fclose(fp);

    return 0;
}