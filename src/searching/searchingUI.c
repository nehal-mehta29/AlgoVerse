#include <stdio.h>

#include "searching/searchingUI.h"

#include "colors.h"
#include "utils.h"

/*==========================================================
                Internal Helper Functions
==========================================================*/

static void printCell(int value, const char *highlightColor){

    printf("%s",highlightColor);

    printf("| %3d ", value);

    printf(COLOR_RESET);

}

/*==========================================================
                Original Array Screen
==========================================================*/

void printOriginalArrayScreen(const int arr[], int size){
    clearScreen();

    printDivider("ORIGINAL ARRAY");

    printf("\n");

    drawArray(arr,
              size,
              -1,
              -1,
              -1,
              -1,
              ARRAY_NORMAL);
}

/*==========================================================
                Sorted Array Screen
==========================================================*/

void printSortedArrayScreen(const int arr[], int size){

    printDivider("SORTED ARRAY");

    printf("\n");

    printf(COLOR_SUCCESS);
    printf("Array Ready for Searching!\n\n");
    printf(COLOR_RESET);

    drawArray(arr,
              size,
              -1,
              -1,
              -1,
              -1,
              ARRAY_NORMAL);
}

/*==========================================================
                Search Header
==========================================================*/

void printSearchHeader(const char *algorithm, int step){

    char title[100];

    snprintf(title,
             sizeof(title),
             "%s - STEP %d",
             algorithm,
             step);

    printDivider(title);
    printf("\n");
}

/*==========================================================
                Array Renderer
==========================================================*/

void drawArray(const int arr[],
               int size,
               int current,
               int secondary,
               int start,
               int end,
               int mode){

    (void)current;
    (void)secondary;
    (void)start;
    (void)end;
    (void)mode;

    int i;

    /*======================================================
                        Index Row
    ======================================================*/

    printf("Index\n\n");

    for(i = 0; i < size; i++){
        printf(" %3d  ", i);
    }

    printf("\n");

    /*======================================================
                        Top Border
    ======================================================*/

    for(i = 0; i < size; i++){
        printf("+-----");
    }

    printf("+\n");

    /*======================================================
                        Array Values
    ======================================================*/

    for(i = 0; i < size; i++){
        if(mode == ARRAY_FOUND && i == current){
            printCell(arr[i], COLOR_ACTIVE);
        }

        else if(mode == ARRAY_COMPARE && (i == current || i == secondary)){
            printCell(arr[i], COLOR_CURRENT);
        }

        else if(mode == ARRAY_DISCARDED && (i < start || i > end)){
            printCell(arr[i], COLOR_PROMPT);
        }

        else{
            printCell(arr[i], COLOR_NUMBER);
        }
    }

    printf("|\n");

    /*======================================================
                        Bottom Border
    ======================================================*/

    for(i = 0; i < size; i++){
        printf("+-----");
    }

    printf("+\n");

    /*======================================================
                        Position Markers
    ======================================================*/

    printf("\n");

    for(i = 0; i < size; i++){

        if(i == current){

            printf(COLOR_CURRENT);
            printf("  ^   ");
            printf(COLOR_RESET);
        }

        else if(i == secondary){

            printf(COLOR_ACCENT);
            printf("  S   ");
            printf(COLOR_RESET);
        }

        else if(i == start){

            printf(COLOR_ACTIVE);
            printf(" ST   ");
            printf(COLOR_RESET);
        }

        else if(i == end){

            printf(COLOR_BREAK);
            printf(" END  ");
            printf(COLOR_RESET);
        }

        else{

            printf("      ");
        }
    }

    printf("\n");

}

/*==========================================================
                Search Information
==========================================================*/

void printSearchComparison(int first,
                     int second,
                     const char *relation){

     printf("\n");

    printf(COLOR_LOGO);
    printf("Comparing ");

    printf(COLOR_CURRENT);
    printf("%d", first);

    printf(COLOR_LOGO);
    printf(" %s ", relation);

    printf(COLOR_CURRENT);
    printf("%d\n", second);

    printf(COLOR_RESET);

}

void printSearchDirection(const char *direction){
    printf("\n");

    printf(COLOR_ACCENT);
    printf("%s\n", direction);

    printf(COLOR_RESET);
}

void printCurrentRange(int start, int end){
    printf("\n");

    printf(COLOR_LOGO);
    printf("Current Search Range\n");

    printf(COLOR_TEXT);
    printf("Start : %d\n", start);
    printf("End   : %d\n", end);

    printf(COLOR_RESET);
}

void printCurrentIndex(int index){
    printf("\n");

    printf(COLOR_LOGO);
    printf("Current Index : ");

    printf(COLOR_CURRENT);
    printf("%d\n", index);

    printf(COLOR_RESET);

}

/*==========================================================
                Final Result
==========================================================*/

void printElementFound(int index){
    printf("\n");

    printf(COLOR_SUCCESS);
    printf("Element Found!\n");

    printf("Index : %d\n", index);

    printf(COLOR_RESET);
}

void printElementNotFound(void){
     printf("\n");

    printf(COLOR_ERROR);
    printf("Element Not Found!\n");

    printf(COLOR_RESET);

}