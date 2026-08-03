#ifndef SORTING_INPUT_H
#define SORTING_INPUT_H

#include "doublyLinkedList.h"

/*==========================================================
                    Input Functions
==========================================================*/

int getNumberOfElements(void);

struct Node *getInputList(int n);

/*==========================================================
                Display Functions
==========================================================*/

void printOriginalList(struct Node *head);

void printSortedList(struct Node *head);

#endif