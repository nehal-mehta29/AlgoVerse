#include <stdio.h>

#include "sorting/selection.h"
#include "sorting/swap.h"
#include "sorting/sortingUI.h"

#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"
#include "dataSet.h"

#include "cost.h"

/*==========================================================
                    Selection Sort Page
==========================================================*/

void selectionPage(void){

    struct Node *head = NULL;
    struct Node *tail = NULL;

    const int *data;
    int size;

    clearScreen();

    printBreadcrumb("Home > Sorting Algorithms > Selection Sort");

    printDivider("Selection Sort");

    data = getDataset();
    size = getDatasetSize();

    /*======================================================*
                    Create Doubly Linked List
    *======================================================*/

    head = createList(data, size);
    tail = findTail(head);

    /*======================================================*
                            Original List
    *======================================================*/

    printf("\n");

    printOriginalListScreen(head);

    pauseScreen();

    printf("\n");

    /*======================================================*
                        Cost Tracking
    *======================================================*/

    struct Cost cost = {0};

    startCostTimer(&cost);

    selectionSort(&head, &tail, &cost);

    stopCostTimer(&cost);

    /*======================================================*
                        Sorted List
    *======================================================*/

    printf("\n"); 

    printSortedListScreen(head);

    pauseScreen();

    /*======================================================*
                        Cost Calculation
    *======================================================*/

    long theoreticalComparisons = (long)size * (size - 1) / 2;

    long theoreticalSwaps = (long)size - 1;

    displayCostAnalysis(cost,
                        "Selection Sort",
                        size,
                        "n(n-1)/2",
                        theoreticalComparisons,
                        "n-1",
                        theoreticalSwaps,
                        "O(n^2)",
                        "O(n^2)",
                        "O(n^2)",
                        "O(1)");

    freeList(head);
}

/*==========================================================*
                Selection Sort Algorithm
*==========================================================*/

void selectionSort(struct Node **head,
                   struct Node **tail,
                   struct Cost *cost){

    int pass = 1;

    if(*head == NULL || (*head)->next == NULL){
        return;
    }

    struct Node *current = *head;

    while(current != NULL && current->next != NULL){

        struct Node *minNode = current;
        struct Node *scan = current->next;

        /*==================================================*
                            Pass Header
        *==================================================*/

        printf("\n");

        printPassHeader("Selection Sort", pass);

        printf("\n");

        printf(COLOR_LOGO);
        printf("Current Position : ");

        printf(COLOR_CURRENT);
        printf("%d\n", current->data);

        printf(COLOR_RESET);

        delayScreen(800);

        /*==================================================*
                            Find Minimum
        *==================================================*/

        while(scan != NULL){

            drawList(*head,
                     minNode,
                     scan,
                     NULL,
                     NULL,
                     LIST_COMPARE);

            printComparison(minNode->data, scan->data);

            countComparison(cost);

            if(scan->data < minNode->data){

                minNode = scan;

                printf(COLOR_LOGO);
                printf("  |  ");

                printf(COLOR_ACCENT);
                printf("New Minimum Found : %d",
                       minNode->data);
                printf(COLOR_RESET);

                printf("\n");

            }

            scan = scan->next;
        }

        /*==================================================*
                            Minimum Found
        *==================================================*/

        printf("\n");

        printf(COLOR_LOGO);
        printf("Minimum Found : ");

        printf(COLOR_ACTIVE);
        printf("%d\n", minNode->data);

        printf(COLOR_RESET);

        printf("\n");

        delayScreen(800);

        /*==================================================*
                                Swap
        *==================================================*/

        if(minNode != current){

            drawListInline(*head,
                            current,
                            minNode,
                            LIST_BREAK);

            printf(COLOR_LOGO);
            printf("  |  ");
            printf(COLOR_RESET);

            swapNodes(head,
                      tail,
                      current,
                      minNode);

            countSwap(cost);

            /* Relink visualization */
            drawListInline(*head,
                        minNode,
                        current,
                        LIST_RELINK);
            printf("\n\n");

            /* Final swapped list */
            drawListInline(*head,
                        minNode,
                        current,
                        LIST_SORTED);

            printf("\n");


            delayScreen(800);
        }

        else{

            printNoSwap();

            delayScreen(800);
        }

        /*==================================================*
                        Move To Next Position
        *==================================================*/

        current = minNode->next;

        delayScreen(800);
        pass++;
    }
}