#ifndef BUBBLE_H
#define BUBBLE_H
#include "doublyLinkedList.h"

#include "cost.h"

/*==========================================================
                    Bubble Sort Page
==========================================================*/

void bubblePage(void);

/*==========================================================
                Bubble Sort Algorithm
==========================================================*/

void bubbleSort(struct Node **head,
                struct Node **tail,
                struct Cost *cost);

#endif