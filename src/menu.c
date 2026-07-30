#include <stdio.h>

#include "menu.h"
#include "colors.h"

/*==========================================================
                        Home Menu
==========================================================*/

void homeMenu(void){
    printf(COLOR_BREADCRUMB);
    printf("Home\n");
    printf(COLOR_RESET);

    printf(COLOR_BORDER);
    printf("------------------------------------------------------------\n");
    printf(COLOR_RESET);

    printf(COLOR_NUMBER);
    printf("1. ");

    printf(COLOR_TEXT);
    printf("Sorting Algorithms\n");

    printf(COLOR_NUMBER);
    printf("2. ");

    printf(COLOR_TEXT);
    printf("Searching Algorithms\n");

    printf(COLOR_NUMBER);
    printf("3. ");

    printf(COLOR_TEXT);
    printf("About AlgoVerse\n");

    printf(COLOR_NUMBER);
    printf("0. ");

    printf(COLOR_TEXT);
    printf("Exit\n");

    printf(COLOR_BORDER);
    printf("------------------------------------------------------------\n\n");
    printf(COLOR_RESET);

    printf(COLOR_TEXT);
    printf("Enter Choice : ");
    printf(COLOR_RESET);
}

/*==========================================================
                    Sorting Menu
==========================================================*/

void sortingMenu(void){
    printf(COLOR_BREADCRUMB);
    printf("Home > Sorting Algorithms\n");
    printf(COLOR_RESET);

    printf(COLOR_BORDER);
    printf("------------------------------------------------------------\n");
    printf(COLOR_RESET);

    printf(COLOR_NUMBER);
    printf("1. ");

    printf(COLOR_TEXT);
    printf("Bubble Sort\n");

    printf(COLOR_NUMBER);
    printf("2. ");

    printf(COLOR_TEXT);
    printf("Selection Sort\n");

    printf(COLOR_NUMBER);
    printf("3. ");

    printf(COLOR_TEXT);
    printf("Insertion Sort\n");

    printf(COLOR_NUMBER);
    printf("4. ");

    printf(COLOR_TEXT);
    printf("Merge Sort\n");

    printf(COLOR_NUMBER);
    printf("5. ");

    printf(COLOR_TEXT);
    printf("Quick Sort\n");

    printf(COLOR_NUMBER);
    printf("0. ");

    printf(COLOR_TEXT);
    printf("Back\n");

    printf(COLOR_BORDER);
    printf("------------------------------------------------------------\n\n");
    printf(COLOR_RESET);

    printf(COLOR_TEXT);
    printf("Enter Choice : ");
    printf(COLOR_RESET);
}

/*==========================================================
                    Sorting Menu
==========================================================*/

void searchingMenu(void){
    printf(COLOR_BREADCRUMB);
    printf("Home > Searching Algorithms\n");
    printf(COLOR_RESET);

    printf(COLOR_BORDER);
    printf("------------------------------------------------------------\n");
    printf(COLOR_RESET);

    printf(COLOR_NUMBER);
    printf("1. ");

    printf(COLOR_TEXT);
    printf("Linear Search\n");

    printf(COLOR_NUMBER);
    printf("2. ");

    printf(COLOR_TEXT);
    printf("Binary Search\n");

    printf(COLOR_NUMBER);
    printf("3. ");

    printf(COLOR_TEXT);
    printf("Jump Search\n");

    printf(COLOR_NUMBER);
    printf("4. ");

    printf(COLOR_TEXT);
    printf("Binary Search Tree\n");

    printf(COLOR_NUMBER);
    printf("5. ");

    printf(COLOR_TEXT);
    printf("Depth First Search\n");

    printf(COLOR_NUMBER);
    printf("6. ");

    printf(COLOR_TEXT);
    printf("Breadth First Search\n");

    printf(COLOR_NUMBER);
    printf("0. ");

    printf(COLOR_TEXT);
    printf("Back\n");

    printf(COLOR_BORDER);
    printf("------------------------------------------------------------\n\n");
    printf(COLOR_RESET);

    printf(COLOR_TEXT);
    printf("Enter Choice : ");
    printf(COLOR_RESET);
}