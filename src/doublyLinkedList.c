#include <stdio.h>
#include <stdlib.h>

#include "doublyLinkedList.h"
#include "colors.h"

/*==========================================================
                    Create New Node
==========================================================*/

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf(COLOR_ERROR);
        printf("\nMemory Allocation Failed!\n");
        printf(COLOR_RESET);
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

/*==========================================================
                    Insert At End
==========================================================*/

void insertAtEnd(struct Node **head, int data){
    struct Node *newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

/*==========================================================
                Create Doubly Linked List
==========================================================*/

struct Node *createList(int n){
    struct Node *head = NULL;
    int element;

    printf("\n");

    for(int i = 0; i < n; i++){
        printf(COLOR_INPUT);
        printf("Element %d : ", i + 1);
        printf(COLOR_RESET);

        scanf("%d", &element);

        insertAtEnd(&head, element);
    }

    return head;
}

/*==========================================================
                Display Linked List
==========================================================*/

void displayList(struct Node *head){

    printf(COLOR_LOGO);
    printf("\nHEAD\n");
    printf(" |\n");
    printf(" v\n");
    printf(COLOR_RESET);

    printf(COLOR_TEXT);
    printf("NULL ");

    while(head != NULL){

        printf("<--> ");

        printf(COLOR_NUMBER);
        printf("[%d]", head->data);

        printf(COLOR_TEXT);
        printf(" ");

        head = head->next;
    }

    printf("<--> NULL\n");
    printf(COLOR_RESET);
}

/*==========================================================
            Display Linked List In Reverse
==========================================================*/

void displayReverse(struct Node *tail){

    printf(COLOR_LOGO);
    printf("\nTAIL\n");
    printf(" |\n");
    printf(" v\n");
    printf(COLOR_RESET);

    printf(COLOR_TEXT);
    printf("NULL ");

    while(tail != NULL){

        printf("<--> ");

        printf(COLOR_NUMBER);
        printf("[%d]", tail->data);

        printf(COLOR_TEXT);
        printf(" ");

        tail = tail->prev;
    }

    printf("<--> NULL\n");
    printf(COLOR_RESET);
}

/*==========================================================
                    Find Tail
==========================================================*/

struct Node *findTail(struct Node *head){

    if(head == NULL){
        return NULL;
    }

    while(head->next != NULL){
        head = head->next;
    }

    return head;
}

/*==========================================================
                    Free Linked List
==========================================================*/

void freeList(struct Node *head){

    struct Node *temp;

    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}