#include <stdio.h>

#include "searching/bfs.h"
#include "searching/binaryTree.h"

#include "utils.h"
#include "colors.h"
#include "dataSet.h"

/*==========================================================
                Breadth First Search Page
==========================================================*/

void bfsPage(void){

    const int *data;
    int size;

    struct TreeNode *root = NULL;

    int key;

    clearScreen();

    printBreadcrumb("Home > Searching Algorithms > Breadth First Search");

    printDivider("Breadth First Search");

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
                    BFS Search
    *======================================================*/

    int step = 1;

    bfsSearch(root, key, &step);

    /*======================================================*
                    Free Tree
    *======================================================*/

    freeTree(root);
}

/*==========================================================*
                        BFS Search
*==========================================================*/

struct TreeNode *bfsSearch(struct TreeNode *root,
                           int key,
                           int *step){

    struct TreeNode *queue[100];

    int front = 0;
    int rear = 0;

    struct TreeNode *current;

    /*======================================================*
                    Check Empty Tree
    *======================================================*/

    if(root == NULL){

        return NULL;
    }

    /*======================================================*
                    Add Root To Queue
    *======================================================*/

    queue[rear] = root;
    rear++;

    /*======================================================*
                    BFS Traversal
    *======================================================*/

    while(front < rear){

        current = queue[front];
        front++;

        printf("\n");

        /*==================================================*
                        QUEUE DISPLAY
        ===================================================*/
        printf(COLOR_LOGO);
        printf("Queue : ");
        printf(COLOR_RESET);

        if(front >= rear){
            printf("NULL\n");
        }

        else{
            for(int i = front; i < rear; i++){

                printf("%d", queue[i]->data);

                if(i < rear - 1){
                    printf(" -> ");
                }
            }

            printf("\n");
        }

        /*==================================================*
                    Display Current Step
        *==================================================*/

        printf("\n");

        printf(COLOR_LOGO);
        printf("======== BREADTH FIRST SEARCH - STEP ");

        printf(COLOR_LOGO);
        printf("%d", *step);

        printf(COLOR_LOGO);
        printf(" ========\n");

        printf(COLOR_RESET);

        printf("\n");

        /*==================================================*
                    Display Complete Tree
        *==================================================*/

        displayHighlightedTree(root,
                               current,
                               0);

        printf(COLOR_CURRENT);
        printf("\nComparing Element : %d\n",
               current->data);

        printf(COLOR_RESET);

        delayScreen(800);

        /*==================================================*
                    Element Found
        *==================================================*/

        if(current->data == key){

            printf("\n");

            printf(COLOR_SUCCESS);

            printf("%d == %d\n",
                   key,
                   current->data);

            printf("Element Found.\n");

            printf(COLOR_RESET);

            delayScreen(800);

            /*==============================================*
                    Display Complete Tree - Found
            *==============================================*/

            displayHighlightedTree(root,
                                   current,
                                   1);

            delayScreen(800);

            printf("\n");

            printf(COLOR_SUCCESS);
            printf("Search Successful!\n");
            printf(COLOR_RESET);

            return current;
        }

        /*==================================================*
                    Comparison
        *==================================================*/

        printf("\n");

        printf(COLOR_ACCENT);

        printf("%d != %d\n",
               key,
               current->data);

        printf(COLOR_RESET);

        delayScreen(800);

        /*==================================================*
                    Add Left Child
        *==================================================*/

        if(current->left != NULL){

            queue[rear] =
                current->left;

            rear++;

            printf(COLOR_LOGO);
            printf("Added %d to Queue\n",
                current->left->data);
            printf(COLOR_RESET);
        }

        /*==================================================*
                    Add Right Child
        *==================================================*/

        if(current->right != NULL){

            queue[rear] =
                current->right;

            rear++;

            printf(COLOR_LOGO);
            printf("Added %d to Queue\n",
                current->right->data);
            printf(COLOR_RESET);
        }

        /*==================================================*
                    Move To Next Step
        *==================================================*/

        (*step)++;
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