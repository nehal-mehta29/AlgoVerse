#ifndef JUMP_H
#define JUMP_H

#include "cost.h"
/*==========================================================
                Jump Search Page
==========================================================*/

void jumpPage(void);

/*==========================================================
                    Jump Search
==========================================================*/

int jumpSearch(int arr[],
               int size,
               int key,
               struct Cost *cost);

#endif