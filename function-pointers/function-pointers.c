//
// Created by Joss Manger on 8/10/22.
//

#include "function-pointers.h"
#include <stdio.h>

//Create a function that accepts a) a collection, b) a length, c) a pointer to sorting function
// typedef of sorting function
//



int hello(void* fPointer){
    FPointer *this = (FPointer*)fPointer;

    printf("this id: %d\n",this->id);

}



void fPointerRoutine() {

    FPointer this;
    this.id = 566;
    FPointer *thisPtr;
    thisPtr = &this;
    this.hello = &hello;


    thisPtr->hello(&this);

}
