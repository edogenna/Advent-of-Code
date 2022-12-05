#include <stdio.h>

#define FILE_NAME "2022/day2/input.txt"

#define OPPONENT_ROCK 'A'
#define OPPONENT_PAPER 'B'
#define OPPONENT_SCISSORS 'C'

#define MY_ROCK 'X'
#define MY_PAPER 'Y'
#define MY_SCISSORS 'Z'

#define NEED_LOSE 'X'
#define NEED_DRAW 'Y'
#define NEED_WIN 'Z'

#define SCORE_DRAW 3
#define SCORE_WON 6
#define SCORE_LOST 0

#define SCORE_ROCK 1
#define SCORE_PAPER 2
#define SCORE_SCISSORS 3


int scoreFromMyChoice(char myChoice){
    switch (myChoice) {
        case MY_ROCK: return SCORE_ROCK;
        case MY_PAPER: return SCORE_PAPER;
        case MY_SCISSORS: return SCORE_SCISSORS;
        default: return -1;
    }
}

int scoreFromResult(char result){
    switch (result) {
        case NEED_LOSE: return SCORE_LOST;
        case NEED_DRAW: return SCORE_DRAW;
        case NEED_WIN: return SCORE_WON;
        default: return -1;
    }
}


int scoreFromAGame(char myChoice, char opponentChoice){
    //0 == ROCK, 1 == PAPER, 2 = SCISSORS
    const int result[3][3] = {
            {SCORE_DRAW, SCORE_LOST, SCORE_WON}, //0 == ROCK
            {SCORE_WON, SCORE_DRAW, SCORE_LOST}, //1 == PAPER
            {SCORE_LOST,SCORE_WON , SCORE_DRAW}  //2 = SCISSORS
    };

    return result[(int)(myChoice-'X')][(int)(opponentChoice-'A')];
}

char myChoiceFromResult(char needResult, char opponentChoice){
    //0 == ROCK, 1 == PAPER, 2 = SCISSORS
    const int result[3][3] = {
            {MY_SCISSORS,MY_ROCK , MY_PAPER}, //NEED_LOST
            {MY_ROCK, MY_PAPER, MY_SCISSORS},  //NEED_DRAW
            {MY_PAPER, MY_SCISSORS, MY_ROCK} //NEED_WIN
    };

    return result[(int)(needResult-'X')][(int)(opponentChoice-'A')];
}


int partOne(){
    char myChoice, opponenctChoice;
    int myScore = 0;

    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fscanf(fp, " %c %c", &opponenctChoice, &myChoice);
    while(!feof(fp)){
        myScore += (scoreFromAGame(myChoice,opponenctChoice) + scoreFromMyChoice(myChoice));

        fscanf(fp, " %c %c", &opponenctChoice, &myChoice);
    }

    printf("Total score: %d", myScore);
    return 0;
}


int partTwo(){
    char result, opponenctChoice;
    int myScore = 0;

    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fscanf(fp, " %c %c", &opponenctChoice, &result);
    while(!feof(fp)){
        myScore += (scoreFromResult(result) + scoreFromMyChoice(myChoiceFromResult(result,opponenctChoice)));

        fscanf(fp, " %c %c", &opponenctChoice, &result);
    }

    printf("Total score: %d", myScore);
    return 0;

}

int main(){
    return partTwo();
}
