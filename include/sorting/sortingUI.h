#ifndef SORTING_UI_H
#define SORTING_UI_H

#include "doublyLinkedList.h"

/*==========================================================
                Algorithm Information
==========================================================*/

void printAlgorithmTitle(const char *algorithm);

void printPass(int pass);

void printStep(const char *message);

/*==========================================================
                Comparison
==========================================================*/

void printComparison(int first,
                     int second);

void printSwapRequired(void);

void printNoSwap(void);

/*==========================================================
                Linked List Display
==========================================================*/

void printCurrentList(struct Node *head);

void printBreakLinks(struct Node *head,
                     struct Node *first,
                     struct Node *second);

void printReconnectLinks(struct Node *head);

#endif