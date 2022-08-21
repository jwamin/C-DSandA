#include <stdio.h>
#include "DataStructures/LinkedLists/sll.h"
#include "DataStructures/BinaryTree/bst.h"
#include "function-pointers/function-pointers.h"
#include "cake-thief/cake-thief.h"
#include <helpers.h>
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

    float lower = min(0.2f,2);
    float upper = max(0.2f,2);
    printf("%.2f %.2f\n",lower, upper);
    printf("%d %d\n",(int)lower, (int)upper);
    fPointerRoutine();
    cakeThiefDriver();

    return 0;
}
