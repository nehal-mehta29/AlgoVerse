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

    printf("\n");

    displayList(head);

    pauseScreen();

    freeList(head);
}

/*==========================================================
                Bubble Sort Algorithm
==========================================================*/

void bubbleSort(struct Node **head,
                struct Node **tail){

    (void)head;
    (void)tail;
}