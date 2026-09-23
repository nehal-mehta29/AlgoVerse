#ifndef QUICK_H
#define QUICK_H

#include "doublyLinkedList.h"
#include "cost.h"

/*==========================================================
                    Quick Sort Page
==========================================================*/

void quickPage(void);

/*==========================================================*
                  Quick Sort Functions
*==========================================================*/

void quickSort(struct Node **head,
               struct Node **tail,
               struct Cost *cost);

void quickSortRec(struct Node **head,
                  struct Node **tail,
                  struct Node *low,
                  struct Node *high,
                  struct Cost *cost);

struct Node *partition(struct Node **head,
                       struct Node **tail,
                       struct Node *low,
                       struct Node *high,
                       struct Cost *cost);

#endif