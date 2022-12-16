#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "2022/day09/input.txt"
#define DIM 3000
#define STR_LEN 30
#define STARTING_POINT (DIM/2)
#define N_NODE 10

int matr[DIM][DIM];
int tailRow, tailCol, headRow, headCol;
//head is in pos 0
int posRow[N_NODE], posCol[N_NODE];


int isTailNearHead(){
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if((headRow + i) == (tailRow) && (headCol + j) == (tailCol))
                return 1;

    return 0;
}
int isNodeNearThePrevious(int node){
    if(node == 0){
        printf("You are checking the head!\n");
        return 1;
    }

    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if(((posRow[node] + i) == posRow[node-1]) && ((posCol[node] + j) == posCol[node-1]))
                return 1;

    return 0;
}
void adjustNodes(){
    for(int i = 1; i < N_NODE; i++){
        if(!isNodeNearThePrevious(i)){
            if(posRow[i-1] > posRow[i]){
                posRow[i]++;
            }else if(posRow[i-1] < posRow[i]){
                posRow[i]--;
            }

            if(posCol[i-1] > posCol[i]){
                posCol[i]++;
            }else if(posCol[i-1] < posCol[i]){
                posCol[i]--;
            }
        }
    }

    if(matr[posRow[N_NODE-1]][posCol[N_NODE-1]] == 0)
        matr[posRow[N_NODE-1]][posCol[N_NODE-1]] = 1;
}

void moveHeadUpLong(){
    if(posRow[0] == 0)
        printf("ERROR HEAD UP\n");

    posRow[0]--;

    adjustNodes();
}
void moveHeadDownLong(){
    if(posRow[0] == DIM-1)
        printf("ERROR HEAD DOWN\n");

    posRow[0]++;

    adjustNodes();
}
void moveHeadLeftLong(){
    if(posCol[0] == 0)
        printf("ERROR HEAD LEFT\n");

    posCol[0]--;

    adjustNodes();
}
void moveHeadRightLong(){
    if(posCol[0] == DIM-1)
        printf("ERROR HEAD RIGHT\n");

    posCol[0]++;

    adjustNodes();
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
        }
        fgets(str,STR_LEN,fp);
    }

    printf("Positions visited by the rope: %d", countPositions());

    return 0;
}

int partTwo(){
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            matr[i][j] = 0;

    for(int i = 0; i < N_NODE; i++){
        posRow[i] = STARTING_POINT;
        posCol[i] = STARTING_POINT;
    }

    matr[posRow[N_NODE-1]][posCol[N_NODE-1]] = 1;

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

        for(int i = 0; i < numMoves; i++){
            switch (direction) {
                case 'U':
                    moveHeadUpLong();
                    break;
                case 'D':
                    moveHeadDownLong();
                    break;
                case 'L':
                    moveHeadLeftLong();
                    break;
                case 'R':
                    moveHeadRightLong();
                    break;
                default:
                    printf("Error direction\n");
            }

        }
        fgets(str,STR_LEN,fp);
    }

    printf("Positions visited by the rope: %d", countPositions());

    return 0;
}

int main(){
    return partTwo();
}