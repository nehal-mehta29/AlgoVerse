#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "searching/jump.h"
#include "searching/searchSort.h"
#include "searching/searchingUI.h"

#include "dataSet.h"
#include "utils.h"
#include "colors.h"

static int step = 1;

/*==========================================================
                    Jump Search Page
==========================================================*/

void jumpPage(void){

    step = 1;

    const int *data;
    int *arr;
    int size;
    int key;
    int index;

    clearScreen();

    printBreadcrumb("Home > Searching Algorithms > Jump Search");

    printDivider("Jump Search");

    data = getDataset();
    size = getDatasetSize();

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL){

        printf(COLOR_ERROR);
        printf("\nMemory Allocation Failed!\n");
        printf(COLOR_RESET);

        return;
    }

    /*======================================================
                    Copy Dataset
    ======================================================*/

    for(int i = 0; i < size; i++){
        arr[i] = data[i];
    }

    /*======================================================
                    Sort Dataset
    ======================================================*/

    if(!isSortedArray(arr, size)){

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

    printSortedArrayScreen(arr, size);

    pauseScreen();

    printf(COLOR_INPUT);
    printf("\nEnter Element to Search : ");
    printf(COLOR_RESET);

    scanf("%d", &key);

    printf("\n");

    index = jumpSearch(arr,
                       size,
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
}

/*==========================================================
                    Jump Search
==========================================================*/

int jumpSearch(int arr[],
               int size,
               int key){

    int stepSize = (int)sqrt(size);

    int prev = 0;
    int next = stepSize;

    /*======================================================
                    Jump Phase
    ======================================================*/

    while(prev < size && arr[(next < size ? next : size) - 1] < key){

        printSearchHeader("Jump Search",
                          step++);

        drawArray(arr,
                  size,
                  (next < size ? next : size) - 1,
                  -1,
                  prev,
                  (next < size ? next : size) - 1,
                  ARRAY_COMPARE);

        printCurrentRange(prev,
                          (next < size ? next : size) - 1);

        printSearchComparison(arr[(next < size ? next : size) - 1],
                              key,
                              "<");

        printSearchDirection("Jumping Forward...");

        pauseScreen();

        printf("\n");
        printf("\n");

        prev = next;
        next += stepSize;

        if(prev >= size){
            printElementNotFound();
            return -1;
        }
    }

    /*======================================================
                    Final Jump Check
    ======================================================*/

    int blockEnd = (next < size ? next : size) - 1;

    printSearchHeader("Jump Search",
                    step++);

    drawArray(arr,
            size,
            blockEnd,
            -1,
            prev,
            blockEnd,
            ARRAY_COMPARE);

    printCurrentRange(prev,
                    blockEnd);

    if(arr[blockEnd] == key){

        printSearchComparison(arr[blockEnd],
                            key,
                            "==");

        drawArray(arr,
                size,
                blockEnd,
                -1,
                prev,
                blockEnd,
                ARRAY_FOUND);

        printElementFound(blockEnd);

        return blockEnd;
    }

    else if(arr[blockEnd] > key){

        printSearchComparison(arr[blockEnd],
                            key,
                            ">");

        printSearchDirection("Correct Block Found.");

        pauseScreen();

        printf("\n");   
    }

    /*======================================================
                    Linear Search Phase
    ======================================================*/

    while(prev < blockEnd){

        printSearchHeader("Jump Search",
                          step++);

        drawArray(arr,
                  size,
                  prev,
                  -1,
                  prev,
                  (next < size ? next : size) - 1,
                  ARRAY_COMPARE);

        printCurrentIndex(prev);

        printSearchComparison(arr[prev],
                              key,
                              (arr[prev] == key) ? "==" : "!=");

        if(arr[prev] == key){

            drawArray(arr,
                      size,
                      prev,
                      -1,
                      prev,
                      (next < size ? next : size) - 1,
                      ARRAY_FOUND);

            printElementFound(prev);

            return prev;
        }

        printSearchDirection("Checking Next Element...");

        pauseScreen();

        printf("\n");

        prev++;
    }

    printElementNotFound();

    return -1;
}