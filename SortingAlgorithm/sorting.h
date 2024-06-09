#pragma once

using LinkedList::Node;

namespace Sorting
{
    
    // Selection Sort
    template <typename T>
    void selectionSort(Node<T>*);

    template <typename T>
    void optimizedSelectionSort(Node<T>*);

    // Bubble Sort
    template <typename T>
    void bubbleSort(Node<T>*);

    template <typename T>
    void optimizedBubbleSort(Node<T>*);

    // Insertion Sort
    template <typename T>
    void insertionSort(Node<T>*);

    // Bogo Sort
    template <typename T>
    bool isSorted(Node<T>*);

    template <typename T>
    void bogoSort(Node<T>*);

    // Shell Sort
    template <typename T>
    void shellSort(Node<T>*);

    template <typename T>
    Node<T>* regresseK(Node<T>*, int);

} // namespace Sorting