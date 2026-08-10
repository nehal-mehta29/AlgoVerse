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
        Display BST With Highlighted Search Node
*==========================================================*/

void displayHighlightedTree(struct TreeNode *root,
                             struct TreeNode *current,
                             int found);

/*==========================================================*
                Display BST During Search
*==========================================================*/

void displaySearchTree(struct TreeNode *root,
                       struct TreeNode *current,
                       int found,
                       int step );

/*==========================================================*
                        Free BST
*==========================================================*/

void freeTree(struct TreeNode *root);

#endif