#pragma once

namespace LinkedList
{
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
    void freeList(Node**);
    void deleteNodebyValue(Node**, int);
    void printList(Node*);
    void swapValue(int&, int&);

} // namespace LinkedList