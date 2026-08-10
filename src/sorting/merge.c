#include <stdio.h>

#include "sorting/merge.h"
#include "sorting/sortingUI.h"
#include "sorting/swap.h"

#include "utils.h"
#include "colors.h"
#include "doublyLinkedList.h"
#include "dataSet.h"

/*==========================================================
                    Merge Sort Page
==========================================================*/

void mergePage(void){

    struct Node *head = NULL;
    struct Node *tail = NULL;

    const int *data;
    int size;

    clearScreen();

    printBreadcrumb("Home > Sorting Algorithms > Merge Sort");

    printDivider("Merge Sort");

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
                        Merge Sort
    *======================================================*/

    mergeSort(&head, &tail);

    /*======================================================*
                        Sorted List
    *======================================================*/

    printf("\n");

    printSortedListScreen(head);

    freeList(head);
}

/*==========================================================*
                    Find List Length
*==========================================================*/

int findLength(struct Node *head){

    int length = 0;

    struct Node *current = head;

    while(current != NULL){

        length++;
        current = current->next;
    }

    return length;
}


/*==========================================================*
                        Merge Sort
*==========================================================*/

void mergeSort(struct Node **head,
               struct Node **tail){

    if(*head == NULL || (*head)->next == NULL){
        return;
    }

    int length = findLength(*head);

    /*======================================================*
                        Two Node Case
    *======================================================*/

    if(length == 2){

        struct Node *first = *head;
        struct Node *second = first->next;

        printf("\n");

        printDivider("MERGE SORT - TWO NODE COMPARISON");

        printf("\n");

        printComparison(first->data,
                        second->data);

        drawList(*head,
                first,
                second,
                NULL,
                NULL,
                LIST_COMPARE);

        delayScreen(800);

        /*==================================================*
                        Swap Required
        *==================================================*/

        if(first->data > second->data){

            printSwapRequired();

            /*----------------------------------------------*
                        Break Links
            *----------------------------------------------*/

            drawList(*head,
                    first,
                    second,
                    first,
                    second,
                    LIST_BREAK);

            delayScreen(800);

            /*----------------------------------------------*
                        Swap Nodes
            *----------------------------------------------*/

            swapAdjacent(head,
                        tail,
                        first,
                        second);

            /*----------------------------------------------*
                        Relinked Nodes
            *----------------------------------------------*/

            drawList(*head,
                    second,
                    first,
                    second,
                    first,
                    LIST_RELINK);

            delayScreen(800);
        }

        else{

            printNoSwap();

            delayScreen(800);
        }

        return;
    }

    /*======================================================*
                        Split List
    *======================================================*/

    struct Node *secondHalf = splitList(*head, length);

    /*======================================================*
                    Find Tails of Both Halves
    *======================================================*/

    struct Node *firstTail = NULL;
    struct Node *secondTail = NULL;

    if(*head != NULL){

        firstTail = *head;

        while(firstTail->next != NULL){
            firstTail = firstTail->next;
        }
    }

    if(secondHalf != NULL){

        secondTail = secondHalf;

        while(secondTail->next != NULL){
            secondTail = secondTail->next;
        }
    }

    /*======================================================*
                    Recursively Sort First Half
    *======================================================*/

    mergeSort(head, &firstTail);

    /*======================================================*
                    Recursively Sort Second Half
    *======================================================*/

    mergeSort(&secondHalf, &secondTail);

    /*======================================================*
                            Merge
    *======================================================*/

    struct Node *merged =
        mergeLists(*head, secondHalf);

    /*======================================================*
                    Update Head and Tail
    *======================================================*/

    *head = merged;

    *tail = merged;

    if(*tail != NULL){

        while((*tail)->next != NULL){
            *tail = (*tail)->next;
        }
    }
}

/*==========================================================*
                    Split Linked List
*==========================================================*/

struct Node *splitList(struct Node *head,
                       int length){

    if(head == NULL || length <= 1){
        return NULL;
    }

    int mid = length / 2;

    struct Node *middle = head;

    for(int i = 1; i < mid; i++){
        middle = middle->next;
    }

    struct Node *secondHalf = middle->next;

    /*======================================================*
                    Break Connection
    *======================================================*/

    printf("\n");

    printDivider("SPLITTING LIST");

    printf("\n");

    printf(COLOR_LOGO);
    printf("List Length : ");

    printf(COLOR_CURRENT);
    printf("%d\n", length);

    printf(COLOR_LOGO);
    printf("Middle      : ");

    printf(COLOR_CURRENT);
    printf("%d\n", middle->data);

    printf(COLOR_RESET);

    delayScreen(800);

    printf("\n");

    if(secondHalf != NULL){

        printf(COLOR_BREAK);
        printf("Breaking Link Between %d and %d\n",
            middle->data,
            secondHalf->data);
        printf(COLOR_RESET);

        delayScreen(800);
    }

    middle->next = NULL;

    if(secondHalf != NULL){
        secondHalf->prev = NULL;
    }

    /*======================================================*
                        Show First Half
    *======================================================*/

    printf("\n");

    printf(COLOR_LOGO);
    printf("First Half\n");
    printf(COLOR_RESET);

    drawList(head,
             NULL,
             NULL,
             NULL,
             NULL,
             LIST_COMPARE);

    delayScreen(800);

    /*======================================================*
                        Show Second Half
    *======================================================*/

    printf("\n");

    printf(COLOR_LOGO);
    printf("Second Half\n");
    printf(COLOR_RESET);

    drawList(secondHalf,
             NULL,
             NULL,
             NULL,
             NULL,
             LIST_COMPARE);

    delayScreen(800);

    return secondHalf;
}


/*==========================================================*
                    Merge Two Sorted Lists
*==========================================================*/

struct Node *mergeLists(struct Node *first,
                        struct Node *second){

    struct Node *result = NULL;
    struct Node *tail = NULL;

    /*======================================================*
                        Merge Process
    *======================================================*/

    while(first != NULL && second != NULL){

        printf("\n");

        printDivider("MERGING");

        printf("\n");

        printComparison(first->data,
                        second->data);

        drawList(first,
                 first,
                 second,
                 NULL,
                 NULL,
                 LIST_COMPARE);

        delayScreen(800);

        struct Node *selected;

        if(first->data <= second->data){

            selected = first;
            first = first->next;
        }

        else{

            selected = second;
            second = second->next;
        }

        /*==================================================*
                    Detach Selected Node
        *==================================================*/

        selected->prev = NULL;
        selected->next = NULL;

        /*==================================================*
                    Add To Result List
        *==================================================*/

        if(result == NULL){

            result = selected;
            tail = selected;
        }

        else{

            tail->next = selected;
            selected->prev = tail;

            tail = selected;
        }

        /*==================================================*
                    Show Reconnected List
        *==================================================*/

        printf("\n");

        printf(COLOR_SUCCESS);
        printf("Node %d Added To Merged List\n",
               selected->data);
        printf(COLOR_RESET);

        delayScreen(800);
    }

    /*======================================================*
                    Remaining First Half
    *======================================================*/

    while(first != NULL){

        struct Node *selected = first;

        first = first->next;

        selected->prev = NULL;
        selected->next = NULL;

        if(result == NULL){

            result = selected;
            tail = selected;
        }

        else{

            tail->next = selected;
            selected->prev = tail;

            tail = selected;
        }

        delayScreen(800);
    }

    /*======================================================*
                    Remaining Second Half
    *======================================================*/

    while(second != NULL){

        struct Node *selected = second;

        second = second->next;

        selected->prev = NULL;
        selected->next = NULL;

        if(result == NULL){

            result = selected;
            tail = selected;
        }

        else{

            tail->next = selected;
            selected->prev = tail;

            tail = selected;
        }

        delayScreen(800);
    }

    return result;
}