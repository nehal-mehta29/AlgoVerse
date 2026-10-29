#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

/*==========================================================
                Doubly Linked List Node
==========================================================*/

struct Node{
    int data;

    struct Node *prev;
    struct Node *next;
};

/*==========================================================
                Function Prototypes
==========================================================*/

/* Node Creation */
struct Node *createNode(int data);

/* List Operations */
void insertAtEnd(struct Node **head, int data);
struct Node *createList(const int data[], int size);

/* Display Functions */
void displayList(struct Node *head);

/* Utility Functions */
struct Node *findTail(struct Node *head);
void freeList(struct Node *head);

#endif