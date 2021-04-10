//
// Created by Jwam3 on 28/03/2021.
//

#include "binSearch.h"
#include <stdio.h>

//[g,h,i,a,b,c,d,e,f]
//       ^
//[d,e,f,g,h,i,a,b,c]
//             ^

int findRotationPoint(const char* array,int length) {

char first = *array;
int lower = 0;
int upper = length - 1;
int mid;

while (lower <= upper) {

    mid = lower + ((upper - lower) / 2);

    if (array[mid]<first) {
        //go left
        printf("going left on %c\n",array[mid]);
        upper = mid;
    } else if (array[mid]>first) {
        //go right
        printf("going right on %c\n",array[mid]);
        lower = mid;
    }

    if (lower + 1 == upper) {
        //we have a convergence
        printf("returning lower: %d, upper: %d, %c\n",lower, upper, array[lower]);
        return upper;
    }

    printf("continuing loop lower: %d, upper: %d, %c\n",lower,upper,array[mid]);

}

return -1;

}

int binSearch(int searchItem, const int* array,int length){

    int lower = 0;
    int upper = length - 1;
    int mid;
    int current;

    while (lower <= upper){

        mid = lower + ((upper - lower) / 2);
        current = array[mid];

        if (current == searchItem){
            return mid;
        }

        if(current < searchItem){ // go right
            lower = mid + 1;
        } else if(current > searchItem) { // go left
            upper = mid - 1;
        }

    }

    return -1;

}