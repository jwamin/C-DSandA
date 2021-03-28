//
// Created by Jwam3 on 28/03/2021.
//

#include "binSearch.h"

int binSearch(int searchItem, const int* array,int length){
    int lower = 0;
    int upper = length - 1;
    int mid = -1;
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