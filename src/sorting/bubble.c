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

    //Original List
    printOriginalListScreen(head);

    pauseScreen();

    printf("\n\n");

    struct Cost cost = {0};  // Initialize cost structure
    startCostTimer(&cost);

    bubbleSort(&head, &tail, &cost);   //Bubble Sort

    stopCostTimer(&cost);

    //Sorted List
    printSortedListScreen(head);

    pauseScreen();

    printf("\n");

    //Display Cost Analysis
    displayCostAnalysis(cost,
                        "Bubble Sort",
                        size,
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

            printComparison(current->data,
                current->next->data);

            drawList(*head,
                    current,
                    current->next,
                    current->prev,
                    current,
                    LIST_COMPARE);

            delayScreen(800);

            /*==================================================
                            Swap Required
            ==================================================*/

            countComparison(cost);

            if(current->data > current->next->data){

                printSwapRequired();

                delayScreen(800);

                /*==================================================
                            Break Connection
                ==================================================*/

                drawList(*head,
                    current,
                    current->next,
                    current->prev,
                    current,
                    LIST_BREAK);

                delayScreen(800);

                /*==================================================
                            Swap Adjacent Nodes
                ==================================================*/
                swapAdjacent(head, tail, current, current->next);

                countSwap(cost);

                /*==================================================
                            Relink Nodes
                ==================================================*/

                drawList(*head,
                    current->prev,
                    current,
                    current->prev,
                    current,
                    LIST_RELINK);

                delayScreen(800);

                /*==================================================
                            Swap Completed
                ==================================================*/
                drawList(*head,
                    current,
                    current->prev,
                    current->prev,
                    current,
                    LIST_SORTED);
                
                delayScreen(800);

                swapped = 1;

                if(current->prev != NULL){
                    current = current->prev;
                }
            }

            /*==================================================
                            No Swap
            ==================================================*/

            else{
                printNoSwap();

                delayScreen(800);

                current = current->next;
            }
            step ++;
        }

        pass++;
    }
    
    while(swapped);

}