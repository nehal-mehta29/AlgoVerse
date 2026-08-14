#include <stdio.h>

#include "sorting/bubble.h"
#include "sorting/swap.h"
#include "sorting/sortingUI.h"

#include "dataSet.h"
#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"

#include "cost.h"

/*==========================================================
                    Bubble Sort Page
==========================================================*/

void bubblePage(void){

    struct Node *head = NULL;
    struct Node *tail = NULL;

    const int *data;
    int size;

    clearScreen();

    printBreadcrumb("Home > Sorting Algorithms > Bubble Sort");

    printDivider("Bubble Sort");

    data = getDataset();
    size = getDatasetSize();

    head = createList(data, size);
    tail = findTail(head);

    /*======================================================*
                            Original List
    =======================================================*/
    printOriginalListScreen(head);

    pauseScreen();

    printf("\n\n");

    /*======================================================
                        Cost Tracking
    ======================================================*/

    struct Cost cost = {0};  // Initialize cost structure
    startCostTimer(&cost);

    bubbleSort(&head, &tail, &cost);   //Bubble Sort

    stopCostTimer(&cost);

    /*======================================================
                            Sorted List
    ======================================================*/
    printSortedListScreen(head);

    pauseScreen();

    printf("\n");

    /*======================================================
                        Cost Analysis
    ======================================================*/

    long theoreticalComparisons = (long)size * (size - 1);

    long theoreticalSwaps = (long)size * (size - 1) / 2;

    displayCostAnalysis(cost,
                        "Bubble Sort",
                        size,
                        "n(n-1)",
                        theoreticalComparisons,
                        "n(n-1)/2",
                        theoreticalSwaps,  
                        "O(n)",
                        "O(n^2)",
                        "O(n^2)",
                        "O(1)");

    freeList(head);

}

/*==========================================================
                Bubble Sort Algorithm
==========================================================*/

void bubbleSort(struct Node **head, struct Node **tail,struct Cost *cost){

    int swapped;
    int pass = 1;
    int step;

    if(*head == NULL){
        return;
    }

    do{
        printPassHeader("Bubble Sort", pass);

        swapped = 0;
        step = 1;

        struct Node *current = *head;

        while(current->next != NULL){

            /*==================================================
                            Comparison
            ==================================================*/

            printStep(step, getDatasetSize() - 1);

            drawList(*head,
                    current,
                    current->next,
                    current->prev,
                    current,
                    LIST_COMPARE);

            printComparison(current->data,
                current->next->data);

            /*==================================================
                            Swap Required
            ==================================================*/

            countComparison(cost);

            if(current->data > current->next->data){

                printf(COLOR_LOGO);
                printf("  |  ");

                printSwapRequired();

                printf("\n");

                /*==================================================
                                Break Visualization
                ==================================================*/

                drawListInline(*head,
                            current,
                            current->next,
                            LIST_BREAK);

                printf(COLOR_LOGO);
                printf("  |  ");
                printf(COLOR_RESET);

                /*==================================================
                                Actual Swap
                ==================================================*/

                swapAdjacent(head,
                            tail,
                            current,
                            current->next);

                countSwap(cost);

                /*==================================================
                                Relink Visualization
                ==================================================*/

                drawListInline(*head,
                            current,
                            current->prev,
                            LIST_RELINK);

                printf("\n\n");

                /*==================================================
                                Final Swapped List
                ==================================================*/

                drawListInline(*head,
                            current,
                            current->prev,
                            LIST_SORTED);

                printf("\n");

                swapped = 1;

                printf("\n");

                swapped = 1;

            }

            /*==================================================
                            No Swap
            ==================================================*/

            else{

                printf(COLOR_LOGO);
                printf("  |  ");
                
                printNoSwap();

                delayScreen(800);

                current = current->next;
            }

            delayScreen(800);
            step ++;
        }

        delayScreen(800);

        pass++;
    }
    
    while(swapped);

}