#include <iostream>

#include "binaryTree.h"
#include "linkedList.h"

using namespace std;

namespace BinaryTree
{

    template <typename T>
    Node<T>* createTreeNode(T value)
    {
        // Criação do nó
        Node<T>* node = (Node<T>*) malloc(sizeof(Node<T>));
        
        // Caso a memória seja alocada com sucesso
        if (node != NULL)
        {
            // Inicialização dos parâmetros
            node->Value = value;
            node->ptrLeft = NULL;
            node->ptrRight = NULL;
        }
        
        return node;
    }

    template <typename T>
    Node<T>* insertNode(Node<T>* startNode, T value)
    {
        // Caso a árvore seja vazia
        if (startNode == nullptr) return createTreeNode(value);
        
        // Definindo a alocação do novo nó
        if (value < startNode->Value)
        {
            startNode->ptrLeft = insertNode(startNode->ptrLeft, value);
        }
        else
        {
            startNode->ptrRight = insertNode(startNode->ptrRight, value);
        }
        
        return startNode;
    }

    template <typename T>
    Node<T>* dfsSearchNode(Node<T>* startNode, T value)
    {
        // Caso a árvore seja vazia
        if (startNode == nullptr) return nullptr;
        // Caso o nó seja o startNode
        else if (value == startNode->Value) return startNode;
        // Caso contrário, busca-se o nó nos filhos de startNode
        else if (value < startNode->Value) return dfsSearchNode(startNode->ptrLeft, value);
        else return dfsSearchNode(startNode->ptrRight, value);
    }

    template <typename T>
    Node<T>* bfsSearchNode(Node<T>* startNode, T value) {
        if (startNode == nullptr) return nullptr;

        // Inicialização da lista de preferência
        LinkedList::Node<Node<T>*>* head = nullptr;
        LinkedList::addElementEnd(&head, startNode);

        while (head != nullptr) {
            if (head->Value->Value == value) {
                Node<T>* result = head->Value;
                while (head != nullptr) {
                    LinkedList::deleteNode(&head, head);
                }
                return result;
            }

            if (head->Value->ptrLeft != nullptr) {
                LinkedList::addElementEnd(&head, head->Value->ptrLeft);
            }

            if (head->Value->ptrRight != nullptr) {
                LinkedList::addElementEnd(&head, head->Value->ptrRight);
            }

            LinkedList::deleteNode(&head, head);
        }

        return nullptr; // Valor não encontrado
    }

    template <typename T>
    Node<T>* lesserLeaf(Node<T>* startNode)
    {
        Node<T>* ptrCurrent = startNode;
        // Desdendo a árvore até encontrar o menor nó folha esquerdo
        while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
        
        return ptrCurrent;
    }

    template <typename T>
    Node<T>* deleteNode(Node<T>* startNode, T value)
    {
        // Caso a árvore seja vazia
        if (startNode == nullptr) return nullptr;
        // Caso o valor esteja na sub-árvore esquerda
        if (value < startNode->Value) startNode->ptrLeft = deleteNode(startNode->ptrLeft, value);
        // Caso o valor esteja na sub-árvore direita
        else if (value > startNode->Value) startNode->ptrRight = deleteNode(startNode->ptrRight, value);
        // Caso o valor seja o nó atual
        else
        {
            Node<T>* ptrTemp = nullptr;
            
            // Caso não exista sub-árvore esquerda
            if (startNode->ptrLeft == nullptr)
            {
                ptrTemp = startNode->ptrRight;
                free(startNode);
                return ptrTemp;
            }
            // Caso não exista sub-árvore direita
            else if (startNode->ptrRight == nullptr)
            {
                ptrTemp = startNode->ptrLeft;
                free(startNode);
                return ptrTemp;            
            }
            
            // Caso existam sub-árvores, buscamos o melhor nó folha esquerdo
            ptrTemp = lesserLeaf(startNode->ptrRight);
            // Transição de valor
            startNode->Value = ptrTemp->Value;
            // Deletando o menor nó folha esquerdo
            startNode->ptrRight = deleteNode(startNode->ptrRight, ptrTemp->Value);
        }
        
        return startNode;
    }

    template <typename T>
    void traversePreOrder(Node<T>* startNode)
    {
        if (startNode != nullptr)
        {
            cout << " " << startNode->Value;
            traversePreOrder(startNode->ptrLeft);
            traversePreOrder(startNode->ptrRight);
        }
    }

    template <typename T>
    void traverseInOrder(Node<T>* startNode)
    {
        if (startNode != nullptr)
        {
            traverseInOrder(startNode->ptrLeft);
            cout << " " << startNode->Value;
            traverseInOrder(startNode->ptrRight);
        }
    }

    template <typename T>
    void traversePostOrder(Node<T>* startNode)
    {
        if (startNode != nullptr)
        {
            traversePostOrder(startNode->ptrLeft);
            traversePostOrder(startNode->ptrRight);
            cout << " " << startNode->Value;
        }
    }

    template <typename T>
    void bfsTraversal(Node<T>* startNode)
    {
        if (startNode == nullptr) return;
        
        // Inicialização da lista de preferência
        LinkedList::Node<Node<T>*>* head = nullptr;
        LinkedList::addElementEnd(&head, startNode);

        while(head != nullptr)
        {
            cout << head->Value->Value << " ";
        
            if(head->Value->ptrLeft != nullptr)
            {
                LinkedList::addElementEnd(&head, head->Value->ptrLeft);
            }
        
            if(head->Value->ptrRight != nullptr)
            {
                LinkedList::addElementEnd(&head, head->Value->ptrRight);
            }

            LinkedList::deleteNode(&head, head);
        }
        return;
    }

    template <typename T>
    int treeHeight(Node<T>* startNode)
    {
        if (startNode == nullptr) return 0;
        else
        {
            int iLeftHeight = treeHeight(startNode->ptrLeft);
            int iRightHeight = treeHeight(startNode->ptrRight);
            
            return max(iLeftHeight, iRightHeight) + 1;
        }
    }

    // Instanciação explícita para os tipos inteiros
    template Node<int>* createTreeNode(int);
    template Node<int>* insertNode(Node<int>*, int);
    template Node<int>* dfsSearchNode(Node<int>*, int);
    template Node<int>* lesserLeaf(Node<int>*);
    template Node<int>* deleteNode(Node<int>*, int);
    template void traversePreOrder(Node<int>*);
    template void traverseInOrder(Node<int>*);
    template void traversePostOrder(Node<int>*);
    template void bfsTraversal(Node<int>*);
    template int treeHeight(Node<int>*);
    template Node<int>* bfsSearchNode(Node<int>*, int);

} // namespace BinaryTree