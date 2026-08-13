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
    printf("%d", second);

    printf(COLOR_LOGO);
    printf("  |  ");

    printf(COLOR_POINTER);

    if(first < second)
        printf("%d < %d", first, second);

    else if(first > second)
        printf("%d > %d", first, second);

    else
        printf("%d = %d", first, second);

    printf(COLOR_LOGO);
    printf("  |  ");

    printf(COLOR_RESET);

}

/*==========================================================
                    Swap Required
==========================================================*/

void printSwapRequired(void){

    printf(COLOR_ACCENT);
    printf("Swap Required\n");
    printf(COLOR_RESET);

}

/*==========================================================
                    No Swap
==========================================================*/

void printNoSwap(void){

    printf(COLOR_SUCCESS);
    printf("Already in Correct Order\n");
    printf(COLOR_RESET);

    printf("\n ");

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
              struct Node *breakAfter,
              struct Node *breakBefore,
              int mode){

    (void)breakAfter;

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

        if(mode == LIST_COMPARE &&
            (current == first || current == second)){

                printf(COLOR_CURRENT);
                printf("[%d]", current->data);
                printf(COLOR_RESET);
        }

        else if(mode == LIST_SORTED &&
            (current == first || current == second)){

            printf(COLOR_ACTIVE);
            printf("[%d]", current->data);
            printf(COLOR_RESET);
        }

        else{

            printf(COLOR_NUMBER);
            printf("[%d]", current->data);
            printf(COLOR_RESET);
        }

        printf(" ");

        if(current->next != NULL){
            if(mode == LIST_BREAK &&
                (current == breakAfter || current == breakBefore)){
                printArrow("<--X-->", COLOR_BREAK);
            }
            else if(mode == LIST_RELINK &&
                (current == breakAfter || current == breakBefore)){
                printArrow("<==>", COLOR_ACTIVE);
            }
            else{
                printArrow("<-->", COLOR_TEXT);
            }

            printf(" ");
        }

        current = current->next;
    }

    printf(COLOR_TEXT);
    printf("NULL\n");
    printf(COLOR_RESET);

}

/*==========================================================*
                    Inline List Renderer
*==========================================================*/

void drawListInline(struct Node *head,
                           struct Node *first,
                           struct Node *second,
                           int mode){

    struct Node *current = head;

    printf("NULL ");

    while(current != NULL){

        /* Highlight compared nodes */
        if(mode == LIST_COMPARE &&
           (current == first || current == second)){

            printf(COLOR_CURRENT);
            printf("[%d]", current->data);
            printf(COLOR_RESET);
        }

        /* Highlight sorted nodes */
        else if(mode == LIST_SORTED &&
                (current == first || current == second)){
  
            printf(COLOR_SUCCESS);
            printf("[%d]", current->data);
            printf(COLOR_RESET);
        }

        else{

            printf(COLOR_NUMBER);
            printf("[%d]", current->data);
            printf(COLOR_RESET);
        }

        if(current->next != NULL){

            if(mode == LIST_BREAK &&
               (current == first || current == second)){

                printArrow("<--X-->", COLOR_BREAK);
            }

            else if(mode == LIST_RELINK &&
                    (current == first || current == second)){

                printArrow("<==>", COLOR_ACTIVE);
            }

            else{

                printArrow("<-->", COLOR_TEXT);
            }

            printf(" ");
        }

        current = current->next;
    }

    printf("NULL");
}

/*==========================================================*
                    Swap Visualization
*==========================================================*/

void drawSwapSequence(struct Node *head,
                      struct Node *first,
                      struct Node *second){

    /*======================================================*
                    Break + Relink
    *======================================================*/

    drawListInline(head,
                   first,
                   second,
                   LIST_BREAK);

    printf(COLOR_LOGO);
    printf("  |  ");
    printf(COLOR_RESET);

    drawListInline(head,
                   first,
                   second,
                   LIST_RELINK);

    printf("\n");
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