#ifndef QUICK_H
#define QUICK_H

#include "doublyLinkedList.h"

/*==========================================================
                    Quick Sort Page
==========================================================*/

void quickPage(void);

/*==========================================================*
                  Quick Sort Functions
*==========================================================*/

void quickSort(struct Node **head,
               struct Node **tail);

void quickSortRec(struct Node **head,
                  struct Node **tail,
                  struct Node *low,
                  struct Node *high);

struct Node *partition(struct Node **head,
                       struct Node **tail,
                       struct Node *low,
                       struct Node *high);

#endif