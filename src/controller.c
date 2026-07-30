#include <stdio.h>
#include <stdlib.h>

#include "controller.h"
#include "menu.h"
#include "colors.h"

void runApplication(void){
    int choice;

    while (1){
        HOME_MENU:
        #ifdef _WIN32
                system("cls");
        #else
                system("clear");
        #endif

        homeMenu();

        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:{
                int sortingChoice;

                while (1){
                    #ifdef _WIN32
                        system("cls");
                    #else
                        system("clear");
                    #endif

                    sortingMenu();

                    scanf("%d", &sortingChoice);
                    getchar();

                    switch (sortingChoice){
                        case 1:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Bubble Sort page coming soon!\n");
                            break;

                        case 2:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Selection Sort page coming soon!\n");
                            break;

                        case 3:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Insertion Sort page coming soon!\n");
                            break;

                        case 4:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Merge Sort page coming soon!\n");
                            break;

                        case 5:
                            printf("\n");
                            printf(COLOR_SUCCESS);
                            printf("Quick Sort page coming soon!\n");
                            break;

                        case 0:
                            goto HOME_MENU;
                            
                        default:
                            printf("\n");
                            printf(COLOR_ERROR);
                            printf("Invalid Choice!\n");
                    }

                    printf(COLOR_RESET);

                    printf(COLOR_PROMPT);
                    printf("\n\nPress ENTER to continue...");
                    printf(COLOR_RESET);

                    getchar();
                }
            }
            case 2:
                printf(COLOR_SUCCESS);
                printf("\nSearching Menu Coming Soon!\n");
                printf(COLOR_RESET);
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

        printf(COLOR_PROMPT);
        printf("\n\nPress ENTER to continue...");
        printf(COLOR_RESET);
        getchar();
    }
}