#include <stdio.h>
#include <string.h>
#include <string.h>

#define FILE_NAME "2022/day08/input.txt"
#define DIM 300
#define STR_LEN 300

int countVisibleTreesFromLeft(int m[][DIM], int counted[][DIM], int r, int dim){
    int max = -1, count = 0;

    for(int i = 0; i < dim; i++){
        if(m[r][i] > max){
            max = m[r][i];
            if(!counted[r][i]){
                counted[r][i] = 1;
                count++;
            }
        }
    }

    return count;
}
int countVisibleTreesFromRight(int m[][DIM], int counted[][DIM], int r, int dim){
    int max = -1, count = 0;

    for(int i = dim-1; i >= 0; i--){
        if(m[r][i] > max){
            max = m[r][i];
            if(!counted[r][i]){
                counted[r][i] = 1;
                count++;
            }
        }
    }

    return count;
}
int countVisibleTreesFromTop(int m[][DIM], int counted[][DIM], int c, int dim){
    int max = -1, count = 0;

    for(int i = 0; i < dim; i++){
        if(m[i][c] > max) {
            max = m[i][c];
            if (!counted[i][c]) {
                counted[i][c] = 1;
                count++;
            }
        }
    }

    return count;
}
int countVisibleTreesFromBottom(int m[][DIM], int counted[][DIM], int c, int dim){
    int max = -1, count = 0;

    for(int i = dim-1; i > 0; i--){
        if(m[i][c] > max){
            max = m[i][c];
            if(!counted[i][c]){
                counted[i][c] = 1;
                count++;
            }
        }
    }

    return count;
}

int countVisibleTreesFromLeftWithStartingPoint(int m[][DIM], int r, int dim, int cInit){
    if(cInit == dim-1)
        return 0;

    int count = 1;

    while(m[r][cInit+count] < m[r][cInit] && cInit+count < dim){
        count++;
    }


    if(cInit+count == dim)
        count--;

    return count;
}
int countVisibleTreesFromRightWithStartingPoint(int m[][DIM], int r, int dim, int cInit){
    if(cInit == 0)
        return 0;

    int count = 1;

    while(m[r][cInit-count] < m[r][cInit] && cInit-count >= 0){
        count++;
    }


    if(cInit-count == -1)
        count--;

    return count;
}
int countVisibleTreesFromTopWithStartingPoint(int m[][DIM], int c, int dim, int rInit){
    if(rInit == dim-1)
        return 0;

    int count = 1;

    while(m[rInit+count][c] < m[rInit][c] && rInit+count < dim){
        count++;
    }

    if(rInit+count == dim)
        count--;

    return count;
}
int countVisibleTreesFromBottomWithStartingPoint(int m[][DIM], int c, int dim, int rInit){
    if(rInit == 0)
        return 0;

    int count = 1;

    while(m[rInit-count][c] < m[rInit][c] && rInit-count >= 0){
        count++;
    }


    if(rInit-count == -1)
        count--;

    return count;
}

int partOne(){
    int m[DIM][DIM];
    int counted[DIM][DIM];
    char str[STR_LEN];
    int r = 0;
    int dim;

    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            counted[i][j] = 0;


    FILE* fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fscanf(fp, " %s", str);
    dim = strlen(str);

    while(!feof(fp)){
        for(int i = 0; i < dim; i++)
            m[r][i] = str[i] - '0';
        r++;
        fscanf(fp, " %s", str);
    }


    int count = 0;

    for(int i = 0; i < dim; i++){
        count += countVisibleTreesFromBottom(m,counted,i,dim);
        count += countVisibleTreesFromLeft(m,counted,i,dim);
        count += countVisibleTreesFromTop(m,counted,i,dim);
        count += countVisibleTreesFromRight(m,counted,i,dim);
    }

    printf("Visible trees: %4d\n", count);

    return 0;
}

int partTwo(){
    int m[DIM][DIM];
    int counted[DIM][DIM];
    char str[STR_LEN];
    int r = 0;
    int dim, currScore, maxScore;

    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            counted[i][j] = 0;


    FILE* fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fscanf(fp, " %s", str);
    dim = strlen(str);

    while(!feof(fp)){
        for(int i = 0; i < dim; i++)
            m[r][i] = str[i] - '0';
        r++;
        fscanf(fp, " %s", str);
    }

    maxScore = 0;

    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++) {
            currScore = countVisibleTreesFromRightWithStartingPoint(m,i,dim,j) *
                        countVisibleTreesFromLeftWithStartingPoint(m,i,dim,j) *
                        countVisibleTreesFromTopWithStartingPoint(m,j,dim,i) *
                        countVisibleTreesFromBottomWithStartingPoint(m,j,dim,i);

            if(currScore > maxScore)
                maxScore = currScore;
        }
    }

    printf("Max Score: %d\n", maxScore);


    return 0;
}


int main(){
    return partTwo();
}