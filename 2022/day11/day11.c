#include <stdio.h>
#include <stdlib.h>


#define DIM_STACK 50
#define N_MONKEYS 8
#define LCM (11*19*5*2*13*7*3*17)

typedef struct stackArray_{
    unsigned long long int top; //highest position occupied
    unsigned long long int *array;
    unsigned capacity;
}stackArray_t;

stackArray_t *stacks[N_MONKEYS];
unsigned long long int numItems[N_MONKEYS] = {0};


unsigned long long int operation0(unsigned long long int old){
    return old*7;
}
unsigned long long int operation1(unsigned long long int old){
    return old*17;
}
unsigned long long int operation2(unsigned long long int old){
    return old+2;
}
unsigned long long int operation3(unsigned long long int old){
    return old+1;
}
unsigned long long int operation4(unsigned long long int old){
    return old+6;
}
unsigned long long int operation5(unsigned long long int old){
    return old*old;
}
unsigned long long int operation6(unsigned long long int old){
    return old+3;
}
unsigned long long int operation7(unsigned long long int old){
    return old+4;
}

unsigned long long int test0(unsigned long long int new){
    return new%11 == 0 ? 5 : 6;
}
unsigned long long int test1(unsigned long long int new){
    return new%19 == 0 ? 4 : 2;
}
unsigned long long int test2(unsigned long long int new){
    return new%5 == 0 ? 7 : 4;
}
unsigned long long int test3(unsigned long long int new){
    return new%2 == 0 ? 2 : 1;
}
unsigned long long int test4(unsigned long long int new){
    return new%13 == 0 ? 7 : 0;
}
unsigned long long int test5(unsigned long long int new){
    return new%7 == 0 ? 6 : 3;
}
unsigned long long int test6(unsigned long long int new){
    return new%3 == 0 ? 1 : 3;
}
unsigned long long int test7(unsigned long long int new){
    return new%17 == 0 ? 0 : 5;
}

unsigned long long int (*operations[N_MONKEYS]) (unsigned long long int old) = {operation0,operation1,operation2,operation3,operation4,operation5,operation6,operation7};
unsigned long long int (*tests[N_MONKEYS]) (unsigned long long int old) = {test0,test1,test2,test3,test4,test5,test6,test7};


stackArray_t *inizializeStackArray(unsigned capacity){
    stackArray_t *s = malloc(sizeof(stackArray_t));
    if(s == NULL) {
        printf("Malloc Error");
        return NULL;
    }

    s->array = malloc(sizeof(unsigned long long int)*capacity);
    if(s == NULL) {
        printf("Malloc Error");
        return NULL;
    }
    s->capacity = capacity;
    s->top = -1;

    return s;
}
unsigned long long int isStackArFull(stackArray_t *stack)
{
    return stack->top == stack->capacity - 1;
}
unsigned long long int isStackArEmpty(stackArray_t *stack)
{
    return stack->top == -1;
}
void pushStackArray(stackArray_t *stack, unsigned long long int n){
    if(isStackArFull(stack)){
        printf("The stack is full\n");
        return;
    }
    stack->top ++;
    stack->array[stack->top] = n;
}
unsigned long long int popStackArray(stackArray_t *stack){
    if(isStackArEmpty(stack)){
        printf("The stack is empty\n");
        return INT_MIN;
    }

    unsigned long long int n = stack->array[stack->top];
    stack->top --;
    return n;
}



int partOne() {
    int nRounds = 20;

    for(int i = 0; i < nRounds; i++){
        for(int j = 0; j < N_MONKEYS; j++) {
            while (!isStackArEmpty(stacks[j])) {
                unsigned long long int tmp = popStackArray(stacks[j]);
                tmp = operations[j](tmp);
                unsigned long long int dest = tests[j](tmp);
                pushStackArray(stacks[dest], tmp/3);

                numItems[j]++;
            }
        }
    }


    for(int i = 0; i < N_MONKEYS; i++)
        printf("%lld\n", numItems[i]);

    return 0;
}


int partTwo(){
    int nRounds = 10000;

    for(int i = 0; i < nRounds; i++){
        for(int j = 0; j < N_MONKEYS; j++) {
            while (!isStackArEmpty(stacks[j])) {
                unsigned long long int tmp = popStackArray(stacks[j]);
                tmp = operations[j](tmp);
                unsigned long long int dest = tests[j](tmp);
                pushStackArray(stacks[dest], tmp%LCM);

                numItems[j]++;
            }
        }
    }


    for(int i = 0; i < N_MONKEYS; i++)
        printf("%lld\n", numItems[i]);

    return 0;
}


int main(){
    for (int i = 0; i < N_MONKEYS; i++){
        stacks[i] = inizializeStackArray(DIM_STACK);
    }

    pushStackArray(stacks[0], 97);
    pushStackArray(stacks[0], 81);
    pushStackArray(stacks[0], 57);
    pushStackArray(stacks[0], 57);
    pushStackArray(stacks[0], 91);
    pushStackArray(stacks[0], 61);

    pushStackArray(stacks[1], 88);
    pushStackArray(stacks[1], 62);
    pushStackArray(stacks[1], 68);
    pushStackArray(stacks[1], 90);

    pushStackArray(stacks[2], 74);
    pushStackArray(stacks[2], 87);

    pushStackArray(stacks[3], 53);
    pushStackArray(stacks[3], 81);
    pushStackArray(stacks[3], 60);
    pushStackArray(stacks[3], 87);
    pushStackArray(stacks[3], 90);
    pushStackArray(stacks[3], 99);
    pushStackArray(stacks[3], 75);

    pushStackArray(stacks[4], 57);

    pushStackArray(stacks[5], 54);
    pushStackArray(stacks[5], 84);
    pushStackArray(stacks[5], 91);
    pushStackArray(stacks[5], 55);
    pushStackArray(stacks[5], 59);
    pushStackArray(stacks[5], 72);
    pushStackArray(stacks[5], 75);
    pushStackArray(stacks[5], 70);

    pushStackArray(stacks[6], 95);
    pushStackArray(stacks[6], 79);
    pushStackArray(stacks[6], 79);
    pushStackArray(stacks[6], 68);
    pushStackArray(stacks[6], 78);

    pushStackArray(stacks[7], 61);
    pushStackArray(stacks[7], 97);
    pushStackArray(stacks[7], 67);
    
    
    return partOne();
}