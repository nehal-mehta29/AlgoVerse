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

/*==========================================================*
                    Swap Any Two Nodes
*==========================================================*/

void swapNodes(struct Node **head,
               struct Node **tail,
               struct Node *a,
               struct Node *b){

    if(a == NULL || b == NULL || a == b){
        return;
    }

    /*======================================================*
                        Adjacent Nodes
    *======================================================*/

    if(a->next == b){
        swapAdjacent(head, tail, a, b);
        return;
    }

    if(b->next == a){
        swapAdjacent(head, tail, b, a);
        return;
    }

    /*======================================================*
                        Save Connections
    *======================================================*/

    struct Node *aPrev = a->prev;
    struct Node *aNext = a->next;

    struct Node *bPrev = b->prev;
    struct Node *bNext = b->next;

    /*======================================================*
                    Connect A's Neighbours to B
    *======================================================*/

    if(aPrev != NULL){
        aPrev->next = b;
    }
    else{
        *head = b;
    }

    if(aNext != NULL){
        aNext->prev = b;
    }
    else{
        *tail = b;
    }

    /*======================================================*
                    Connect B's Neighbours to A
    *======================================================*/

    if(bPrev != NULL){
        bPrev->next = a;
    }
    else{
        *head = a;
    }

    if(bNext != NULL){
        bNext->prev = a;
    }
    else{
        *tail = a;
    }

    /*======================================================*
                            Update A
    *======================================================*/

    a->prev = bPrev;
    a->next = bNext;

    /*======================================================*
                            Update B
    *======================================================*/

    b->prev = aPrev;
    b->next = aNext;
}