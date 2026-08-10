#include <stdio.h>

#include "sorting/insertion.h"
#include "sorting/swap.h"
#include "sorting/sortingUI.h"

#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"
#include "dataSet.h"

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
                    Insertion Sort
    *======================================================*/

    insertionSort(&head, &tail);

    /*======================================================*
                        Sorted List
    *======================================================*/

    printf("\n");

    printSortedListScreen(head);

    freeList(head);
}

/*==========================================================*
                    Insertion Sort
*==========================================================*/

void insertionSort(struct Node **head,
                   struct Node **tail){

    int step = 1;

    if(*head == NULL || (*head)->next == NULL){
        return;
    }

    struct Node *current = (*head)->next;

    while(current != NULL){

        struct Node *nextNode = current->next;
        struct Node *position = current->prev;

        /*==================================================*
                            Step Header
        *==================================================*/

        printf("\n");

        printPassHeader("Insertion Sort", step);

        printf("\n");

        printf(COLOR_LOGO);
        printf("Current Node : ");

        printf(COLOR_CURRENT);
        printf("%d\n", current->data);

        printf(COLOR_RESET);

        delayScreen(800);

        /*==================================================*
                        Find Insertion Position
        *==================================================*/

        while(position != NULL &&
              position->data > current->data){

            printComparison(position->data,
                            current->data);

            drawList(*head,
                     position,
                     current,
                     NULL,
                     NULL,
                     LIST_COMPARE);

            delayScreen(800);

            position = position->prev;
        }

        /*==================================================*
                        Correct Position
        *==================================================*/

        if(position == current->prev){

            printNoSwap();

            delayScreen(800);
        }

        else{

            printSwapRequired();

            drawList(*head,
                     position,
                     current,
                     position,
                     current,
                     LIST_BREAK);

            delayScreen(800);

            /* Move current node to its correct position */

            if(position == NULL){

                /* Move node to the beginning */

                struct Node *before = current->prev;
                struct Node *after = current->next;

                if(before != NULL)
                    before->next = after;

                if(after != NULL)
                    after->prev = before;
                else
                    *tail = before;

                current->prev = NULL;
                current->next = *head;

                (*head)->prev = current;

                *head = current;
            }

            else{

                struct Node *before = current->prev;
                struct Node *after = current->next;

                if(before != NULL)
                    before->next = after;

                if(after != NULL)
                    after->prev = before;
                else
                    *tail = before;

                current->prev = position;
                current->next = position->next;

                if(position->next != NULL)
                    position->next->prev = current;

                position->next = current;
            }

            printf("\n");

            printf(COLOR_SUCCESS);
            printf("Node Inserted Successfully.\n");
            printf(COLOR_RESET);

            delayScreen(800);

            /*==================================================*
                    Show Reconnected List
            *==================================================*/

            drawList(*head,
                     current,
                     position,
                     current,
                     position,
                     LIST_RELINK);

            delayScreen(800);
        }

        current = nextNode;
        step++;
    }
}