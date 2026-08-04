#include <stdio.h>
#include <string.h>

#include "sorting/sortingUI.h"

#include "colors.h"
#include "utils.h"
#include "doublyLinkedList.h"

/*==========================================================
                Internal Helper Functions
==========================================================*/

static void printArrow(const char *arrow,
                       const char *color){

    printf("%s", color);
    printf("%s", arrow);
    printf(COLOR_RESET);

}


/*==========================================================
                    Original List
==========================================================*/

void printOriginalListScreen(struct Node *head){

    printf("\n");
    
    printDivider("ORIGINAL LIST");

    printf("\n");

    displayList(head);

}

/*==========================================================
                    Sorted List
==========================================================*/

void printSortedListScreen(struct Node *head){

    printDivider("SORTED LIST");

    printf("\n");

    printf(COLOR_SUCCESS);
    printf("Sorting Completed Successfully!\n\n");
    printf(COLOR_RESET);

    displayList(head);

}

/*==========================================================
                    Pass Header
==========================================================*/

void printPassHeader(const char *algorithm, int pass){

    char title[100];

    snprintf(title,
         sizeof(title),
         "%s - PASS %d",
         algorithm,
         pass);

    printDivider(title);

    printBreadcrumb("Home > Sorting Algorithms > Visualization");

}

/*==========================================================
                Visualization Header
==========================================================*/

void printVisualizationHeader(const char *title){

    printDivider(title);

}

/*==========================================================
                    Comparison
==========================================================*/

void printComparison(int first, int second){

    printf("\n");

    printf(COLOR_LOGO);
    printf("Comparing ");

    printf(COLOR_CURRENT);
    printf("%d", first);

    printf(COLOR_LOGO);
    printf(" and ");

    printf(COLOR_CURRENT);
    printf("%d\n\n", second);

    printf(COLOR_RESET);

}

/*==========================================================
                    Swap Required
==========================================================*/

void printSwapRequired(void){

    printf(COLOR_ACCENT);
    printf("Swap Required\n\n");
    printf(COLOR_RESET);

}

/*==========================================================
                    No Swap
==========================================================*/

void printNoSwap(void){

    printf(COLOR_SUCCESS);
    printf("Already in Correct Order\n\n");
    printf(COLOR_RESET);

}

/*==========================================================
                    Step
==========================================================*/

void printStep(int step, int totalSteps){

    printf("\n");

    printf(COLOR_TEXT);
    printf("Step : %d of %d\n", step, totalSteps);

    printf(COLOR_RESET);

}

/*==========================================================
                Linked List Renderer
==========================================================*/

void drawList(struct Node *head,
              struct Node *first,
              struct Node *second,
              int mode){

    struct Node *current = head;

    printf(COLOR_LOGO);
    printf("\nHEAD\n");
    printf(" |\n");
    printf(" v\n");
    printf(COLOR_RESET);

    printf(COLOR_TEXT);
    printf("NULL ");
    printf(COLOR_RESET);

    while(current != NULL){

        printArrow("<-->", COLOR_TEXT);
        printf(" ");

        if(mode == LIST_COMPARE &&
            (current == first || current == second)){

                printf(COLOR_CURRENT);
                printf("[%d]", current->data);
                printf(COLOR_RESET);
        }

        else if(mode == LIST_SORTED){

            printf(COLOR_SORTED);
            printf("[%d]", current->data);
            printf(COLOR_RESET);
        }

        else{

            printf(COLOR_NUMBER);
            printf("[%d]", current->data);
            printf(COLOR_RESET);
        }

        printf(" ");

        current = current->next;
    }
    printArrow("<-->", COLOR_TEXT);

    printf(" ");

    printf(COLOR_TEXT);
    printf("NULL\n");
    printf(COLOR_RESET);

}

/*==========================================================
                Sorting Completed
==========================================================*/

void printSortingCompleted(void){

    printf("\n");

    printf(COLOR_SUCCESS);
    printf("Sorting Completed Successfully!\n");

    printf(COLOR_RESET);

}