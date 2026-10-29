#include <stdio.h>
#include "cost.h"
#include "colors.h"

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
                         const char *comparisonFormula,
                         long theoreticalComparisons,
                         const char *swapFormula,     
                         long theoreticalSwaps,  
                         const char *bestCase,
                         const char *averageCase,
                         const char *worstCase,
                         const char *space){

       printf("\n");

       printf(COLOR_BORDER);
       printf("====================================================\n");
       printf(COLOR_LOGO STYLE_BOLD);
       printf("          %s COST ANALYSIS\n", algorithm);
       printf(COLOR_BORDER);
       printf("====================================================\n");
       printf(COLOR_RESET);

       printf("\n");

       printf(COLOR_ACCENT "Algorithm       : " COLOR_RESET);
       printf(COLOR_TEXT "%s\n", algorithm);

       printf(COLOR_ACCENT "Input Size      : " COLOR_RESET);
       printf(COLOR_TEXT "%d\n", inputSize);

       printf("\n");

       /*======================================================*
                            ACTUAL COST
       *======================================================*/

       printf("\n");

       printf(COLOR_BORDER "---------- " COLOR_RESET);
       printf(COLOR_LOGO STYLE_BOLD "ACTUAL COST" COLOR_RESET);
       printf(COLOR_BORDER " ----------\n" COLOR_RESET);

       printf("\n");

       printf(COLOR_ACCENT "Execution Time  : " COLOR_RESET);
       printf(COLOR_TEXT "%.3f ms\n", cost.executionTime);

       printf(COLOR_ACCENT "Comparisons     : " COLOR_RESET);
       printf(COLOR_TEXT "%ld\n", cost.comparisons);

       printf(COLOR_ACCENT "Swaps           : " COLOR_RESET);
       printf(COLOR_TEXT "%ld\n", cost.swaps);
       
       /*======================================================*
                     THEORETICAL COST
       *======================================================*/

       printf("\n");

       printf(COLOR_BORDER "-------- " COLOR_RESET);
       printf(COLOR_LOGO STYLE_BOLD "THEORETICAL COST" COLOR_RESET);
       printf(COLOR_BORDER " --------\n" COLOR_RESET);

       printf("\n");

       printf(COLOR_ACCENT "Comparisons     : " COLOR_RESET);
       printf(COLOR_TEXT "%s\n", comparisonFormula);

       printf(COLOR_ACCENT "                  = " COLOR_RESET);
       printf(COLOR_TEXT "%ld\n", theoreticalComparisons);

       printf("\n");

       printf(COLOR_ACCENT "Swaps           : " COLOR_RESET);
       printf(COLOR_TEXT "%s\n", swapFormula);

       printf(COLOR_ACCENT "                  = " COLOR_RESET);
       printf(COLOR_TEXT "%ld\n", theoreticalSwaps);

       /*======================================================*
                     COMPLEXITY
       *======================================================*/

       printf("\n");

       printf(COLOR_BORDER "---------- " COLOR_RESET);
       printf(COLOR_LOGO STYLE_BOLD "COMPLEXITY" COLOR_RESET);
       printf(COLOR_BORDER " ----------\n" COLOR_RESET);

       printf("\n");

       printf(COLOR_ACCENT "Best Case       : " COLOR_RESET);
       printf(COLOR_TEXT "%s\n", bestCase);

       printf(COLOR_ACCENT "Average Case    : " COLOR_RESET);
       printf(COLOR_TEXT "%s\n", averageCase);

       printf(COLOR_ACCENT "Worst Case      : " COLOR_RESET);
       printf(COLOR_TEXT "%s\n", worstCase);

       printf(COLOR_ACCENT "Space           : " COLOR_RESET);
       printf(COLOR_TEXT "%s\n", space);

       printf("\n");

       printf(COLOR_BORDER "====================================================\n");
       printf(COLOR_RESET);
}

/*==========================================================*
                Display Search Cost Analysis
*==========================================================*/

void displaySearchCostAnalysis(struct Cost cost,
                               const char *algorithm,
                               int inputSize,
                               const char *comparisonFormula,
                               long theoreticalComparisons,
                               const char *bestCase,
                               const char *averageCase,
                               const char *worstCase,
                               const char *space){

    printf("\n");

    printf(COLOR_BORDER);
    printf("====================================================\n");
    printf(COLOR_LOGO STYLE_BOLD);
    printf("          %s COST ANALYSIS\n", algorithm);
    printf(COLOR_BORDER);
    printf("====================================================\n");
    printf(COLOR_RESET);

    printf("\n");
    printf(COLOR_ACCENT "Algorithm       : " COLOR_RESET);
    printf(COLOR_TEXT "%s\n", algorithm);

    printf(COLOR_ACCENT "Input Size      : " COLOR_RESET);
    printf(COLOR_TEXT "%d\n", inputSize);

    printf("\n");

    /*======================================================*
                            ACTUAL COST
    *======================================================*/

    printf("\n");

    printf(COLOR_BORDER "---------- " COLOR_RESET);
    printf(COLOR_LOGO STYLE_BOLD "ACTUAL COST" COLOR_RESET);
    printf(COLOR_BORDER " ----------\n" COLOR_RESET);

    printf("\n");

    printf(COLOR_ACCENT "Execution Time  : " COLOR_RESET);
    printf(COLOR_TEXT "%.3f ms\n", cost.executionTime);

    printf(COLOR_ACCENT "Comparisons     : " COLOR_RESET);
    printf(COLOR_TEXT "%ld\n", cost.comparisons);

    /*======================================================*
                         THEORETICAL COST
    *======================================================*/

    printf("\n");

    printf(COLOR_BORDER "-------- " COLOR_RESET);
    printf(COLOR_LOGO STYLE_BOLD "THEORETICAL COST" COLOR_RESET);
    printf(COLOR_BORDER " --------\n" COLOR_RESET);

    printf("\n");

    printf(COLOR_ACCENT "Comparisons     : " COLOR_RESET);
    printf(COLOR_TEXT "%s\n", comparisonFormula);

    printf(COLOR_ACCENT "                  = " COLOR_RESET);
    printf(COLOR_TEXT "%ld\n", theoreticalComparisons);

    /*======================================================*
                            COMPLEXITY
    *======================================================*/

    printf("\n");

    printf(COLOR_BORDER "---------- " COLOR_RESET);
    printf(COLOR_LOGO STYLE_BOLD "COMPLEXITY" COLOR_RESET);
    printf(COLOR_BORDER " ----------\n" COLOR_RESET);

    printf("\n");

    printf(COLOR_ACCENT "Best Case       : " COLOR_RESET);
    printf(COLOR_TEXT "%s\n", bestCase);

    printf(COLOR_ACCENT "Average Case    : " COLOR_RESET);
    printf(COLOR_TEXT "%s\n", averageCase);

    printf(COLOR_ACCENT "Worst Case      : " COLOR_RESET);
    printf(COLOR_TEXT "%s\n", worstCase);

    printf(COLOR_ACCENT "Space           : " COLOR_RESET);
    printf(COLOR_TEXT "%s\n", space);

    printf("\n");

    printf(COLOR_BORDER "====================================================\n");
    printf(COLOR_RESET);
}