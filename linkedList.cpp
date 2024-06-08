#include <iostream>
#include <cstdlib>

#include "linkedList.h"
#include "SortingAlgorithm/sorting.h"
#include "binaryTree.h"

using namespace std;

namespace LinkedList
{
    template <typename T>
    Node<T>* newNode(T value)
    {
        // Criação do nó
        Node<T>* node = (Node<T>*) malloc(sizeof(Node<T>));
        
        // Caso a memória seja alocada com sucesso
        if (node != NULL)
        {
            // Inicialização dos parâmetros
            node->Value = value;
            node->ptrPrev = NULL;
            node->ptrNext = NULL;
        }
        
        return node;
    }

    template <typename T>
    void addElementEnd(Node<T>** head, T value)
    {
        // Criação do nó
        Node<T>* node = newNode(value);
        
        // Se o cabeçalho da lista for vazio, i.e, lista vazia
        if ((*head) == NULL)
        {   
            // A lista se reduz a este nó
            (*head) = node;
        }
        // Caso contrário, i.e, cabeçalho-não vazio
        else
        {
            // Criação de um nó dinâmico
            Node<T>* current = (*head);

            // Percurso até o fim da lista
            while (current->ptrNext != NULL) current = current->ptrNext;

            // Inserção do nó
            node->ptrPrev = current;
            current->ptrNext = node;
        }
    }

    template <typename T>
    void addElementFront(Node<T>** head, T value)
    {
        // Criação do nó
        Node<T>* node = newNode(value);
        
        // Se o cabeçalho da lista não for vazio, i.e, lista não-vazia 
        if ((*head) != NULL)
        {
            // Inserção do nó antes do cabeçalho
            node->ptrNext = (*head);
            (*head)->ptrPrev = node;
            // Correção na posição do cabeçalho
            (*head) = node;
            return;
        }

        // Se lista for vazia, a operação se reduz a inserção do nó no cabeçalho
        (*head) = node;
    }

    template <typename T>
    Node<T>* searchNodebyValue(Node<T>* head, T value)
    {
        // Se o cabeçalho da lista for vazio, i.e, lista vazia 
        if (head == nullptr)
        {
            cout << "Empty list! Impossible to search value." << endl;
            return head;
        }
        // Se o valor buscado está no cabeçalho
        else if (head->Value == value)
        {
            // Retornamos o nó do cabeçalho
            return head;
        }
        // Caso contrário
        else
        {
            // Criação de um nó dinâmico
            Node<T>* current = head;

            // Percurso até o fim da lista
            while (current != nullptr & current->Value != value) current = current->ptrNext;
            
            // Se não foi encontrado o nó buscado
            if (current == nullptr)
            {
                cout << "Element not found, sorry." << endl;
                return current;
            }
            // Caso seja encontrado
            else
            {
                // Retornamos um ponteiro para o nó buscado
                return current;
            }
        }
    }

    template <typename T>
    void insertAfter(Node<T>* ptrLocation, T value)
    {
        // Se a localização do nó é vazia
        if (ptrLocation == NULL)
        {
            cout << "Location is NULL. Impossible to insert." << endl;
            return;
        }
        
        // Caso a localização seja válida, criamos o nó
        Node<T>* node = newNode(value);
        
        // Inserção do nó na posição desejada
        node->ptrNext = ptrLocation->ptrNext;
        node->ptrPrev = ptrLocation;
        
        ptrLocation->ptrNext = node;
        
        // Verificação de elementos após o nó adicionado. Se for o caso, efetuamos uma operação extra
        if (node->ptrNext != NULL) node->ptrNext->ptrPrev = node;
    }

    template <typename T>
    void insertBefore(Node<T>* ptrLocation, T value)
    {
        // Se a localização do nó é vazia
        if (ptrLocation == NULL)
        {
            cout << "Location is NULL. Impossible to insert." << endl;
            return;
        }

        // Caso a localização seja válida, criamos o nó
        Node<T>* node = newNode(value);

        // Verificação se a localização se refere ao primeiro nó
        if (ptrLocation->ptrPrev == nullptr)
        {
            // Inserção do nó para este caso
            ptrLocation->ptrPrev = node;
            node->ptrNext = ptrLocation;
            return;
        }
        // Caso contrário, efetuamos a devida iserção do nó
        Node<T>* ptrTemp = ptrLocation->ptrPrev;
        ptrTemp->ptrNext = node;
        node->ptrNext = ptrLocation;
        node->ptrPrev = ptrTemp;
    }

    template <typename T>
    void deleteNode(Node<T>** head, Node<T>* ptrDelete)
    {
        // Se o cabeçalho for vazio ou o ponteiro inválido
        if ((*head) == NULL || ptrDelete == NULL)
        {
            cout << "Can't remove it." << endl;
            return;
        }

        // Caso contrário, verifica-se se o nó a ser removido é o primeiro nó da lista
        if ((*head) == ptrDelete) (*head) = ptrDelete->ptrNext;
        // Verificação se existe nós a frente do nó a ser removido
        if (ptrDelete->ptrNext != NULL) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
        // Verificação se existe nós antes do nó a ser removido
        if (ptrDelete->ptrPrev != NULL) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
        // Exclusão do nó
        free(ptrDelete);
    }

    template <typename T>
    void freeList(Node<T>** head) 
    {
        // Deeleta o primero nó até não sobrar nenhum
        while (*head != nullptr) 
        {
            deleteNode(head, *head);
        }
    }

    template <typename T>
    void deleteNodebyValue(Node<T>** head, T value)
    {
        // Busca pelo nó com o valor a ser removido
        Node<T>* node = searchNodebyValue(*head, value);
        // Remove o nó encontrado
        deleteNode(head, node);
    }

    template <typename T>
    void printList(Node<T>* head)
    {
        // Se o cabeçalho for vazio, i.e., lista vazia
        if (head == NULL)
        {
            cout << "Empty list!" << endl;
        }
        // Caso o cabeçalho fornecido não seja para o primeiro nó da fila
        else if (head->ptrPrev != NULL)
        {
            cout << "Sorry, you're in the middle of list. Please try again with the head of the list." << endl;
        }
        else
        {
            // Criação de nó dinâmico
            Node<T>* current = head;

            cout << "Elements: \n";
            // Percurso até o fim da lista
            while (current != NULL)
            {
                // Impressão dos valores dos nós
                cout << current->Value << "  ";
                current = current->ptrNext;
            } 
            cout << endl;
        }
    }

    template <typename T>
    void swapValue(T& irefValue1, T& irefValue2)
    {
        T temp = irefValue1;
        irefValue1 = irefValue2;
        irefValue2 = temp;
    }

    // Instanciação explícita para os tipos inteiros
    template Node<int>* newNode(int);
    template void addElementEnd(Node<int>**, int);
    template void addElementFront(Node<int>**, int);
    template Node<int>* searchNodebyValue(Node<int>*, int);
    template void insertAfter(Node<int>*, int);
    template void insertBefore(Node<int>*, int);
    template void deleteNode(Node<int>**, Node<int>*);
    template void freeList(Node<int>**);
    template void deleteNodebyValue(Node<int>**, int);
    template void printList(Node<int>*);
    template void swapValue(int&, int&);

    // Instanciação explícita para os tipos float
    template Node<float>* newNode(float);
    template void addElementEnd(Node<float>**, float);
    template void addElementFront(Node<float>**, float);
    template Node<float>* searchNodebyValue(Node<float>*, float);
    template void insertAfter(Node<float>*, float);
    template void insertBefore(Node<float>*, float);
    template void deleteNode(Node<float>**, Node<float>*);
    template void freeList(Node<float>**);
    template void deleteNodebyValue(Node<float>**, float);
    template void printList(Node<float>*);
    template void swapValue(float&, float&);

    // Instanciação explícita para os tipos char
    template Node<char>* newNode(char);
    template void addElementEnd(Node<char>**, char);
    template void addElementFront(Node<char>**, char);
    template Node<char>* searchNodebyValue(Node<char>*, char);
    template void insertAfter(Node<char>*, char);
    template void insertBefore(Node<char>*, char);
    template void deleteNode(Node<char>**, Node<char>*);
    template void freeList(Node<char>**);
    template void deleteNodebyValue(Node<char>**, char);
    template void printList(Node<char>*);
    template void swapValue(char&, char&);

    // Instanciação explícita para os tipos BinaryTree::Node<int>*
    template Node<BinaryTree::Node<int>*>* newNode(BinaryTree::Node<int>*);
    template void addElementEnd(Node<BinaryTree::Node<int>*>**, BinaryTree::Node<int>*);
    template void deleteNode(Node<BinaryTree::Node<int>*>**, Node<BinaryTree::Node<int>*>*);

    // Instanciação explícita para os tipos BinaryTree::Node<float>*
    template Node<BinaryTree::Node<float>*>* newNode(BinaryTree::Node<float>*);
    template void addElementEnd(Node<BinaryTree::Node<float>*>**, BinaryTree::Node<float>*);
    template void deleteNode(Node<BinaryTree::Node<float>*>**, Node<BinaryTree::Node<float>*>*);

    // Instanciação explícita para os tipos BinaryTree::Node<char>*
    template Node<BinaryTree::Node<char>*>* newNode(BinaryTree::Node<char>*);
    template void addElementEnd(Node<BinaryTree::Node<char>*>**, BinaryTree::Node<char>*);
    template void deleteNode(Node<BinaryTree::Node<char>*>**, Node<BinaryTree::Node<char>*>*);

} // namespace LinkedList