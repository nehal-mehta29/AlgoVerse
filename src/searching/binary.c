#include <stdio.h>
#include <stdlib.h>

#include "searching/searchSort.h"
#include "searching/binary.h"

#include "utils.h"
#include "colors.h"
#include "dataSet.h"

/*==========================================================
                    Binary Search Page
==========================================================*/

void binaryPage(void){
    const int *data;
    int *arr;
    int size;
    int key;

    clearScreen();

    printBreadcrumb("Home > Searching Algorithms > Binary Search");

    printDivider("Binary Search");

    data = getDataset();
    size = getDatasetSize();

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL){
        printf(COLOR_ERROR);
        printf("\nMemory Allocation Failed!\n");
        printf(COLOR_RESET);
        return;
    }

    /*==========================================================
                        Copy Dataset
    ==========================================================*/

    for(int i = 0; i < size; i++){
        arr[i] = data[i];
    }

    /*==========================================================
                            Sort Array
    ==========================================================*/

    if(!isSortedArray(arr, size)){

        /*==========================================================
                            Original Array
        ==========================================================*/

        printf(COLOR_SUCCESS);
        printf("\nOriginal Array\n");
        printf(COLOR_RESET);

        for(int i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }

        printf("\n");

        printf(COLOR_SUCCESS);

        printf("\nChecking if array is sorted...\n");

        if(size <= 10){

            printf("\nDataset is not sorted.\n");
            printf("Using Bubble Sort...\n");

            bubbleSortArray(arr, size);
        }

        else{

            printf("\nDataset is not sorted.\n");
            printf("Using Merge Sort...\n");

            mergeSortArray(arr, 0, size - 1);
        }

        printf(COLOR_RESET);
    }

    else{

        printf(COLOR_SUCCESS);
        printf("\nDataset is already sorted.\n");
        printf(COLOR_RESET);
    }

    printf(COLOR_SUCCESS);
    printf("\nSorted Array\n");
    printf(COLOR_RESET);

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf(COLOR_INPUT);
    printf("\nEnter Element to Search : ");
    printf(COLOR_RESET);

    scanf("%d", &key);

    int index;

    index = binarySearch(arr,
                        0,
                        size - 1,
                        key);

    printf("\n");

    if(index != -1){

        printf(COLOR_SUCCESS);
        printf("Element Found at Index %d\n", index);
        printf(COLOR_RESET);
    }

    else{

        printf(COLOR_ERROR);
        printf("Element Not Found\n");
        printf(COLOR_RESET);
    }

    free(arr);

    pauseScreen();
}

/*==========================================================
                Recursive Binary Search
==========================================================*/

int binarySearch(int arr[],
                 int low,
                 int high,
                 int key){

    if(low > high){
        return -1;
    }

    int mid = (low + high) / 2;

    printf("\n----------------------------------------");
    printf("\nLow  = %d", low);
    printf("\nHigh = %d", high);
    printf("\nMid  = %d", mid);
    printf("\nElement at Mid = %d\n", arr[mid]);

    if(arr[mid] == key){

        printf("\n%d == %d\n", arr[mid], key);

        return mid;
    }

    else if(arr[mid] < key){

        printf("\n%d < %d", arr[mid], key);
        printf("\nSearching Right Half...\n");

        return binarySearch(arr,
                            mid + 1,
                            high,
                            key);
    }

    else{

        printf("\n%d > %d", arr[mid], key);
        printf("\nSearching Left Half...\n");

        return binarySearch(arr,
                            low,
                            mid - 1,
                            key);
    }
}