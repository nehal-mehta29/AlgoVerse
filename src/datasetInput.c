#include <stdio.h>
#include <stdlib.h>

#include "datasetInput.h"
#include "dataSet.h"
#include "colors.h"

/*==========================================================
                    Input Dataset
==========================================================*/

void inputDataset(void){
    int n;
    int i;
    int *data;

    printf(COLOR_TEXT);
    printf("Enter Number of Elements : ");
    printf(COLOR_RESET);

    scanf("%d", &n);

    if (n <= 0){
        printf(COLOR_ERROR);
        printf("\nInvalid number of elements!\n");
        printf(COLOR_RESET);
        return;
    }

    data = (int *)malloc(n * sizeof(int));

    if (data == NULL){
        printf(COLOR_ERROR);
        printf("\nMemory allocation failed!\n");
        printf(COLOR_RESET);
        exit(EXIT_FAILURE);
    }

    printf(COLOR_TEXT);
    printf("\nEnter %d Elements : ", n);
    printf(COLOR_RESET);

    for (i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }

    setDataset(data, n);

    free(data);
}