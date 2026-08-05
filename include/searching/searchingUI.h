#ifndef SEARCHING_UI_H
#define SEARCHING_UI_H

/*==========================================================
                    Display Modes
==========================================================*/

#define ARRAY_NORMAL        0
#define ARRAY_COMPARE       1
#define ARRAY_FOUND         2
#define ARRAY_DISCARDED     3

/*==========================================================
                    Screen Pages
==========================================================*/

void printOriginalArrayScreen(const int arr[],
                              int size);

void printSortedArrayScreen(const int arr[],
                            int size);

void printSearchHeader(const char *algorithm,
                       int step);

/*==========================================================
                    Array Renderer
==========================================================*/

void drawArray(const int arr[],
               int size,
               int current,
               int secondary,
               int start,
               int end,
               int mode);

/*==========================================================
                Search Information
==========================================================*/

void printSearchComparison(int first,
                     int second,
                     const char *relation);

void printSearchDirection(const char *direction);

void printCurrentRange(int start,
                       int end);

void printCurrentIndex(int index);

/*==========================================================
                    Final Result
==========================================================*/

void printElementFound(int index);

void printElementNotFound(void);

#endif