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
    printf("string reverse:\n");
    const char* cstr = "revetahw";
    printf("original cstr: %s\n");

    char* mystr;
    strcpy(mystr,cstr);
    printf("copy of cstr string mystr: %s\n",mystr);
    reverseEntireString(mystr);
    printf("mystr string reversed: %s\n\n",mystr);

    char str2[] = "Because this is my united states of ";
    printf("original String: %s\n",str2);

    char* outstr;
    outstr = strcat(str2,cstr);

    reverseCharacters(outstr,36,strlen(outstr)-1);

    printf("out string concat with last word reversed at index %s\n",outstr);

    funWithPointers();

    return 0;
}

void reverseCharacters(char *str, size_t lower, size_t upper) {

    char tempLchar;
    char tempRchar;

    while (lower < upper) {
        tempLchar = str[lower];
        tempRchar = str[upper];
        str[lower] = tempRchar;
        str[upper] = tempLchar;
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

