#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "2022/day12/input.txt"
#define STR_LEN 150
#define COL 114
#define ROW 41

char m[ROW][COL];
int rowS, colS, rowE, colE;


int partOne(){
    char str[STR_LEN];
    int r;

    FILE* fp = fopen(FILE_NAME, "r");
    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    r = 0;
    fgets(str,STR_LEN,fp);
    while(!feof(fp)){
        for(int i = 0; i < COL; i++){
            m[r][i] = str[i];
            if(m[r][i] == 'S'){
                rowS = r;
                colS = i;
            }else if(m[r][i] == 'E'){
                rowE = r;
                colE = i;
            }
        }
        r++;

        fgets(str,STR_LEN,fp);
    }

    fclose(fp);





    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }


    return 0;
}


int main(){
    return partOne();
}