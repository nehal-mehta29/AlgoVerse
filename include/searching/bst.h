#ifndef BST_H
#define BST_H

#include "searching/binaryTree.h"
/*==========================================================
                Binary Search Tree Page
==========================================================*/

void bstPage(void);

/*==========================================================*
                        BST Search
*==========================================================*/

struct TreeNode *searchBST(struct TreeNode *root, int key);
#endif