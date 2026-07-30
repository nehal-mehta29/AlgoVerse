#include <stdio.h>

#include "ui.h"
#include "menu.h"

int main(void){
    int choice;

    splashScreen();

    homeMenu();

    scanf("%d", &choice);

    return 0;
}