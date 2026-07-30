#include <stdio.h>

#include "../include/ui.h"
#include "../include/colors.h"

/*==========================================================
                    Splash Screen
==========================================================*/

void splashScreen(void){
    printf(COLOR_LOGO);

    printf("\n");
    printf("     _    _     ____   ___ __     __ _____ ____  ____ _____\n");
    printf("    / \\\\  | |   / ___| / _ \\\\\\ \\   / /| ____|  _ \\\\/ ___| ____|\n");
    printf("   / _ \\\\ | |  | |  _ | | | |\\\\ \\ / / |  _| | |_) \\\\___ \\\\|  _|\n");
    printf("  / ___ \\\\| |__| |_| || |_| | \\\\ V /  | |___|  _ < ___) | |___\n");
    printf(" /_/   \\\\_\\\\_____\\\\____| \\\\___/   \\\\_/   |_____|_| \\\\_\\\\____/|_____|\n");

    printf(COLOR_RESET);

    printf("\n");

    printf(COLOR_TEXT);
    printf("        Interactive Data Structure & Algorithm Learning System\n");
    printf(COLOR_RESET);

    printf("\n");

    printf(COLOR_ACCENT);
    printf("                  Visualize • Analyze • Understand\n");
    printf(COLOR_RESET);

    printf("\n\n");

    printf(COLOR_PROMPT);
    printf("Press ENTER to continue...");
    printf(COLOR_RESET);

    getchar();
}