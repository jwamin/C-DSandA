//
// Created by Jwam3 on 19/03/2021.
//

#include "arrays.h"
#include <assert.h>

void intPtr2DArray(void);

void arrays(){

    //check pointer value assignments
    printf("check the action of using a stack into to pass a value to be stored in a heap int*\n");
    int num = 9;
    int* ptr = (int*)malloc(sizeof(int));
    printf("num: %d, num address %p, ptr: %d, ptraddress: %p\n",num,&num,*ptr,ptr);
    *ptr = num;
    printf("num: %d, num address %p, ptr: %d, ptraddress: %p\n",num,&num,*ptr,ptr);
    free(ptr);

    printf("create int ptr array - of length\n");
    int count = 11;
    int (*arr)[count] = malloc(sizeof(int)*count);
    int insertInt;
    for( int i = 0; i<count; i++){
        insertInt = i + 5;
        *arr[i] = insertInt;
    }
    printf("\n");
    for (int i = count-1; i >= 0; i--){
        printf("%d ",*arr[i]);
    }
    printf("\n");

    printf("assert index 5 is 10 %d\n",*arr[5]);
    assert(*arr[5] == 10);

    free(arr);

    intPtr2DArray();

}

void intPtr2DArray(void) {

    printf("will print 2d array: \n\n");

    int dimension = 5;
    int (*twoD)[dimension][dimension] = malloc(sizeof(int[dimension][dimension]));
    int number = 75;
    //assign first value through ptr "decay" does not work
    //*twoD = number;

    //2d loop assign
    for (int o = 0; o < dimension; o++){
        for(int i = 0; i < dimension; i++){
            *twoD[o][i] = 0;
        }
    }

    //create int ptr from array, "decays" to first index
    int *first = (int*)twoD;
    *first = number;

    printf("addr of array:%p, addr of first:%p value: %d\n",twoD,first, *first);
    printf("%lu\n",sizeof(int));
    first += 1;
    *first = 56;

    printf("addr of array:%p, addr of first:%p value: %d\n",twoD,first, *first);
    printf("addr of array[0][1]:%p, value of array[0][1]:%d\n",twoD[0][1],*twoD[0][1]);

    //2d Loop Read
    for (int o = 0; o < dimension; o++){
        for(int i = 0; i < dimension; i++){
            printf("%d ",*twoD[o][i]);
        }
        printf("\n");
    }

}