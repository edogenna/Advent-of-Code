#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "2022/day9/input.txt"
#define DIM 3000
#define STR_LEN 30
#define STARTING_POINT (DIM/2)

int matr[DIM][DIM];
int tailRow, tailCol, headRow, headCol;


int isTailNearHead(){
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if((headRow + i) == (tailRow) && (headCol + j) == (tailCol))
                return 1;

    return 0;
}

void moveHeadUp(){
    if(headRow == 0)
        printf("ERROR HEAD UP\n");

    headRow--;

    if(!isTailNearHead()){
        tailRow = headRow+1;
        tailCol = headCol;
    }

    if(matr[tailRow][tailCol] == 0)
        matr[tailRow][tailCol] = 1;
}
void moveHeadDown(){
    if(headRow == DIM -1)
        printf("ERROR HEAD DOWN\n");

    headRow++;

    if(!isTailNearHead()){
        tailRow = headRow-1;
        tailCol = headCol;
    }

    if(matr[tailRow][tailCol] == 0)
        matr[tailRow][tailCol] = 1;
}
void moveHeadLeft(){
    if(headCol == 0)
        printf("ERROR HEAD LEFT\n");

    headCol--;

    if(!isTailNearHead()){
        tailRow = headRow;
        tailCol = headCol+1;
    }

    if(matr[tailRow][tailCol] == 0)
        matr[tailRow][tailCol] = 1;
}
void moveHeadRight(){
    if(headCol == DIM-1)
        printf("ERROR HEAD RIGHT\n");

    headCol++;

    if(!isTailNearHead()){
        tailRow = headRow;
        tailCol = headCol-1;
    }

    if(matr[tailRow][tailCol] == 0)
        matr[tailRow][tailCol] = 1;
}

int countPositions(){
    int count = 0;
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            if(matr[i][j] == 1)
                count ++;

    return count;
}

void printMatrix(){
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++)
            printf("%d",matr[i][j]);
        printf("\n");
    }
}

int partOne(){
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            matr[i][j] = 0;

    tailRow = tailCol = headRow = headCol = STARTING_POINT;
    matr[tailRow][tailCol] = 1;

    char str[STR_LEN];
    int numMoves;
    char direction;


    FILE* fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fgets(str,STR_LEN,fp);

    while(!feof(fp)){
        direction = str[0];
        numMoves = atoi(str + 2);

        //printf("ho letto;%s\n", str);
        for(int i = 0; i < numMoves; i++){
            switch (direction) {
                case 'U':
                    moveHeadUp();
                    break;
                case 'D':
                    moveHeadDown();
                    break;
                case 'L':
                    moveHeadLeft();
                    break;
                case 'R':
                    moveHeadRight();
                    break;
                default:
                    printf("Error direction\n");
            }

            //printMatrix();
        }


        fgets(str,STR_LEN,fp);
    }

    printf("Positions visited by the rope: %d", countPositions());


    return 0;
}

int main(){
    return partOne();
}