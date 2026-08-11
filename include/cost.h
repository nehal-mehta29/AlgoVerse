#ifndef COST_H
#define COST_H

#include <time.h>

/*==========================================================*
                    Cost Analysis
*==========================================================*/

struct Cost{

    clock_t start;
    clock_t end;

    double executionTime;

    long comparisons;
    long swaps;
};

/*==========================================================*
                    Timer Functions
*==========================================================*/

void startCostTimer(struct Cost *cost);

void stopCostTimer(struct Cost *cost);

/*==========================================================*
                    Cost Counters
*==========================================================*/

void countComparison(struct Cost *cost);

void countSwap(struct Cost *cost);

/*==========================================================*
                    Display Cost
*==========================================================*/

void displayCostAnalysis(struct Cost cost,
                         const char *algorithm,
                         int inputSize,
                         const char *bestCase,
                         const char *averageCase,
                         const char *worstCase,
                         const char *space);

#endif