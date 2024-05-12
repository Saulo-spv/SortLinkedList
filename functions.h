#ifndef FUNCOES_H
#define FUNCOES_H

// Estrutura do Nó
typedef struct Node
{
    int iValue;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Linked List
Node* newNode(int);
void addElementEnd(Node**, int);
void addElementFront(Node**, int);
Node* searchNodebyValue(Node*, int);
void insertAfter(Node*, int);
void insertBefore(Node*, int);
void deleteNode(Node**, Node*);
void deleteNodebyValue(Node**, int);
void printList(Node*);
void swapValue(int&, int&);

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