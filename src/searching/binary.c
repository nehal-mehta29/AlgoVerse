#include <stdio.h>
#include <stdlib.h>

#include "searching/searchSort.h"
#include "searching/binary.h"
#include "searching/searchingUI.h"

#include "utils.h"
#include "colors.h"
#include "dataSet.h"

static int step = 1;

/*==========================================================
                    Binary Search Page
==========================================================*/

void binaryPage(void){
    step = 1;

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

        printOriginalArrayScreen(arr, size);

        pauseScreen();

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

    printSortedArrayScreen(arr, size);

    pauseScreen();

    printf(COLOR_INPUT);
    printf("\nEnter Element to Search : ");
    printf(COLOR_RESET);

    scanf("%d", &key);

    int index;

    index = binarySearch(arr, 0, size - 1, key);

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
}

/*==========================================================
                Recursive Binary Search
==========================================================*/

int binarySearch(int arr[], int low, int high, int key){

    if(low > high){
        return -1;
    }

    int mid = (low + high) / 2;

    /*======================================================
                        Current Step
    ======================================================*/

    printf("\n");

    printSearchHeader("Binary Search", step++);

    drawArray(arr,
            high + 1,
            mid,
            -1,
            low,
            high,
            ARRAY_COMPARE);

    printCurrentRange(low, high);

    printCurrentIndex(mid);

    /*======================================================
                        Comparison
    ======================================================*/

    if(arr[mid] == key){

        printSearchComparison(arr[mid], key, "==");

        delayScreen(800);

        printf("\n");

        drawArray(arr,
                high + 1,
                mid,
                -1,
                low,
                high,
                ARRAY_FOUND);

        printElementFound(mid);

        return mid;
    }

    else if(arr[mid] < key){

        printSearchComparison(arr[mid], key, "<");

        printSearchDirection("Searching Right Half...");

        delayScreen(800);

        return binarySearch(arr, mid + 1, high, key);
    }

    else{

        printSearchComparison(arr[mid], key, ">");

        printSearchDirection("Searching Left Half...");

        delayScreen(800);

        return binarySearch(arr, low, mid - 1, key);
    }
}