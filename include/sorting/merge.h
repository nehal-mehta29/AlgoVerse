#ifndef MERGE_H
#define MERGE_H

#include "doublyLinkedList.h"
#include "cost.h"

/*==========================================================
                    Merge Sort Page
==========================================================*/

void mergePage(void);

/*==========================================================*
                        Merge Sort
*==========================================================*/

void mergeSort(struct Node **head,
               struct Node **tail,
               struct Cost *cost);

/*==========================================================*
                      Helper Functions
*==========================================================*/

int findLength(struct Node *head);

struct Node *splitList(struct Node *head,
                       int length);

struct Node *mergeLists(struct Node *first,
                        struct Node *second,
                        struct Cost *cost);

#endif