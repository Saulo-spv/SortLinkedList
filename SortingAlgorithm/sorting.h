#pragma once

using LinkedList::Node;

namespace Sorting
{
    
    // Selection Sort
    void selectionSort(Node*);
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

} // namespace Sorting