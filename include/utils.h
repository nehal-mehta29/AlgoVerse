#ifndef UTILS_H
#define UTILS_H

/*==========================================================
                    Utility Functions
==========================================================*/

/* Clear the terminal screen */
void clearScreen(void);

/* Wait until the user presses ENTER */
void pauseScreen(void);

/* Print breadcrumb navigation */
void printBreadcrumb(const char *path);

/* Print a horizontal divider */
void printDivider(const char *title);

#endif