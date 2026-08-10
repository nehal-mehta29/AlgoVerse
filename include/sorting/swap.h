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

/*==========================================================
                Swap Any Two Nodes
==========================================================*/

void swapNodes(struct Node **head,
               struct Node **tail,
               struct Node *a,
               struct Node *b);


#endif 