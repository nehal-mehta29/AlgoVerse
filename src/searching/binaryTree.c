#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "searching/binaryTree.h"
#include "dataSet.h"
#include "utils.h"
#include "colors.h"

/*==========================================================*
                    Create Tree Node
*==========================================================*/

struct TreeNode *createTreeNode(int data){

    struct TreeNode *newNode;

    newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if(newNode == NULL){

        printf(COLOR_ERROR);
        printf("\nMemory Allocation Failed!\n");
        printf(COLOR_RESET);

        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/*==========================================================*
                Insert Node Into BST
*==========================================================*/

struct TreeNode *insertTreeNode(struct TreeNode *root, int data){

    if(root == NULL){

        return createTreeNode(data);
    }

    if(data < root->data){

        root->left =
            insertTreeNode(root->left, data);
    }

    else if(data > root->data){

        root->right =
            insertTreeNode(root->right, data);
    }

    return root;
}

/*==========================================================*
                Build BST From Stored Dataset
*==========================================================*/

struct TreeNode *buildBSTFromDataset(const int *data, int size){

    struct TreeNode *root = NULL;

    for(int i = 0; i < size; i++){

        root = insertTreeNode(root, data[i]);
    }

    return root;
}

/*==========================================================*
                Tree Display Helper
*==========================================================*/

typedef struct{

    char lines[64][256];

    int numLines;
    int width;

    int rootStart;
    int rootEnd;

} TreeBox;

/*==========================================================*
                    Create Spaces
*==========================================================*/

static void makeSpaces(char *str, int count){

    int i;

    if(count < 0)
        count = 0;

    for(i = 0; i < count; i++){

        str[i] = ' ';
    }

    str[count] = '\0';
}

/*==========================================================*
                    Create Characters
*==========================================================*/

static void makeChars(char *str,
                      char ch,
                      int count){

    int i;

    if(count < 0)
        count = 0;

    for(i = 0; i < count; i++){

        str[i] = ch;
    }

    str[count] = '\0';
}

/*==========================================================*
                    Build Printable Tree
*==========================================================*/

static TreeBox buildTreeBox(struct TreeNode *root, 
                            struct TreeNode *current,
                            int found){

    TreeBox box;

    box.numLines = 0;
    box.width = 0;
    box.rootStart = 0;
    box.rootEnd = -1;

    if(root == NULL)
        return box;

    char nodeText[64];
    char plainNodeText[20];

    sprintf(plainNodeText, "%d", root->data);

    int nodeWidth = strlen(plainNodeText);

    if(root == current){

        if(found){
            sprintf(nodeText,
                    COLOR_ACTIVE "%d" COLOR_RESET,
                    root->data);
        }
        else{
            sprintf(nodeText,
                    COLOR_ACCENT "%d" COLOR_RESET,
                    root->data);
        }
    }
    else{
        sprintf(nodeText, "%d", root->data);
    }

    TreeBox leftBox =
        buildTreeBox(root->left, current, found);

    TreeBox rightBox =
        buildTreeBox(root->right, current, found);

    char line1[256] = "";
    char line2[256] = "";
    char temp[256];

    int gap = nodeWidth;
    int rootPosition;

    /*======================================================*
                        Left Subtree
    *======================================================*/

    if(leftBox.width > 0){

        int leftRoot =
            (leftBox.rootStart +
             leftBox.rootEnd) / 2 + 1;

        makeSpaces(temp, leftRoot + 1);
        strcat(line1, temp);

        makeChars(temp,
                  '_',
                  leftBox.width - leftRoot);

        strcat(line1, temp);

        makeSpaces(temp, leftRoot);
        strcat(line2, temp);

        strcat(line2, "/");

        makeSpaces(temp,
                   leftBox.width - leftRoot);

        strcat(line2, temp);

        rootPosition =
            leftBox.width + 1;

        gap++;
    }

    else{

        rootPosition = 0;
    }

    strcat(line1, nodeText);

    makeSpaces(temp, nodeWidth);
    strcat(line2, temp);

    /*======================================================*
                        Right Subtree
    *======================================================*/

    if(rightBox.width > 0){

        int rightRoot =
            (rightBox.rootStart +
             rightBox.rootEnd) / 2;

        makeChars(temp,
                  '_',
                  rightRoot);

        strcat(line1, temp);

        makeSpaces(temp,
                   rightBox.width -
                   rightRoot + 1);

        strcat(line1, temp);

        makeSpaces(temp, rightRoot);

        strcat(line2, temp);

        strcat(line2, "\\");

        makeSpaces(temp,
                   rightBox.width -
                   rightRoot);

        strcat(line2, temp);

        gap++;
    }

    box.rootStart = rootPosition;

    box.rootEnd =
        rootPosition + nodeWidth - 1;

    strcpy(box.lines[box.numLines++],
           line1);

    strcpy(box.lines[box.numLines++],
           line2);

    char gapSpace[256];

    makeSpaces(gapSpace, gap);

    int maxLines;

    if(leftBox.numLines >
       rightBox.numLines)

        maxLines = leftBox.numLines;

    else

        maxLines = rightBox.numLines;

    for(int i = 0; i < maxLines; i++){

        char row[256] = "";

        if(i < leftBox.numLines){

            strcat(row,
                   leftBox.lines[i]);
        }

        else if(leftBox.width > 0){

            makeSpaces(temp,
                       leftBox.width);

            strcat(row, temp);
        }

        strcat(row, gapSpace);

        if(i < rightBox.numLines){

            strcat(row,
                   rightBox.lines[i]);
        }

        else if(rightBox.width > 0){

            makeSpaces(temp,
                       rightBox.width);

            strcat(row, temp);
        }

        strcpy(box.lines[box.numLines++],
               row);
    }

    box.width = strlen(plainNodeText);

    if(leftBox.width > 0){
        box.width += leftBox.width + 1;
    }

    if(rightBox.width > 0){
        box.width += rightBox.width + 1;
    }

    return box;
}

/*==========================================================*
                        Display Tree
*==========================================================*/

void displayTree(struct TreeNode *root){

    if(root == NULL){

        printf(COLOR_ERROR);
        printf("\nTree is Empty.\n");
        printf(COLOR_RESET);

        return;
    }

    TreeBox box =
        buildTreeBox(root, NULL, 0);

    printf("\n");

    for(int i = 0;
        i < box.numLines;
        i++){

        printf("%s\n",
               box.lines[i]);
    }

    printf("\n");
}

void displayHighlightedTree(struct TreeNode *root,
                            struct TreeNode *current,
                            int found){

    if(root == NULL){
        return;
    }

    TreeBox box =
        buildTreeBox(root, current, found);

    printf("\n");

    for(int i = 0;
        i < box.numLines;
        i++){

        printf("%s\n", box.lines[i]);
    }

    printf("\n");
}

/*==========================================================*
                Display BST During Search
*==========================================================*/

void displaySearchTree(struct TreeNode *root,
                       struct TreeNode *current,
                       int found,
                       int step){

    if(root == NULL){
        return;
    }

    printf("\n");

    //Display step number

    printf(COLOR_LOGO);
    printf("======== BINARY SEARCH TREE - STEP ");

    printf(COLOR_CURRENT);
    printf("%d", step);

    printf(COLOR_LOGO);
    printf(" ========\n");

    printf(COLOR_RESET);

    printf("\n");

    // Display tree

    displayHighlightedTree(root, current, found);

    //Display which node is being compared

    if(current != NULL){

        if(found){

            printf(COLOR_SUCCESS);
            printf("\nFound Element : %d\n",
                   current->data);
            printf(COLOR_RESET);
        }

        else{

            printf(COLOR_CURRENT);
            printf("\nComparing Element : %d\n",
                   current->data);
            printf(COLOR_RESET);
        }
    }
}

/*==========================================================*
                        Free Tree
*==========================================================*/

void freeTree(struct TreeNode *root){

    if(root == NULL)
        return;

    freeTree(root->left);

    freeTree(root->right);

    free(root);
}