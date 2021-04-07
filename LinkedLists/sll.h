//
// Created by Joss Manger on 1/24/21.
//

#ifndef DSANDA_SLL_H
#define DSANDA_SLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNode{
    void* value;
    struct SLLNode* next;
} SLLNode;

typedef enum TypeEnum {
    one = 0,
    two = 1,
    three = 2
} TypeEnum;

struct SLLNode* newNodeWithSize(size_t size);

struct SLLNode* demo();

void sllDemo(void);

struct SLLNode* reverseListInPlace(struct SLLNode** start);

#endif //DSANDA_SLL_H
