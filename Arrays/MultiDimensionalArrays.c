//
// Created by Jwam3 on 18/03/2021.
//

#include "MultiDimensionalArrays.h"

void* multiDimensionalArrayOfLength(int y,int x) {
    int *p = (int*)malloc(sizeof(int[23]));
    int (*yArray)[y] = malloc(sizeof(int[x][y]));
    for (int i = 0; i < y; i++){
        for (int z = 0; z < x; z++) {
            yArray[i][z] = 1;
            printf("(%d,%d)=%d ",i,z,yArray[i][z]);
        }
        printf("\n");
    }
    p[12] = 2;
    for (int i = 0; i < 23; i++){
        printf("index %d = %d,",i,p[i]);
    }
    free(p);
    return yArray;
}

void printMultiDimensionalArray(int y, int x, void* array[]) {
    printf("printing:\n");
    int (*intArray)[y] = array;
    for (int o = 0; o < y; o++){
        for (int i = 0; i < x; i++){
            printf("%d",intArray[o][i]);
        }
        printf("\n");
    }
}

