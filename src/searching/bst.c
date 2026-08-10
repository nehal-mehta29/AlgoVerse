#include <stdio.h>

#include "searching/bst.h"
#include "searching/binaryTree.h"

#include "utils.h"
#include "colors.h"
#include "dataSet.h"

/*==========================================================
                Binary Search Tree Page
==========================================================*/

void bstPage(void){
    const int *data;
    int size;

    struct TreeNode *root = NULL;

    int key;

    clearScreen();

    printBreadcrumb("Home > Searching Algorithms > Binary Search Tree");

    printDivider("Binary Search Tree");

    /*======================================================*
                    Get Stored Dataset
    *======================================================*/

    data = getDataset();
    size = getDatasetSize();

    /*======================================================*
                    Create BST
    *======================================================*/

    printf("\n");

    printf(COLOR_LOGO);
    printf("Creating Binary Search Tree...\n");
    printf(COLOR_RESET);

    delayScreen(800);

    root = buildBSTFromDataset(data, size);

    if(root == NULL){

        printf(COLOR_ERROR);
        printf("\nUnable to create Binary Search Tree.\n");
        printf(COLOR_RESET);

        return;
    }

    /*======================================================*
                        Display BST
    *======================================================*/

    displayTree(root);

    pauseScreen();

    /*======================================================*
                        Enter Search Key
    *======================================================*/

    printf("\n");

    printf("\n");

    printf(COLOR_INPUT);
    printf("Enter Element to Search : ");
    printf(COLOR_RESET);

    scanf("%d", &key);

    printf("\n");

    /*======================================================*
                        BST Search
    *======================================================*/

    searchBST(root, key);

    /*======================================================*
                        Free Tree
    *======================================================*/

    freeTree(root);
}

/*==========================================================*
                        BST Search
*==========================================================*/

struct TreeNode *searchBST(struct TreeNode *root, int key){

    int step = 1;

    struct TreeNode *current = root;

    /*======================================================*
                    Search Process
    *======================================================*/

    while(current != NULL){

        /*==================================================*
                        Step Header
        *==================================================*/

        printf("\n");

        printf(COLOR_LOGO);
        printf("BST SEARCH - STEP ");

        printf(COLOR_CURRENT);
        printf("%d\n", step);

        printf(COLOR_RESET);

        printf(COLOR_LOGO);
        printf("Searching For : ");

        printf(COLOR_ACTIVE);
        printf("%d\n", key);

        printf(COLOR_LOGO);
        printf("Current Node  : ");

        printf(COLOR_CURRENT);
        printf("%d\n", current->data);

        printf(COLOR_RESET);

        /*==================================================*
                        Display Current Step
        *==================================================*/

        printf("\n");

        displaySearchTree(root, current, 0, step);

        delayScreen(800);

        /*==================================================*
                        Comparison
        *==================================================*/

        printf("\n");

        if(key == current->data){

            printf(COLOR_SUCCESS);

            printf("%d == %d\n",
                   key,
                   current->data);

            printf("Element Found.\n");

            printf(COLOR_RESET);

            delayScreen(800);

            /*==============================================*
                        Display Found Element
            *==============================================*/

            printf("\n");

            displaySearchTree(root, current, 1, step);

            delayScreen(800);

            printf("\n");

            printf(COLOR_SUCCESS);
            printf("Search Successful!\n");
            printf(COLOR_RESET);

            return current;
        }

        /*==================================================*
                        Move Left
        *==================================================*/

        if(key < current->data){

            printf(COLOR_ACCENT);

            printf("%d < %d\n",
                   key,
                   current->data);

            printf("Move Left\n");

            printf(COLOR_RESET);

            delayScreen(800);

            current = current->left;
        }

        /*==================================================*
                        Move Right
        *==================================================*/

        else{

            printf(COLOR_ACCENT);

            printf("%d > %d\n",
                   key,
                   current->data);

            printf("Move Right\n");

            printf(COLOR_RESET);

            delayScreen(800);

            current = current->right;
        }

        step++;
    }

    /*======================================================*
                        Element Not Found
    *======================================================*/

    printf("\n");

    printf(COLOR_ERROR);
    printf("Element Not Found.\n");
    printf(COLOR_RESET);

    delayScreen(800);

    return NULL;
}