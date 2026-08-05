#include "searching/searchSort.h"

/*==========================================================
                Check if Array is Sorted
==========================================================*/

int isSorted(int arr[],
             int size){

    for(int i = 0; i < size - 1; i++){

        if(arr[i] > arr[i + 1]){
            return 0;
        }
    }

    return 1;
}

/*==========================================================
                    Bubble Sort
==========================================================*/

void bubbleSort(int arr[],
                int size){

    for(int i = 0; i < size - 1; i++){

        int swapped = 0;

        for(int j = 0; j < size - i - 1; j++){

            if(arr[j] > arr[j + 1]){

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        if(swapped == 0){
            break;
        }
    }
}

/*==========================================================
                Merge Two Sorted Arrays
==========================================================*/

void merge(int arr[],
           int left,
           int mid,
           int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1];
    int rightArray[n2];

    for(int i = 0; i < n1; i++){
        leftArray[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++){
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2){

        if(leftArray[i] <= rightArray[j]){
            arr[k++] = leftArray[i++];
        }

        else{
            arr[k++] = rightArray[j++];
        }
    }

    while(i < n1){
        arr[k++] = leftArray[i++];
    }

    while(j < n2){
        arr[k++] = rightArray[j++];
    }
}

/*==========================================================
                    Merge Sort
==========================================================*/

void mergeSort(int arr[],
               int left,
               int right){

    if(left < right){

        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
