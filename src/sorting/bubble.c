#include <stdio.h>

#include "sorting/bubble.h"
#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"

/*==========================================================
                    Bubble Sort Page
==========================================================*/

void bubblePage(void){
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int n;

    clearScreen();

    printBreadcrumb("Home > Sorting Algorithms > Bubble Sort");

    printDivider("Bubble Sort");

    printf(COLOR_TEXT);
    printf("Enter Number of Elements : ");
    printf(COLOR_RESET);

    scanf("%d",&n);
    getchar();

    head = createList(n);

    tail = findTail(head);

    printf(COLOR_SUCCESS);
    printf("\nOriginal Linked List\n");
    printf(COLOR_RESET);

    displayList(head);

    /* Bubble Sort */

    bubbleSort(&head, &tail);

    printf(COLOR_SUCCESS);
    printf("\nSorted Linked List\n");
    printf(COLOR_RESET);

    displayList(head);

    pauseScreen();

    freeList(head);
}

/*==========================================================
                Bubble Sort Algorithm
==========================================================*/

void bubbleSort(struct Node **head,struct Node **tail){
    if(*head == NULL){
        return;
    }

    int swapped;

    do{

        swapped = 0;

        struct Node *current = *head;

        while(current->next != NULL){

            if(current->data > current->next->data){

                swapAdjacent(head,
                             tail,
                             current,
                             current->next);

                swapped = 1;

                /*
                    current now points to the larger node.

                    After swapping:

                    second -> current

                    So move one step back to continue correctly.
                */

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
}