#include <stdio.h>
#include "DataStructures/LinkedLists/sll.h"
#include "DataStructures/BinaryTree/bst.h"
#include "fPointer/fpointer.h"
#include "cake-thief/cake-thief.h"

int main() {

    printf("Hello, World!\n");

//    int* valueFromHeap;
//    SLLNode* newnode;
//
//    newnode = demo();
//    valueFromHeap = newnode->value;
//    printf("value from heap is: %d\n",*valueFromHeap);
//    free(newnode);
//
//    sllDemo();
//    printf("\ntrees:\n");
//    treeDemo();

    fPointerRoutine();
    cakeThiefDriver();

    return 0;
}
