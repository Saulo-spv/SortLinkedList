#include <iostream>
#include <cstdlib>

#include "linkedList.h"
#include "SortingAlgorithm/sorting.h"

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
    template Node<int>* newNode<int>(int);
    template void addElementEnd<int>(Node<int>**, int);
    template void addElementFront<int>(Node<int>**, int);
    template Node<int>* searchNodebyValue<int>(Node<int>*, int);
    template void insertAfter<int>(Node<int>*, int);
    template void insertBefore<int>(Node<int>*, int);
    template void deleteNode<int>(Node<int>**, Node<int>*);
    template void freeList<int>(Node<int>**);
    template void deleteNodebyValue<int>(Node<int>**, int);
    template void printList<int>(Node<int>*);
    template void swapValue<int>(int&, int&);

    // Instanciação explícita para os tipos float
    template Node<float>* newNode<float>(float);
    template void addElementEnd<float>(Node<float>**, float);
    template void addElementFront<float>(Node<float>**, float);
    template Node<float>* searchNodebyValue<float>(Node<float>*, float);
    template void insertAfter<float>(Node<float>*, float);
    template void insertBefore<float>(Node<float>*, float);
    template void deleteNode<float>(Node<float>**, Node<float>*);
    template void freeList<float>(Node<float>**);
    template void deleteNodebyValue<float>(Node<float>**, float);
    template void printList<float>(Node<float>*);
    template void swapValue<float>(float&, float&);

    // Instanciação explícita para os tipos char
    template Node<char>* newNode<char>(char);
    template void addElementEnd<char>(Node<char>**, char);
    template void addElementFront<char>(Node<char>**, char);
    template Node<char>* searchNodebyValue<char>(Node<char>*, char);
    template void insertAfter<char>(Node<char>*, char);
    template void insertBefore<char>(Node<char>*, char);
    template void deleteNode<char>(Node<char>**, Node<char>*);
    template void freeList<char>(Node<char>**);
    template void deleteNodebyValue<char>(Node<char>**, char);
    template void printList<char>(Node<char>*);
    template void swapValue<char>(char&, char&);

} // namespace LinkedList