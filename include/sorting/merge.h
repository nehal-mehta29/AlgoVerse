#ifndef MERGE_H
#define MERGE_H

#include "doublyLinkedList.h"

/*==========================================================
                    Merge Sort Page
==========================================================*/

void mergePage(void);

/*==========================================================*
                        Merge Sort
*==========================================================*/

void mergeSort(struct Node **head,
               struct Node **tail);

/*==========================================================*
                      Helper Functions
*==========================================================*/

int findLength(struct Node *head);

struct Node *splitList(struct Node *head,
                       int length);

struct Node *mergeLists(struct Node *first,
                        struct Node *second);

#endif