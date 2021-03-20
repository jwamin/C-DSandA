//
// Created by Jwam3 on 19/03/2021.
//
#include <stdio.h>
#include "k&rmain.h"

#define MIN 0
#define MAX 300
#define STEP 10

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

}