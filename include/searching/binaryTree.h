#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "doublyLinkedList.h"

/*==========================================================*
                Binary Search Tree Node
*==========================================================*/

struct TreeNode{

    int data;

    struct TreeNode *left;
    struct TreeNode *right;
};

/*==========================================================*
                    Create Tree Node
*==========================================================*/

struct TreeNode *createTreeNode(int data);

/*==========================================================*
                    Insert Node Into BST
*==========================================================*/

struct TreeNode *insertTreeNode(struct TreeNode *root, int data);

/*==========================================================*
                Build BST From Dataset
*==========================================================*/

struct TreeNode *buildBSTFromDataset(const int *data, int size);

/*==========================================================*
                        Display BST
*==========================================================*/

void displayTree(struct TreeNode *root);

/*==========================================================*
                        Free BST
*==========================================================*/

void freeTree(struct TreeNode *root);

#endif