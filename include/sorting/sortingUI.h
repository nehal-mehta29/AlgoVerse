#ifndef SORTING_UI_H
#define SORTING_UI_H

#include "doublyLinkedList.h"

/*==========================================================
                Linked List Display Modes
==========================================================*/

#define LIST_NORMAL        0
#define LIST_COMPARE       1
#define LIST_BREAK         2
#define LIST_RELINK        3
#define LIST_SORTED        4

/*==========================================================
                    Screen Functions
==========================================================*/

// Displays the original linked list
void printOriginalListScreen(struct Node *head);

// Displays the final sorted linked list
void printSortedListScreen(struct Node *head);

// Displays the pass header
void printPassHeader(const char *algorithm,
                     int pass);

// Displays a visualization header
void printVisualizationHeader(const char *title);

// Displays sorting completed message
void printSortingCompleted(void);

/*==========================================================
                Algorithm Event Functions
==========================================================*/

// Displays comparison between two values
void printComparison(int first,
                     int second);

// Displays swap required message
void printSwapRequired(void);

// Displays no swap required message
void printNoSwap(void);

// Displays current step information
void printStep(int step,
               int totalSteps);

/*==========================================================
                Linked List Visualization
==========================================================*/

// Draws the linked list according to the visualization mode
void drawList(struct Node *head,
              struct Node *first,
              struct Node *second,
              struct Node *breakAfter,
              struct Node *breakBefore,
              int mode);

#endif