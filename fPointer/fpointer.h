//
// Created by Joss Manger on 8/10/22.
//

#ifndef DSANDA_FPOINTER_H
#define DSANDA_FPOINTER_H

typedef int(Hello)(void* fPointer);

typedef struct FPointer {
    int id;
    Hello *hello;
} FPointer;

void fPointerRoutine();

#endif //DSANDA_FPOINTER_H
