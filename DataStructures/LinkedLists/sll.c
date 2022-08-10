//
// Created by Joss Manger on 1/24/21.
//

#include "sll.h"

struct SLLNode* newNodeWithSize(size_t size) {
    SLLNode* newNode;
    newNode = (SLLNode *)malloc(sizeof(SLLNode)); //allocate on heap
    newNode->value = (int*)malloc(size); //allocate space of size on node "value" property
    return newNode;
}

void freeSinglyLinkedList(struct SLLNode* node){
    SLLNode *next = node->next;
    int* value;
    if (next != NULL){
        printf("going down\n");
        freeSinglyLinkedList(next);
    }
    value = (int*)node->value;
    printf("freeing node %p, with value: %d\n",node, *value);
    free(node);
}

struct SLLNode* demo(){

    ///Declaration of variables
    int assignmentValue = 5; //stack int
    int* nodeValue; //stack in pointer
    size_t sizeOfNode; //stack size uint
    SLLNode* myNode; //stack node pointer

    ///allocate heap addresses, assign to stack ptr
    myNode = newNodeWithSize(sizeof(int));

    //get size of node
    sizeOfNode = sizeof(*myNode);

    //assign stack pointer to location of node Value
    nodeValue = myNode->value;

    // indirection operator
    *nodeValue = assignmentValue * 10;

    //start printing things
    printf("size of node: %lu\n", sizeOfNode);

    //print values and locations of values
    printf("value of stackVar: %d (%p), value of heapVar: %d (%p)\naddr of nodeItem: %p\n",assignmentValue,&assignmentValue,*nodeValue,&nodeValue,myNode->value);

    //ensure value points to heap variable
    nodeValue = (int*)myNode->value;

    //indirection operator assign value of nodevalue (node value), square value
    *nodeValue = *nodeValue * *nodeValue;

    //ensure value points to heap variable
    nodeValue = (int*)myNode->value;

    //print values and location of nodeValue
    printf("value of stackVar: %d (%p)\n",*nodeValue,nodeValue);

    return myNode;
}

void sllDemo(){

    //demo routine
    int* loadingInt;
    SLLNode* current;

    SLLNode* start = newNodeWithSize(sizeof(int));
    SLLNode* second = newNodeWithSize(sizeof(int));
    SLLNode* third = newNodeWithSize(sizeof(int));
    SLLNode* fourth = newNodeWithSize(sizeof(int));
    SLLNode* end = newNodeWithSize(sizeof(int));

    loadingInt = start->value;
    *loadingInt = 5;
    start->next = second;

    loadingInt = second->value;
    *loadingInt = 7;
    second->next = third;

    loadingInt = third->value;
    *loadingInt = 9;
    third->next = fourth;

    loadingInt = fourth->value;
    *loadingInt = 11;
    fourth->next = end;

    loadingInt = end->value;
    *loadingInt = 13;

    current = start;

    for (int i = 0; current != NULL; i++) {
        loadingInt = current->value;
        printf("%d:%d",i,*loadingInt);
        current = current->next;
        if (current){
            printf("->");
        } else {
            printf("\n");
        }
    }

    printf("Will free linked list:\n");
    freeSinglyLinkedList(start);

    printf("...done\n");

}
