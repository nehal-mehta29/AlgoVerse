#ifndef DFS_H
#define DFS_H

#include "binaryTree.h"
#include "cost.h"

/*==========================================================
                Depth First Search Page
==========================================================*/
void dfsPage(void);

/*==========================================================*
                    Depth First Search
*==========================================================*/

struct TreeNode *dfsSearch(struct TreeNode *root,
                           int key,
                           int *step,
                           struct TreeNode *treeRoot,
                           struct Cost *cost);

#endif