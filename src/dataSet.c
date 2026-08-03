#include <stdio.h>
#include <stdlib.h>
#include "dataSet.h"

/*========== Private Variables ==========*/

static int *dataset = NULL;
static int datasetSize = 0;

/*========== Store / Replace Dataset ==========*/

void setDataset(const int data[], int size){
    int i;

    /* Free old dataset if it exists */
    free(dataset);

    dataset = NULL;
    datasetSize = 0;

    if (size <= 0)
        return;

    dataset = (int *)malloc(size * sizeof(int));

    if (dataset == NULL){
        printf("\nError: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < size; i++){
        dataset[i] = data[i];
    }

    datasetSize = size;
}

/*========== Get Dataset ==========*/

const int* getDataset(void){
    return dataset;
}

/*========== Get Dataset Size ==========*/

int getDatasetSize(void){
    return datasetSize;
}

/*========== Free Dataset ==========*/

void freeDataset(void){
    free(dataset);
    dataset = NULL;
    datasetSize = 0;
}