#include <stdlib.h>
#include "sorting/swap.h"

/*==========================================================
                Swap Adjacent Nodes
==========================================================*/

void swapAdjacent(struct Node **head,
                  struct Node **tail,
                  struct Node *first,
                  struct Node *second){

    if(first == NULL || second == NULL){
        return;
    }

    struct Node *before = first->prev;
    struct Node *after = second->next;

    /* Update previous node */

    if(before != NULL){
        before->next = second;
    }
    else{
        *head = second;
    }

    /* Update next node */

    if(after != NULL){
        after->prev = first;
    }
    else{
        *tail = first;
    }

    /* Swap adjacent nodes */

    second->prev = before;
    second->next = first;

    first->prev = second;
    first->next = after;
}