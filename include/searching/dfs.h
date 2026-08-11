#ifndef DFS_H
#define DFS_H

#include "binaryTree.h"

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
                           struct TreeNode *treeRoot);

#endif