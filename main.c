#include <stdio.h>
#include "LinkedLists/sll.h"
#include "BinaryTree/bst.h"
#include "Arrays/MultiDimensionalArrays.h"
#include "Arrays/arrays.h"
#include "K&R/k&rmain.h"
#include <string.h>

void reverseEntireString(char* str);
void reverseCharacters(char *str, size_t leftIndex, size_t rightIndex);

int main(int argc, char* argv[]) {

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

    //krMain(argc,argv);

    //###########################3
    //String reverse in range


    const char* cstr = "revetahw";
    const char* toReversed = "desrever";
    char* mystr = malloc(sizeof(int)*strlen(toReversed));

    char str2[] = "Because this is my united states of ";
    char* outstr;

    //Whole String reverse
    printf("Whole string reverse:\n");

    printf("original cstr: %s\n",toReversed);

    strcpy(mystr,toReversed);

    printf("copy of cstr string mystr: %s\n",toReversed);

    reverseEntireString(mystr);

    printf("mystr string reversed: %s\n\n",mystr);

    printf("mystr pointer: %p, cstr pointer: %p\n",mystr,toReversed);

    //free malloc'd string
    free(mystr);


    //##############################
    // Testing reversing in range

    printf("original String: \"%s\"\n",str2);

    outstr = strcat(str2,cstr);
    size_t endIndex = strlen(outstr) - 1;
    reverseCharacters(outstr,36,endIndex);

    printf("outstr concat with last word reversed at index 36-%lu \"%s\"\n",endIndex,outstr);

    //Other bits
    funWithPointers();

    return 0;
}

void reverseCharacters(char *str, size_t lower, size_t upper) {

    char temp;

    while (lower < upper) {
        temp = str[lower];
        str[lower] = str[upper];
        str[upper] = temp;
        lower++;
        upper--;
    }
}

void reverseEntireString(char* str) {

    size_t count = strlen(str);
    size_t lower = 0;
    size_t upper = count-1;

    reverseCharacters(str,lower,upper);

};

