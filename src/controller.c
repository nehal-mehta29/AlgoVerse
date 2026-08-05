#include <stdio.h>
#include <stdlib.h>

#include "controller.h"
#include "menu.h"
#include "colors.h"
#include "utils.h"

#include "datasetInput.h"

#include "sorting/bubble.h"
#include "sorting/selection.h"
#include "sorting/insertion.h"
#include "sorting/merge.h"
#include "sorting/quick.h"

#include "searching/linear.h"
#include "searching/binary.h"
#include "searching/jump.h"
#include "searching/bst.h"
#include "searching/dfs.h"
#include "searching/bfs.h"

#include "about.h"

void runApplication(void){
    int choice;

    inputDataset();

    while (1){
        HOME_MENU:
        clearScreen();

        homeMenu();

        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:{
                int sortingChoice;

                while (1){
                    clearScreen();

                    sortingMenu();

                    scanf("%d", &sortingChoice);
                    getchar();

                    switch (sortingChoice){
                        case 1:
                            bubblePage();
                            break;

                        case 2:
                            selectionPage();
                            break;

                        case 3:
                           insertionPage();
                            break;

                        case 4:
                            mergePage();
                            break;

                        case 5:
                            quickPage();
                            break;

                        case 0:
                            goto HOME_MENU;

                        default:
                            printf("\n");
                            printf(COLOR_ERROR);
                            printf("Invalid Choice!\n");
                            printf(COLOR_RESET);
                    }

                    printf(COLOR_RESET);

                    getchar();

                }
            }
            break;

            case 2:{
                int searchingChoice;

                while (1){
                    clearScreen();

                    searchingMenu();

                    scanf("%d", &searchingChoice);
                    getchar();

                    switch (searchingChoice){
                        case 1:
                            linearPage();
                            break;

                        case 2:
                            binaryPage();
                            break;

                        case 3:
                            jumpPage();
                            break;

                        case 4:
                            bstPage();
                            break;

                        case 5:
                            dfsPage();
                            break;

                        case 6:
                            bfsPage();
                            break;

                        case 0:
                            goto HOME_MENU;
                            
                        default:
                            printf("\n");
                            printf(COLOR_ERROR);
                            printf("Invalid Choice!\n");
                            printf(COLOR_RESET);
                    }

                    printf(COLOR_RESET);

                    getchar();
                }
            }
            break;

            case 3:
                inputDataset();
                break;
            case 4:
                aboutPage();
                break;

            case 0:
                printf(COLOR_SUCCESS);
                printf("\nThank you for using AlgoVerse!\n");
                printf(COLOR_RESET);
                return;

            default:
                printf(COLOR_ERROR);
                printf("\nInvalid Choice!\n");
                printf(COLOR_RESET);
        }

        pauseScreen();
    }
}