#include <stdio.h>

#include "about.h"
#include "utils.h"
#include "colors.h"

/*==========================================================
                        About Page
==========================================================*/

void aboutPage(void){
    clearScreen();

    printBreadcrumb("Home > About AlgoVerse");

    printDivider("About AlgoVerse");

    printf(COLOR_TEXT);

    printf("\n");
    printf("AlgoVerse is an interactive terminal-based application\n");
    printf("developed in C to help users learn, visualize and\n");
    printf("understand fundamental Data Structures and Algorithms.\n\n");

    printf("The application demonstrates how different sorting and\n");
    printf("searching algorithms work through step-by-step execution,\n");
    printf("allowing users to observe the complete process instead of\n");
    printf("only viewing the final output.\n\n");

    printf("Users can enter their own data, execute algorithms,\n");
    printf("observe intermediate steps, compare results and gain a\n");
    printf("better understanding of algorithmic behaviour.\n\n");

    printf("Modules Available\n");
    printf("-----------------\n");
    printf("# Sorting Algorithms\n");
    printf("    - Bubble Sort\n");
    printf("    - Selection Sort\n");
    printf("    - Insertion Sort\n");
    printf("    - Merge Sort\n");
    printf("    - Quick Sort\n\n");

    printf("# Searching Algorithms\n");
    printf("    - Linear Search\n");
    printf("    - Binary Search\n");
    printf("    - Jump Search\n");
    printf("    - Binary Search Tree\n");
    printf("    - Depth First Search\n");
    printf("    - Breadth First Search\n\n");

    printf("Each module is designed to provide a consistent learning\n");
    printf("experience with clear navigation, structured output and\n");
    printf("an intuitive terminal interface.\n\n");

    printf(COLOR_RESET);

    pauseScreen();
}