#include <stdio.h>
#include "LinkedLists/sll.h"
#include "BinaryTree/bst.h"

int main() {

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

    return 0;
}
