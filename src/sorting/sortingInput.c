#include <stdio.h>

#include "sorting/sortingInput.h"
#include "doublyLinkedList.h"
#include "colors.h"

/*==========================================================
                Get Number Of Elements
==========================================================*/

int getNumberOfElements(void){

    int n;

    printf(COLOR_TEXT);
    printf("Enter Number of Elements : ");
    printf(COLOR_RESET);

    scanf("%d", &n);
    getchar();

    return n;
}

/*==========================================================
                Get Input Linked List
==========================================================*/

struct Node *getInputList(int n){

    return createList(n);

}

/*==========================================================
                Print Original List
==========================================================*/

void printOriginalList(struct Node *head){

    printf(COLOR_SUCCESS);
    printf("\nOriginal Linked List\n");
    printf(COLOR_RESET);

    displayList(head);

}

/*==========================================================
                Print Sorted List
==========================================================*/

void printSortedList(struct Node *head){

    printf(COLOR_SUCCESS);
    printf("\nSorted Linked List\n");
    printf(COLOR_RESET);

    displayList(head);

}