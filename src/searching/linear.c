#include <stdio.h>
#include <stdlib.h>

#include "searching/linear.h"
#include "searching/searchingUI.h"

#include "dataSet.h"
#include "utils.h"
#include "colors.h"

static int step = 1;

/*==========================================================
                    Linear Search Page
==========================================================*/

void linearPage(void){
    step = 1;

    const int *data;
    int *arr;
    int size;
    int key;
    int index;

    clearScreen();

    printBreadcrumb("Home > Searching Algorithms > Linear Search");

    printDivider("Linear Search");

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
                Display Original Array
    ======================================================*/

    printOriginalArrayScreen(arr, size);

    pauseScreen();

    printf(COLOR_INPUT);
    printf("\nEnter Element to Search : ");
    printf(COLOR_RESET);

    scanf("%d", &key);

    index = linearSearch(arr,
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
                    Linear Search
==========================================================*/

int linearSearch(int arr[],
                 int size,
                 int key){

    for(int i = 0; i < size; i++){

        printSearchHeader("Linear Search",
                          step++);

        drawArray(arr,
                  size,
                  i,
                  -1,
                  0,
                  size - 1,
                  ARRAY_COMPARE);

        printCurrentIndex(i);

        printSearchComparison(arr[i],
                              key,
                              (arr[i] == key) ? "==" : "!=");

        if(arr[i] == key){

            drawArray(arr,
                      size,
                      i,
                      -1,
                      0,
                      size - 1,
                      ARRAY_FOUND);

            printElementFound(i);

            return i;
        }

        printSearchDirection("Checking Next Element...");

        delayScreen(800);

        printf("\n");
    }

    printElementNotFound();

    return -1;
}