#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "2022/day10/input.txt"
#define STR_LEN 30
#define OFFSET_CYCLES 40
#define NUM_MEASURES 6


int nextCycleMeasured = 20;
int countMeasures = 0;
int currentCycle = 0;
int registerX = 1;
int signalStrengths = 0;

void verifyCycle(){
    if(currentCycle == nextCycleMeasured){
        signalStrengths += (registerX * currentCycle);
        nextCycleMeasured += OFFSET_CYCLES;
        countMeasures++;
    }
}


int partOne(){
    char str[STR_LEN];

    FILE* fp = fopen(FILE_NAME, "r");
    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fgets(str,STR_LEN,fp);
    while(!feof(fp)){
        if(str[0] == 'n'){ //noop
            currentCycle++;
            verifyCycle();
        }else{ //addx
            currentCycle++;
            verifyCycle();
            currentCycle++;
            verifyCycle();
            registerX += atoi(str+5);
        }

        if(countMeasures == NUM_MEASURES)
            break;

        fgets(str,STR_LEN,fp);
    }

    fclose(fp);

    printf("Value: %d\n", signalStrengths);


    return 0;
}

int main(){
    return partOne();
}