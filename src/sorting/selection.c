#include <stdio.h>

#include "sorting/selection.h"
#include "sorting/swap.h"
#include "sorting/sortingUI.h"

#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"
#include "dataSet.h"

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
                        Selection Sort
    *======================================================*/

    selectionSort(&head, &tail);

    /*======================================================*
                        Sorted List
    *======================================================*/

    printf("\n"); 

    printSortedListScreen(head);

    freeList(head);
}

/*==========================================================*
                Selection Sort Algorithm
*==========================================================*/

void selectionSort(struct Node **head,
                   struct Node **tail){

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

            printComparison(minNode->data,
                            scan->data);

            drawList(*head,
                     minNode,
                     scan,
                     NULL,
                     NULL,
                     LIST_COMPARE);

            delayScreen(800);

            if(scan->data < minNode->data){

                minNode = scan;

                printf("\n");

                printf(COLOR_ACCENT);
                printf("New Minimum Found : %d\n",
                       minNode->data);
                printf(COLOR_RESET);

                delayScreen(800);
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

        delayScreen(800);

        /*==================================================*
                                Swap
        *==================================================*/

        if(minNode != current){

            printSwapRequired();

            drawList(*head,
                     current,
                     minNode,
                     current,
                     minNode,
                     LIST_BREAK);

            delayScreen(800);

            swapNodes(head,
                      tail,
                      current,
                      minNode);

            printf("\n");

            printf(COLOR_SUCCESS);
            printf("Pointers Swapped Successfully.\n");
            printf(COLOR_RESET);

            delayScreen(800);

            drawList(*head,
                     minNode,
                     current,
                     minNode,
                     current,
                     LIST_RELINK);

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

        pass++;
    }
}