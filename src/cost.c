#include <stdio.h>
#include "cost.h"

/*==========================================================*
                    Start Timer
*==========================================================*/

void startCostTimer(struct Cost *cost){

    cost->start = clock();
}

/*==========================================================*
                    Stop Timer
*==========================================================*/

void stopCostTimer(struct Cost *cost){

    cost->end = clock();

    cost->executionTime =
        ((double)(cost->end - cost->start)
        / CLOCKS_PER_SEC) * 1000.0;
}

/*==========================================================*
                    Count Comparison
*==========================================================*/

void countComparison(struct Cost *cost){

    cost->comparisons++;
}

/*==========================================================*
                    Count Swap
*==========================================================*/

void countSwap(struct Cost *cost){

    cost->swaps++;
}

/*==========================================================*
                    Display Cost Analysis
*==========================================================*/

void displayCostAnalysis(struct Cost cost,
                         const char *algorithm,
                         int inputSize){

    printf("\n");
    printf("========================================\n");
    printf("          %s COST ANALYSIS\n",
           algorithm);
    printf("========================================\n");

    printf("\n");

    printf("Algorithm       : %s\n", algorithm);
    printf("Input Size      : %d\n", inputSize);

    printf("\n");

    printf("## ACTUAL COST\n");

    printf("\n");

    printf("Execution Time  : %.3f ms\n",
           cost.executionTime);

    printf("Comparisons     : %ld\n",
           cost.comparisons);

    printf("Swaps           : %ld\n",
           cost.swaps);

    printf("\n");

    printf("## COMPLEXITY\n");

    printf("\n");

    printf("Best Case       : O(n)\n");
    printf("Average Case    : O(n^2)\n");
    printf("Worst Case      : O(n^2)\n");
    printf("Space           : O(1)\n");

    printf("\n");
    printf("========================================\n");
}