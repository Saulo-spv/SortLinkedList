#ifndef SORTING_H
#define SORTING_H

// Selection Sort
void selectionSort_Aux(Node*);
void selectionSort(Node*);
void optimizedSelectionSort_Aux(Node*);
void optimizedSelectionSort(Node*);

// Bubble Sort
void bubbleSort(Node*);
void optimizedBubbleSort(Node*);

// Insertion Sort
void insertionSort(Node*);

// Bogo Sort
bool isSorted(Node*);
void shuffleList(Node*, int);
void bogoSort(Node*);

#endif