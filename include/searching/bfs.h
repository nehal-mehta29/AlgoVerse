#ifndef BFS_H
#define BFS_H

/*==========================================================
                Breadth First Search Page
==========================================================*/

void bfsPage(void);

/*==========================================================*
                BFS Search
*==========================================================*/

struct TreeNode *bfsSearch(struct TreeNode *root,
                           int key,
                           int *step);

#endif