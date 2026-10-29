#ifndef BFS_H
#define BFS_H

#include "binaryTree.h"
#include "cost.h"

/*==========================================================
                Breadth First Search Page
==========================================================*/

void bfsPage(void);

/*==========================================================*
                BFS Search
*==========================================================*/

struct TreeNode *bfsSearch(struct TreeNode *root,
                           int key,
                           int *step,
                           struct Cost *cost);

#endif