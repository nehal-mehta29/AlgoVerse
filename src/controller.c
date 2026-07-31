#include <stdio.h>
#include <stdlib.h>

#include "controller.h"
#include "menu.h"
#include "colors.h"
#include "utils.h"

#include "sorting/bubble.h"
#include "sorting/insertion.h"
#include "sorting/merge.h"
#include "sorting/quick.h"
#include "sorting/selection.h"

void runApplication(void){
    int choice;

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

                    pauseScreen();
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
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Linear Search page coming soon!\n");
                            break;

                        case 2:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Binary Search page coming soon!\n");
                            break;

                        case 3:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Jump Search page coming soon!\n");
                            break;

                        case 4:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Binary Search Tree page coming soon!\n");
                            break;

                        case 5:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Depth First Search page coming soon!\n");
                            break;

                        case 6:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Breadth First Search page coming soon!\n");
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

                    pauseScreen();
                }
            }
            break;

            case 3:
                printf(COLOR_SUCCESS);
                printf("\nAbout Page Coming Soon!\n");
                printf(COLOR_RESET);
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