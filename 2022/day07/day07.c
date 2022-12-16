#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define FILE_NAME "2022/day07/example.txt"
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
    int numSubFolder = 0;
    int flag = 1;

    fscanf(fp, " %[^\n]", str);

    while(flag && !feof(fp)){

        printf("ho letto: %s\n", str);

        if(isDigit(str[0])){  //file
            dimFolders[currentFolder] += atoi(str);
        }else if(str[0] == '$' && str[2] == 'c' && str[3] == 'd' && str[5] == '.'){ //$ cd ..
            return dimFolders[currentFolder];
        }else if(str[0] == 'd' && str[1] == 'i' && str[2] == 'r'){ //dir
            numSubFolder++;
        }else if(str[0] == '$' && str[2] == 'c' && str[3] == 'd' && str[5] != '/' && str[5] != '.'){  //$ cd a
            flag = 0;
        }
        fscanf(fp, " %[^\n]", str);
    }

    for(int i = 0; i < numSubFolder; i++)
        dimFolders[currentFolder] += calculateDimensionFolder();

    return dimFolders[currentFolder];
}


int main(){
    fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    calculateDimensionFolder();

    for(int i = 0; i < numFolders; i++){
        printf("%d\n", dimFolders[i]);
    }

    fclose(fp);

    return 0;
}