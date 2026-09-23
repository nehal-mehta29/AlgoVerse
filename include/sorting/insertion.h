#ifndef INSERTION_H
#define INSERTION_H

#include "doublyLinkedList.h"

#include "cost.h"
/*==========================================================
                    Insertion Sort Page
==========================================================*/

void insertionPage(void);

/*==========================================================*
                    Insertion Sort Function
*==========================================================*/

void insertionSort(struct Node **head,
                   struct Node **tail,
                   struct Cost *Cost);

#endif