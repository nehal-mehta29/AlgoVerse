#include <stdio.h>

#include "searching/dfs.h"
#include "searching/binaryTree.h"

#include "utils.h"
#include "colors.h"
#include "dataSet.h"

/*==========================================================
                Depth First Search Page
==========================================================*/

void dfsPage(void){
    const int *data;
    int size;

    struct TreeNode *root = NULL;

    int key;

    clearScreen();

    printBreadcrumb("Home > Searching Algorithms > Depth First Search");

    printDivider("Depth First Search");

    /*======================================================*
                    Get Stored Dataset
    *======================================================*/

    data = getDataset();
    size = getDatasetSize();

    /*======================================================*
                    Create Binary Tree
    *======================================================*/

    printf("\n");

    printf(COLOR_LOGO);
    printf("Creating Binary Tree...\n");
    printf(COLOR_RESET);

    delayScreen(800);

    root = buildBSTFromDataset(data, size);

    if(root == NULL){

        printf(COLOR_ERROR);
        printf("\nUnable to create Binary Tree.\n");
        printf(COLOR_RESET);

        return;
    }

    /*======================================================*
                    Display Binary Tree
    *======================================================*/

    displayTree(root);

    pauseScreen();

    /*======================================================*
                    Enter Search Key
    *======================================================*/

    printf("\n\n");

    printf(COLOR_INPUT);
    printf("Enter Element to Search : ");
    printf(COLOR_RESET);

    scanf("%d", &key);

    printf("\n");

    /*======================================================*
                    DFS Search
    *======================================================*/

    int step = 1;

    dfsSearch(root, key, &step, root);

    /*======================================================*
                    Free Tree
    *======================================================*/

    freeTree(root);
}

/*==========================================================*
                        DFS Search
*==========================================================*/

struct TreeNode *dfsSearch(struct TreeNode *root,
                           int key,
                           int *step,
                           struct TreeNode *treeRoot){

    struct TreeNode *result;

    if(root == NULL){

        return NULL;
    }

    /*======================================================*
                    Display Current Step
    *======================================================*/

    printf("\n");

    printf(COLOR_LOGO);
    printf("======== DEPTH FIRST SEARCH - STEP ");

    printf(COLOR_LOGO);
    printf("%d", *step);

    printf(COLOR_LOGO);
    printf(" ========\n");

    printf(COLOR_RESET);

    printf("\n");

    /*======================================================*
                    Display Tree
    *======================================================*/

    displayHighlightedTree(treeRoot, root, 0);

    printf(COLOR_CURRENT);
    printf("\nComparing Element : %d\n",
           root->data);
    printf(COLOR_RESET);

    delayScreen(800);

    /*======================================================*
                    Element Found
    *======================================================*/

    if(root->data == key){

        printf("\n");

        printf(COLOR_SUCCESS);

        printf("%d == %d\n",
               key,
               root->data);

        printf("Element Found.\n");

        printf(COLOR_RESET);

        /* Highlight found node in green */

        displayHighlightedTree(treeRoot, root, 1);

        delayScreen(800);

        return root;
    }

    /*======================================================*
                    Comparison
    *======================================================*/

    printf("\n");

    printf(COLOR_ACCENT);

    printf("%d != %d\n",
           key,
           root->data);

    printf(COLOR_RESET);

    delayScreen(800);

    /*======================================================*
                    Move To Next Step
    *======================================================*/

    (*step)++;

    /*======================================================*
                    Search Left Subtree
    *======================================================*/

    result = dfsSearch(root->left,
                       key,
                       step,
                       treeRoot);

    if(result != NULL){

        return result;
    }

    /*======================================================*
                    Search Right Subtree
    *======================================================*/

    result = dfsSearch(root->right,
                       key,
                       step, 
                       treeRoot);

    if(result != NULL){

        return result;
    }

    return NULL;
}