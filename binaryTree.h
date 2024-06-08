#pragma once

#include "linkedList.h"

namespace BinaryTree
{

    // Estrutura do Nó como template
    template <typename T>
    struct Node {
        T Value;
        Node* ptrLeft;
        Node* ptrRight;
    };

    // Funções para Binary Tree
    template <typename T>
    Node<T>* createTreeNode(T);

    template <typename T>
    Node<T>* insertNode(Node<T>*, T);

    template <typename T>
    Node<T>* dfsSearchNode(Node<T>*, T);

    template <typename T>
    Node<T>* lesserLeaf(Node<T>*); // menor nó esquerdo

    template <typename T>
    Node<T>* deleteNode(Node<T>*, T);

    template <typename T>
    void traversePreOrder(Node<T>*);

    template <typename T>
    void traverseInOrder(Node<T>*);

    template <typename T>
    void traversePostOrder(Node<T>*);

    template <typename T>
    void bfsTraversal(Node<T>*);

    template <typename T>
    Node<T>* bfsSearchNode(Node<T>*, T);

    template <typename T>
    int treeHeight(Node<T>* startNode);

} // namespace BinaryTree