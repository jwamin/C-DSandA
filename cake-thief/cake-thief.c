//
// Created by Joss Manger on 8/14/22.
//

#include "cake-thief.h"
#include <stdio.h>
#include <assert.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

//"Super secret cake definition"
typedef struct Cake {
    unsigned int weight;
    unsigned int value;
} Cake;

unsigned int maxValue(size_t duffelBagCapacity, const Cake* cakes, size_t cakeSize) {



    /*
     * Keep a running tally of max sizes
     * [0] : 0
     * [1] : 0
     * [2] : 2 - 15
     * [3] : 3 - 90
     * [4] : 3 - 90
     * [5] : 3 - 90 + 2 - 15 = 105 etc
     * [6] :
     * [7] :
     * [8] :
     * [9] :
     * [10] :
     * [11] :
     * [12] :
     * [13] :
     * [14] :
     * [15] :
     * [16] :
     * [17] :
     * [18] :
     * [19] :
     */

    /* Modification of the "making change" algorithm
     * for index in 0 ..< capacity of duffel bag
     *      store local max value
     *      for index in 0... cakes
     *          if cake weight <= bag capacity
     *              remainder = capacity - cakeWeight;
     *              current = cakeValue + maxValues[remainder]
     *              localMaxvalue = max(localMaxValue, current)
     * maxValues[index] = localMaxValue;
     * return maxValues[count - 1];
     */

    //will store partial results
    unsigned int maxValues[duffelBagCapacity+1];
    unsigned int localMaxValue;
    const Cake* currentCake;
    unsigned int remainderIndex;
    unsigned int currentValue;

    for (int i = 0; i <= duffelBagCapacity; ++i) {
        localMaxValue = 0;
        for (int j = 0; j < cakeSize; ++j) {
            currentCake = &cakes[j];
            if (currentCake->weight <= i) {
                remainderIndex = i - currentCake->weight;
                currentValue = currentCake->value + maxValues[remainderIndex];
                localMaxValue = MAX(localMaxValue, currentValue);
            }
        }
        maxValues[i] = localMaxValue;
    }

    return maxValues[duffelBagCapacity];

}

void cakeThiefDriver(void) {

    const Cake cakes[] = {
            {7, 160},
            {3, 90},
            {2, 15}
    };

    size_t size = sizeof cakes / sizeof(Cake);

    size_t capacity = 20;

    unsigned int maxValueOfTheft = maxValue(capacity,&cakes[0],size);
    unsigned int expected = 555;
    printf("max value of theft with duffelbag of capacity %d is %d, expected: %d\n",(int)capacity, maxValueOfTheft, expected);

}
