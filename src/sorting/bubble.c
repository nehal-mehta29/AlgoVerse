#include <stdio.h>

#include "sorting/bubble.h"
#include "sorting/swap.h"
#include "sorting/sortingUI.h"

#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"

/*==========================================================
                    Bubble Sort Page
==========================================================*/

void bubblePage(void){

    struct Node *head = NULL;
    struct Node *tail = NULL;

    //int n;

    clearScreen();

    printBreadcrumb("Home > Sorting Algorithms > Bubble Sort");

    printDivider("Bubble Sort");

    //n = getNumberOfElements();  //Input

    //head = getInputList(n);

    //tail = findTail(head);

    //printOriginalList(head);   //Original List

    //bubbleSort(&head, &tail);   //Bubble Sort

    //printSortedList(head);   //Sorted List

    pauseScreen();

    freeList(head);

}

/*==========================================================
                Bubble Sort Algorithm
==========================================================*/

/*void bubbleSort(struct Node **head, struct Node **tail){

    int swapped;

    if(*head == NULL){
        return;
    }

    int swapped;
    int pass = 1;

    do{
        swapped = 0;

        struct Node *current = *head;

        while(current->next != NULL){

            printComparison(current->data, current->next->data);

            printCurrentList(*head);


            if(current->data > current->next->data){
                printSwapRequired();

                printBreakLinks(*head, current, current->next);

                swapAdjacent(head, tail, current, current->next);

                printReconnectLinks(*head);

                printCurrentList(*head);
                 
                swapped = 1;

                if(current->prev != NULL){
                    current = current->prev;
                }
            }

            else{
                current = current->next;
            }
        }
    }
    
    while(swapped);

}*/