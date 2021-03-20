#include <stdio.h>
#include "LinkedLists/sll.h"
#include "BinaryTree/bst.h"
#include "Arrays/MultiDimensionalArrays.h"
#include "Arrays/arrays.h"
#include "K&R/k&rmain.h"

int main(int argc, char** argv) {

    printf("Hello, World!\n");

    int* valueFromHeap;
    SLLNode* newnode;

    newnode = demo();
    valueFromHeap = newnode->value;
    printf("value from heap is: %d\n",*valueFromHeap);
    free(newnode);

    sllDemo();
    printf("\ntrees:\n");
    treeDemo();

    /*
     * Arrays
     */

    int y = 6;
    int x = 12;

    void* myArray = multiDimensionalArrayOfLength(y,x);
    int (*yArray)[y] = myArray;
    yArray[3][2] = 2;
    printMultiDimensionalArray(y,x,myArray);
    free(myArray);

    arrays();

    krMain(argc,argv);

    return 0;
}
