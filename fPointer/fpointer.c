//
// Created by Joss Manger on 8/10/22.
//

#include "fpointer.h"
#include <stdio.h>

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
