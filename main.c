#include <stdio.h>
#include "LinkedLists/sll.h"
#include "BinaryTree/bst.h"
#include "Arrays/MultiDimensionalArrays.h"
#include "Arrays/arrays.h"
#include "K&R/k&rmain.h"
#include <string.h>
#include "Arrays/binSearch.h"
#include <assert.h>

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

    //Binary Search

    int length = 40;
    int* array = (int*) malloc (sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        array[i] = i+1;
    }

    int result = binSearch(1,array,length);

    printf("binSearchResult: %d\n",result);

    char myTest[] = {'g','h','a','b','c','d','e','f'}; // 2
    char myTest2[] = {'e','f','g','h','i','j','k','a','b','c','d'}; //7
    char myTest3[] = {'c','d','e','f','g','h','i','j','k','l','m','n','a','b'}; //12

    printf("rotation point test1: should be 2, answer: %d\n",findRotationPoint(myTest,8));
    assert(findRotationPoint(myTest,8) == 2);
    printf("rotation point test2: should be 7, answer: %d\n",findRotationPoint(myTest2,11));
    assert(findRotationPoint(myTest2,11) == 7);
    printf("rotation point test3: should be 12, answer: %d\n",findRotationPoint(myTest3,14));
    assert(findRotationPoint(myTest3,14) == 12);

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

