//
// Created by Joss Manger on 9/21/22.
//

#include "array-merge.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char mergeIntArray(int **outArray, int *outArrayLength, int *inArray1, const int *inArray1Length, int *inArray2,
                            const int *inArray2Length) {

    int count1 = 0, count2 = 0;
    *outArrayLength = *inArray1Length + *inArray2Length;
    int* out = (int*) malloc((sizeof(int) * *outArrayLength));
    int* returnAddr = out;
    while(count1 < *inArray1Length || count2 < *inArray2Length){

        if(*inArray1 < *inArray2 && count1 < *inArray1Length) {
            *out++ = *inArray1++;
            count1++;
        } else if (count2 < *inArray2Length) {
            *out++ = *inArray2++;
            count2++;
        }

    }
    *outArray = returnAddr;
    return EXIT_SUCCESS;
}

void test() {

    int hello[] = {0,1,3};
    int world[] = {2,4,6,7};
    int helloCount = 3;
    int worldCount = 4;

    int* out = NULL;
    int outCount = 0;

    mergeIntArray(&out,&outCount,hello,&helloCount,world,&worldCount);

    for (int i = 0; i < helloCount+worldCount; ++i) {
        printf("%d ",*&out[i]);
    }
    printf("\n");

}
