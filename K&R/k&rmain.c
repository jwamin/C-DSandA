//
// Created by Jwam3 on 19/03/2021.
//
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "k&rmain.h"

#define MIN 0
#define MAX 300
#define STEP 10

int nextChar(int* c){
    return (*c = getchar()) != EOF;
}

//accept formatted string arguments, but insert newline at the end.
void println(const char *format, ...){

    va_list ap;
    int percentEncoded = 0;
    int currentIndex = 0;
    char c = format[currentIndex];
    int in = 0;
    while (c != EOF){

        //we encountered a percent character, this might be a format specifier
        if (c == '%'){
            in = 1;
            percentEncoded++;
        }

        //the current character was a % character
        if (in == 1){
            c = format[currentIndex+1];
            switch(c){
                case 'p':
                    break;
                default:
                    break;
            }

        }

        currentIndex++;
        c = format[currentIndex];
    }
    printf("%d\n",percentEncoded);
    // to implement this, need to work out the varadic argument count
    //essentialy count the format string for incidences of %
    //then use that to unpack the args

    va_start(ap, percentEncoded); /* Requires the last fixed parameter (to get the address) */
    for (int j = 0; j < percentEncoded; j++) {
        va_arg(ap, int); /* Increments ap to the next argument. */
    }
    va_end(ap);

    vprintf("%s\n",ap);
}

void krMain(int argc, char** argv){

    printf("hello, world\nWelcome to K&R\n\n");

    printf("Fahrenheit to Celsius\n\n");

    const float fRatio = 5.0 / 9.0;
    float current;
    float cTest;
    //C = (5/9) * (F-32)
    //F = (C / (5/9)) + 32

    printf("°F  °C\n");
    for(int i = MIN; i <= MAX; i+=STEP){
        current = fRatio * (i - 32);
        printf("%3.0d %3.2f\n",i,current);

        cTest = (current / fRatio) + 32;
        //printf("°C reconverted %3.0f\n",cTest);
    }


    printf("Character input\n\n");

    int *c = malloc(sizeof(int));
    int matches = nextChar(c);
    while (matches){
        printf("matches: %d\n",matches);
        printf("%c\n",*c);
        matches = nextChar(c);
        //short circuit quit
        /*
        *c = EOF;
        matches = 0
         */
    }
    printf("eof: %d\n",*c);

}

void funWithPointers() {

    int stackNumber = 7;
    int* myintPtr = malloc(sizeof(int));
    int** pointerPointer;

    *myintPtr = stackNumber * 5;

    pointerPointer = &myintPtr;

    printf("fun with int pointer: %d\n",stackNumber);
    printf("fun with int pointer: %d\n",**pointerPointer);

    free(myintPtr);

}
