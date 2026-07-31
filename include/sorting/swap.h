#ifndef SWAP_H
#define SWAP_H

#include "doublyLinkedList.h"

/*==========================================================
                Swap Adjacent Nodes
==========================================================*/

void swapAdjacent(struct Node **head,
                  struct Node **tail,
                  struct Node *first,
                  struct Node *second);

#endif 