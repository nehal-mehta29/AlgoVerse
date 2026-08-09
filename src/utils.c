#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "utils.h"
#include "colors.h"

/*==========================================================
                    Clear Screen
==========================================================*/

void clearScreen(void){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*==========================================================
                    Pause Screen
==========================================================*/

void pauseScreen(void){
    printf(COLOR_PROMPT);
    printf("\nPress ENTER to continue...");
    printf(COLOR_RESET);

    while(_getch() != '\r');
}

/*==========================================================
                Print Breadcrumb
==========================================================*/

void printBreadcrumb(const char *path){    
    printf(COLOR_BREADCRUMB);
    printf("%s\n\n", path);
    printf(COLOR_RESET);
}

/*==========================================================
                Print Divider
==========================================================*/

void printDivider(const char *title){
    printf(COLOR_BORDER);

    printf("==================== ");

    printf(COLOR_LOGO);
    printf("%s", title);

    printf(COLOR_BORDER);
    printf(" ====================\n");

    printf(COLOR_RESET);
}

/*==========================================================
                Delay Screen
==========================================================*/

void delayScreen(int milliseconds){

    Sleep(milliseconds);
}