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