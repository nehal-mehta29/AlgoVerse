#include <stdio.h>

#include "sorting/bubble.h"
#include "sorting/swap.h"
#include "sorting/sortingUI.h"

#include "dataSet.h"
#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"

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

    bubbleSort(&head, &tail);   //Bubble Sort

    //Sorted List
    printSortedListScreen(head);

    pauseScreen();

    freeList(head);

}

/*==========================================================
                Bubble Sort Algorithm
==========================================================*/

void bubbleSort(struct Node **head, struct Node **tail){

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

            printStep(step, getDatasetSize() - 1);

            printComparison(current->data,
                current->next->data);

            drawList(*head,
                    current,
                    current->next,
                    current->prev,
                    current,
                    LIST_COMPARE);
            
            printf("\n");

            if(current->data > current->next->data){

                printSwapRequired();

                drawList(*head,
                    current,
                    current->next,
                    current->prev,
                    current,
                    LIST_BREAK);

                printf("\n");

                swapAdjacent(head, tail, current, current->next);

                drawList(*head,
                    current->prev,
                    current,
                    current->prev,
                    current,
                    LIST_RELINK);

                printf("\n");

                drawList(*head,
                    current,
                    current->prev,
                    current->prev,
                    current,
                    LIST_SORTED);
                
                printf("\n");

                swapped = 1;

                if(current->prev != NULL){
                    current = current->prev;
                }
            }

            else{
                printNoSwap();

                current = current->next;
            }
            step ++;
        }

        pass++;
    }
    
    while(swapped);

}