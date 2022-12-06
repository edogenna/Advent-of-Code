#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define FILE_NAME "2022/day5/input.txt"
#define STR_LEN 80
#define DIM_STACK 100
#define NUM_STACK 9


typedef struct stackArray_{
    int top; //highest position occupied
    int array[DIM_STACK];
}stackArray_t;


int isStackArFull(stackArray_t *stack)
{
    return stack->top == DIM_STACK - 1;
}

int isStackArEmpty(stackArray_t *stack)
{
    return stack->top == -1;
}

void pushStackArray(stackArray_t *stack, int n){
    if(isStackArFull(stack)){
        printf("The stack is full\n");
        return;
    }
    stack->top ++;
    stack->array[stack->top] = n;
}

int popStackArray(stackArray_t *stack){
    if(isStackArEmpty(stack)){
        printf("The stack is empty\n");
        return INT_MIN;
    }

    int n = stack->array[stack->top];
    stack->top --;
    return n;
}

void reverseStackArray(stackArray_t *stack){
    int tmp;
    for(int i = 0; i <= stack->top/2; i++){
        tmp = stack->array[i];
        stack->array[i] = stack->array[stack->top-i];
        stack->array[stack->top-i] = tmp;
    }
}

void printStackArray(stackArray_t *stack){
    printf("Printing the stack from the bottom: \n");
    for(int i = 0; i <= stack->top; i++)
        printf("%c\n", stack->array[i]);
}

void inseringIntoStacks(char* str, stackArray_t* stacks){
    int i;
    for(i = 0; i < NUM_STACK; i++){
        if('A' <= str[i*4 + 1] && str[i*4 + 1] <= 'Z'){
            pushStackArray(&stacks[i], str[i*4 + 1]);
        }
    }
}

void movingBetweenStacks(char* str, stackArray_t* stacks){
    int count = 0;
    int source = 0;
    int destination = 0;
    int i = 0;

    for(; str[i] != 'f'; i++)
        if('0' <= str[i] && str[i] <= '9')
            count = count * 10 + (str[i] - '0');

    for(; str[i] != 't'; i++)
        if('0' <= str[i] && str[i] <= '9')
            source = source*10 + (str[i] - '0');

    for(; str[i] != '\0'; i++)
        if('0' <= str[i] && str[i] <= '9')
            destination = destination*10 + (str[i] - '0');



    for(i = 0; i < count; i++)
        pushStackArray(&stacks[destination-1], popStackArray(&stacks[source-1]));

}

int partOne(){
    char str[STR_LEN];
    stackArray_t stacks[NUM_STACK];
    for(int i = 0; i < NUM_STACK; i++)
        stacks[i].top = -1;

    int reversed = 0;

    FILE *fp = fopen(FILE_NAME, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        return -1;
    }

    fgets(str, STR_LEN, fp);
    while(!feof(fp)){
        if(str[0] == 'm'){
            if(!reversed) {
                for (int i = 0; i < NUM_STACK; i++)
                    reverseStackArray(&stacks[i]);
                reversed = 1;
            }


            movingBetweenStacks(str, stacks);
        }else{
            inseringIntoStacks(str, stacks);
        }

        fgets(str, STR_LEN, fp);
    }

    for(int i = 0; i < NUM_STACK; i++)
        printf(" %c", stacks[i].array[stacks[i].top]);

    fclose(fp);

    return 0;
}

int partTwo(){
}


int main(){
    return partOne();
}
