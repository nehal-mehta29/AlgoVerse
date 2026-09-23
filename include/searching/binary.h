#ifndef BINARY_H
#define BINARY_H

#include "cost.h"

/*==========================================================
                    Binary Search Page
==========================================================*/

void binaryPage(void);

/*==========================================================
                Recursive Binary Search
==========================================================*/

int binarySearch(int arr[],
                 int low,
                 int high,
                 int key,
                 struct Cost *cost);

#endif