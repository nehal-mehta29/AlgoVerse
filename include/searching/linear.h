#ifndef LINEAR_H
#define LINEAR_H

#include "cost.h"

/*==========================================================
                Linear Search Page
==========================================================*/

void linearPage(void);

/*==========================================================
                    Linear Search
==========================================================*/

int linearSearch(int arr[],
                 int size,
                 int key,
                 struct Cost *cost);

#endif