//
// Created by Joss Manger on 8/14/22.
//

#include "cake-thief.h"
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

/*
 * Keep a running tally of max sizes
 * [0] : 0
 * [1] : 0
 * [2] : 2 - 15
 * [3] : 3 - 90
 * [4] : 3 - 90
 * [5] : 3 - 90 + 2 - 15 = 105 etc
...
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

//"Super secret cake definition"
typedef struct Cake {
    unsigned int weight;
    unsigned int value;
} Cake;

unsigned int maxValue(size_t duffelBagCapacity, const Cake* cakes, size_t cakeSize) {

    //will store partial results
    unsigned int maxValues[duffelBagCapacity];
    Cake* currentCake = cakes;
    unsigned int localMaxValue, remainderIndex, currentValue;

    //verify cakes
    for (int i = 0; i < cakeSize; ++i) {
        if (currentCake->weight == 0 && currentCake->value > 0) {
            return UINT_MAX;
        }
        currentCake++;
    }

    currentCake = cakes;

    for (int i = 0; i <= duffelBagCapacity; ++i) {
        localMaxValue = 0;
        for (int j = 0; j < cakeSize; ++j) {
            if (currentCake->value == 0) {
                localMaxValue = MAX(localMaxValue, 0);
                continue;
            }
            if (currentCake->weight <= i) {
                remainderIndex = i - currentCake->weight;
                currentValue = currentCake->value + maxValues[remainderIndex];
                localMaxValue = MAX(localMaxValue, currentValue);
            }
            currentCake++;
        }
        currentCake = cakes;
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

    const Cake cakes2[] = {
            {7, 160},
            {3, 90},
            {2, 15},
            {0,0},
            {0,500}
    };

    size_t size = sizeof cakes / sizeof(Cake);

    size_t capacity = 20;

    unsigned int maxValueOfTheft = maxValue(capacity,&cakes[0],size);
    unsigned int expected = 555;

    printf("max value of theft with duffelbag of capacity %d is %d, expected: %d\n",(int)capacity, maxValueOfTheft, expected);

    assert(maxValueOfTheft == expected);

    //second example, capacity of bag is zero
    capacity = 0;
    expected = 0;

    maxValueOfTheft = maxValue(capacity,&cakes[0],size);

    assert(maxValueOfTheft == expected);

    printf("max value of theft with duffelbag of capacity %d is %d, expected: %d\n",(int)capacity, maxValueOfTheft, expected);

    //third example, value of weightless cake
    size = sizeof cakes2 / sizeof(Cake);
    capacity = 20;
    expected = UINT_MAX;

    maxValueOfTheft = maxValue(capacity,&cakes2[0],size);

    assert(maxValueOfTheft == expected);

    printf("max value of theft with duffelbag of capacity %d is %d, expected: %d\n",(int)capacity, maxValueOfTheft, expected);


}
