#include <stdio.h>

#include "searching/jump.h"
#include "utils.h"
#include "colors.h"

/*==========================================================
                    Jump Search Page
==========================================================*/

void jumpPage(void){
    clearScreen();

    printBreadcrumb("Home > Searching Algorithms > Jump Search");

    printDivider("Jump Search");

    printf(COLOR_TEXT);
    printf("\n");
    printf("This module is currently under development.\n");
    printf(COLOR_RESET);
}