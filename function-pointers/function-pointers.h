//
// Created by Joss Manger on 8/10/22.
//

#ifndef DSANDA_FUNCTION_POINTERS_H
#define DSANDA_FUNCTION_POINTERS_H

typedef int(Hello)(void* fPointer);
typedef int(IntSorter)(int left, int right);
typedef int(CharSorter)(unsigned char left, unsigned char right);
typedef struct FPointer {
    int id;
    Hello *hello;
} FPointer;

void fPointerRoutine();

#endif //DSANDA_FUNCTION_POINTERS_H
