#include <stdio.h>
#include <math.h>

#include "sorting/quick.h"
#include "sorting/swap.h"
#include "sorting/sortingUI.h"

#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"
#include "dataSet.h"

#include "cost.h"

/*==========================================================
                    Quick Sort Page
==========================================================*/

void quickPage(void){

    struct Node *head = NULL;
    struct Node *tail = NULL;

    const int *data;
    int size;

    clearScreen();

    printBreadcrumb("Home > Sorting Algorithms > Quick Sort");

    printDivider("Quick Sort");

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

    quickSort(&head, &tail, &cost);

    stopCostTimer(&cost);

    /*======================================================*
                        Sorted List
    *======================================================*/

    printf("\n");

    printSortedListScreen(head);

    pauseScreen();

    /*======================================================*
                        Cost Analysis
    *======================================================*/
    long theoreticalComparisons = (size > 1) ? (long)(size * (log(size) / log(2))) : 0;
    long theoreticalSwaps = (size > 1) ? (long)(theoreticalComparisons / 2) : 0;

    displayCostAnalysis(cost,
                        "Quick Sort",
                        size,
                        "n log2(n)",
                        theoreticalComparisons,
                        "n/2 log2(n)",
                        theoreticalSwaps,
                        "O(n log n)",
                        "O(n log n)",
                        "O(n^2)",
                        "O(log n)");

    freeList(head);
}

/*==========================================================*
                  Quick Sort - Partition
*==========================================================*/

struct Node *partition(struct Node **head,
                       struct Node **tail,
                       struct Node *low,
                       struct Node *high,
                       struct Cost *cost){

    struct Node *i = NULL;
    struct Node *j = low;

    int pivot = high->data;

    /*======================================================*
                        Partition Header
    *======================================================*/

    printf("\n");

    printDivider("PARTITIONING");

    printf("\n");

    printf(COLOR_LOGO);
    printf("Pivot : ");

    printf(COLOR_ACTIVE);
    printf("%d\n", pivot);

    printf(COLOR_RESET);

    delayScreen(800);

    /*======================================================*
                        Partition Process
    *======================================================*/

    while(j != high){

        // Save next node before any pointer swap.
        struct Node *jNext = j->next;

        printf("\n");

        printComparison(j->data, pivot);

        countComparison(cost);

        printf("\n");

        drawList(*head,
                 j,
                 high,
                 NULL,
                 NULL,
                 LIST_COMPARE);

        delayScreen(800);

        /*==================================================*
                    Node Belongs To Left Partition
        *==================================================*/

        if(j->data <= pivot){

            struct Node *target;

            if(i == NULL){
                target = low;
            }
            else{
                target = i->next;
            }

            printf("\n");

            printf(COLOR_SUCCESS);
            printf("%d <= %d\n", j->data, pivot);
            printf("Node belongs to left partition.\n");
            printf(COLOR_RESET);

            delayScreen(800);

            /*==============================================*
                        Swap Required
            *==============================================*/

            if(target != j){

                printf("\n");

                printSwapRequired();

                printf(COLOR_LOGO);
                printf("Boundary Node : %d\n",
                       target->data);

                printf("Current Node  : %d\n",
                       j->data);

                printf(COLOR_RESET);

                /*------------------------------------------*
                                Break Links
                *------------------------------------------*/

                drawList(*head,
                         target,
                         j,
                         target,
                         j,
                         LIST_BREAK);

                delayScreen(800);

                /*------------------------------------------*
                                Swap Nodes
                *------------------------------------------*/

                swapNodes(head,
                          tail,
                          target,
                          j);

                countSwap(cost);
                /*------------------------------------------*
                                Relink
                *------------------------------------------*/

                printf("\n");

                drawList(*head,
                         target,
                         j,
                         target,
                         j,
                         LIST_RELINK);

                delayScreen(800);
            }

            else{

                printf("\n");

                printf(COLOR_SUCCESS);
                printf("Already in Correct Position.\n");
                printf(COLOR_RESET);

                delayScreen(800);
            }

            // j becomes the new partition boundary.
            
            i = j;
        }

        /*==================================================*
                    Node Belongs To Right Partition
        *==================================================*/

        else{

            printf("\n");

            printf(COLOR_ACCENT);
            printf("%d > %d\n",
                   j->data,
                   pivot);

            printf("Node remains in right partition.\n");

            printf(COLOR_RESET);

            delayScreen(800);
        }

        j = jNext;
    }

    /*======================================================*
                    Place Pivot
    *======================================================*/

    struct Node *target;

    if(i == NULL){
        target = low;
    }
    else{
        target = i->next;
    }

    printf("\n");

    printf(COLOR_LOGO);
    printf("Placing Pivot ");

    printf(COLOR_ACTIVE);
    printf("%d", pivot);

    printf(COLOR_LOGO);
    printf(" Into Correct Position\n");

    printf(COLOR_RESET);

    delayScreen(800);

    /*======================================================*
                    Pivot Swap
    *======================================================*/

    if(target != high){

        printf("\n");

        /*------------------------------------------*
                    Break Pivot Links
        *------------------------------------------*/

        drawList(*head,
                 target,
                 high,
                 target,
                 high,
                 LIST_BREAK);

        delayScreen(800);

        /*------------------------------------------*
                    Swap Pivot
        *------------------------------------------*/

        swapNodes(head,
                  tail,
                  target,
                  high);

        countSwap(cost);

        /*------------------------------------------*
                    Relink + Pivot Highlight
        *------------------------------------------*/

        printf("\n");

        drawList(*head,
                 high,
                 NULL,
                 target,
                 high,
                 LIST_RELINK);

        delayScreen(800);
    }

    else{

        printf("\n");

        printf(COLOR_SUCCESS);
        printf("Pivot Already in Correct Position.\n");
        printf(COLOR_RESET);

        delayScreen(800);
    }

    return high;
}

/*==========================================================*
                    Quick Sort Recursion
*==========================================================*/

void quickSortRec(struct Node **head,
                  struct Node **tail,
                  struct Node *low,
                  struct Node *high,
                  struct Cost *cost){

    if(high == NULL ||
       low == NULL ||
       low == high ||
       low == high->next){

        return;
    }

    /*======================================================*
                    Save Partition Boundaries
    *======================================================*/

    struct Node *beforeLow = low->prev;
    struct Node *afterHigh = high->next;

    /*======================================================*
                        Partition
    *======================================================*/

    struct Node *pivot =
        partition(head,
                  tail,
                  low,
                  high,
                  cost);

    /*======================================================*
                    Find New Boundaries
    *======================================================*/

    struct Node *newLow;

    if(beforeLow == NULL){
        newLow = *head;
    }
    else{
        newLow = beforeLow->next;
    }

    struct Node *newHigh;

    if(afterHigh == NULL){
        newHigh = *tail;
    }
    else{
        newHigh = afterHigh->prev;
    }

    /*======================================================*
                        Pivot Fixed
    *======================================================*/

    printf("\n");

    printf(COLOR_SUCCESS);
    printf("Pivot %d is now in its correct position.\n",
           pivot->data);
    printf(COLOR_RESET);

    delayScreen(800);

    /*======================================================*
                    Sort Left Partition
    *======================================================*/

    if(pivot->prev != NULL){

        printf("\n");

        printf(COLOR_LOGO);
        printf("Sorting Left Partition of Pivot %d...\n",
               pivot->data);
        printf(COLOR_RESET);

        delayScreen(800);

        quickSortRec(head,
                     tail,
                     newLow,
                     pivot->prev,
                     cost);
    }

    /*======================================================*
                    Sort Right Partition
    *======================================================*/

    if(pivot->next != NULL){

        printf("\n");

        printf(COLOR_LOGO);
        printf("Sorting Right Partition of Pivot %d...\n",
               pivot->data);
        printf(COLOR_RESET);

        delayScreen(800);

        quickSortRec(head,
                     tail,
                     pivot->next,
                     newHigh,
                     cost);
    }
}

/*==========================================================*
                        Quick Sort
*==========================================================*/

void quickSort(struct Node **head,
               struct Node **tail,
               struct Cost *cost){

    if(*head == NULL || (*head)->next == NULL){
        return;
    }

    struct Node *high = *tail;

    /*======================================================*
                    Quick Sort Header
    *======================================================*/

    printf("\n");

    printDivider("QUICK SORT");

    printf("\n");

    printf(COLOR_LOGO);
    printf("Starting Quick Sort...\n");
    printf(COLOR_RESET);

    delayScreen(800);

    /*======================================================*
                    Recursive Quick Sort
    *======================================================*/

    quickSortRec(head,
                 tail,
                 *head,
                 high,
                 cost);

    /*======================================================*
                    Restore Head / Tail
    *======================================================*/

    while(*head != NULL && (*head)->prev != NULL){
        *head = (*head)->prev;
    }

    *tail = *head;

    while(*tail != NULL && (*tail)->next != NULL){
        *tail = (*tail)->next;
    }
}