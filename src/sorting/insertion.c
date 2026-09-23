#include <stdio.h>

#include "sorting/insertion.h"
#include "sorting/swap.h"
#include "sorting/sortingUI.h"

#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"
#include "dataSet.h"

#include "cost.h"

/*==========================================================
                    Insertion Sort Page
==========================================================*/

void insertionPage(void){

    struct Node *head = NULL;
    struct Node *tail = NULL;

    const int *data;
    int size;

    clearScreen();

    printBreadcrumb("Home > Sorting Algorithms > Insertion Sort");

    printDivider("Insertion Sort");

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

    insertionSort(&head, &tail, &cost);

    stopCostTimer(&cost);


    /*======================================================*
                        Sorted List
    *======================================================*/

    printf("\n");

    printSortedListScreen(head);

    pauseScreen();

    printf("\n");

    /*======================================================
                        Cost Analysis
    ======================================================*/

    long theoreticalComparisons = (long)size * (size - 1) / 2;

    long theoreticalSwaps = (long)size * (size - 1) / 2;

    displayCostAnalysis(cost,
                        "Insertion Sort",
                        size,
                        "n(n-1)/2",
                        theoreticalComparisons,
                        "n(n-1)/2",
                        theoreticalSwaps,
                        "O(n)",
                        "O(n^2)",
                        "O(n^2)",
                        "O(1)");

    printf("\n");

    freeList(head);
}

/*==========================================================*
                    Insertion Sort
*==========================================================*/

void insertionSort(struct Node **head,
                   struct Node **tail,
                   struct Cost *cost){

    int pass = 1;
    int step;

    if(*head == NULL || (*head)->next == NULL){
        return;
    }

    struct Node *current = (*head)->next;

    while(current != NULL){

        printPassHeader("Insertion Sort", pass);

        struct Node *nextNode = current->next;
        struct Node *keyNode = current;

        step = 1;

        while(keyNode->prev != NULL){

            printStep(step, pass);

            /*==================================================
                            Comparison
            ==================================================*/

            drawList(*head,
                     keyNode->prev,
                     keyNode,
                     keyNode->prev,
                     keyNode,
                     LIST_COMPARE);

            printComparison(keyNode->prev->data,
                            keyNode->data);

            countComparison(cost);

            /*==================================================
                            Swap Required
            ==================================================*/

            if(keyNode->prev->data > keyNode->data){

                printf(COLOR_LOGO);
                printf("  |  ");

                printSwapRequired();

                printf("\n");

                /* Break Visualization */
                drawListInline(*head,
                               keyNode->prev,
                               keyNode,
                               LIST_BREAK);

                printf(COLOR_LOGO);
                printf("  |  ");
                printf(COLOR_RESET);

                /* Swap Adjacent Nodes */
                swapAdjacent(head,
                             tail,
                             keyNode->prev,
                             keyNode);

                countSwap(cost);

                /* Relink Visualization */
                drawListInline(*head,
                               keyNode,
                               keyNode->next,
                               LIST_RELINK);

                printf("\n\n");

                /* Final Swapped List for Current Step */
                drawListInline(*head,
                               keyNode,
                               keyNode->next,
                               LIST_SORTED);

                printf("\n\n");

                delayScreen(800);
                step++;
            }

            /*==================================================
                            No Swap (In Correct Place)
            ==================================================*/

            else{

                printf(COLOR_LOGO);
                printf("  |  ");

                printNoSwap();

                delayScreen(800);
                break;
            }
        }

        delayScreen(800);
        current = nextNode;
        pass++;
    }
}