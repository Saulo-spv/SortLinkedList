#pragma once

namespace LinkedList
{

    // Estrutura do Nó como template
    template <typename T>
    struct Node {
        T Value;
        Node* ptrNext;
        Node* ptrPrev;
    };

    // Funções para Linked List
    template <typename T>
    Node<T>* newNode(T);

    template <typename T>
    void addElementEnd(Node<T>**, T);

    template <typename T>
    void addElementFront(Node<T>**, T);

    template <typename T>
    Node<T>* searchNodebyValue(Node<T>*, T);

    template <typename T>
    void insertAfter(Node<T>*, T);

    template <typename T>
    void insertBefore(Node<T>*, T);

    template <typename T>
    void deleteNode(Node<T>**, Node<T>*);

    template <typename T>
    void freeList(Node<T>**);

    template <typename T>
    void deleteNodebyValue(Node<T>**, T);

    template <typename T>
    void printList(Node<T>*);

    template <typename T>
    void swapValue(T&, T&);

    template <typename T>
    void shuffleList(Node<T>*, int);

} // namespace LinkedList