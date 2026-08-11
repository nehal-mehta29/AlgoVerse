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
                         int inputSize,
                         const char *bestCase,
                         const char *averageCase,
                         const char *worstCase,
                         const char *space){

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

    printf("Best Case       : %s\n",bestCase);
    printf("Average Case    : %s\n",averageCase);
    printf("Worst Case      : %s\n",worstCase);
    printf("Space           : %s\n",space);

    printf("\n");
    printf("========================================\n");
}