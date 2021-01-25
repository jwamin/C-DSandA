#include <stdio.h>
#include "sll.h"

int main() {

    printf("Hello, World!\n");

    int* valueFromHeap;
    SLLNode* newnode = demo();
    valueFromHeap = newnode->value;
    printf("value from heap is: %d\n",*valueFromHeap);
    free(newnode);

    demo2();

    return 0;
}
