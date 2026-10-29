#ifndef DATASET_H
#define DATASET_H

/*========== Dataset Management ==========*/

// Create/Store a new dataset
void setDataset(const int data[], int size);

// Replace the current dataset
void updateDataset(const int data[], int size);

// Get read-only access to the stored dataset
const int* getDataset(void);

// Get the number of elements
int getDatasetSize(void);

// Free allocated memory before exiting
void freeDataset(void);

#endif