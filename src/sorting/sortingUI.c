#include <stdio.h>

#include "sorting/sortingUI.h"

#include "colors.h"
#include "utils.h"
#include "doublyLinkedList.h"

/*==========================================================
                Algorithm Title
==========================================================*/

void printAlgorithmTitle(const char *algorithm){

    printDivider(algorithm);

}

/*==========================================================
                    Pass Number
==========================================================*/

void printPass(int pass){

    printf(COLOR_ACCENT);
    printf("\n");
    printf("=============== PASS %d ===============\n", pass);
    printf(COLOR_RESET);

}

/*==========================================================
                    Step
==========================================================*/

void printStep(const char *message){

    printf(COLOR_TEXT);
    printf("\n%s\n", message);
    printf(COLOR_RESET);

}

/*==========================================================
                    Comparison
==========================================================*/

void printComparison(int first, int second){

    printf(COLOR_NUMBER);

    printf("\nComparing ");

    printf("[%d]", first);

    printf(" and ");

    printf("[%d]\n", second);

    printf(COLOR_RESET);

}

/*==========================================================
                Swap Required
==========================================================*/

void printSwapRequired(void){

    printf(COLOR_ERROR);
    printf("Swap Required!\n");
    printf(COLOR_RESET);

}

/*==========================================================
                No Swap Required
==========================================================*/

void printNoSwap(void){

    printf(COLOR_SUCCESS);
    printf("Already in Correct Order.\n");
    printf(COLOR_RESET);

}

/*==========================================================
                Current List
==========================================================*/

void printCurrentList(struct Node *head){

    printf(COLOR_SUCCESS);

    printf("\nCurrent Linked List\n");

    printf(COLOR_RESET);

    displayList(head);

}