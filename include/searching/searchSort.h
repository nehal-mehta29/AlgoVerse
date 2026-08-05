#ifndef SEARCH_SORT_H
#define SEARCH_SORT_H

/*==========================================================
                Check if Array is Sorted
==========================================================*/

int isSortedArray(int arr[],
             int size);

/*==========================================================
                    Bubble Sort
==========================================================*/

void bubbleSortArray(int arr[],
                int size);

/*==========================================================
                    Merge Sort
==========================================================*/

void mergeSortArray(int arr[],
               int left,
               int right);

/*==========================================================
                Merge Two Sorted Arrays
==========================================================*/

void mergeArray(int arr[],
           int left,
           int mid,
           int right);

#endif