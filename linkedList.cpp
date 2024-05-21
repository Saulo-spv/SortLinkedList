#include <iostream>
#include <cstdlib>

#include "linkedList.h"
#include "SortingAlgorithm/sorting.h"

using namespace std;

namespace LinkedList
{

    Node* newNode(int iValue)
    {
        // Criação do nó
        Node* node = (Node*) malloc(sizeof(Node));
        
        // Caso a memória seja alocada com sucesso
        if (node != NULL)
        {
            // Inicialização dos parâmetros
            node->iValue = iValue;
            node->ptrPrev = NULL;
            node->ptrNext = NULL;
            return node;
        }
        
        return NULL;
    }

    void addElementEnd(Node** head, int iValue)
    {
        // Criação do nó
        Node* node = newNode(iValue);
        
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
            Node* current = (*head);

            // Percurso até o fim da lista
            while (current->ptrNext != NULL) current = current->ptrNext;

            // Inserção do nó
            node->ptrPrev = current;
            current->ptrNext = node;
        }
    }

    void addElementFront(Node** head, int iValue)
    {
        // Criação do nó
        Node* node = newNode(iValue);
        
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

    Node* searchNodebyValue(Node* head, int iValue)
    {
        // Se o cabeçalho da lista for vazio, i.e, lista vazia 
        if (head == nullptr)
        {
            cout << "Empty list! Impossible to search value." << endl;
            return head;
        }
        // Se o valor buscado está no cabeçalho
        else if (head->iValue == iValue)
        {
            // Retornamos o nó do cabeçalho
            return head;
        }
        // Caso contrário
        else
        {
            // Criação de um nó dinâmico
            Node* current = head;

            // Percurso até o fim da lista
            while (current != nullptr & current->iValue != iValue) current = current->ptrNext;
            
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

    void insertAfter(Node* ptrLocation, int iValue)
    {
        // Se a localização do nó é vazia
        if (ptrLocation == NULL)
        {
            cout << "Location is NULL. Impossible to insert." << endl;
            return;
        }
        
        // Caso a localização seja válida, criamos o nó
        Node* node = newNode(iValue);
        
        // Inserção do nó na posição desejada
        node->ptrNext = ptrLocation->ptrNext;
        node->ptrPrev = ptrLocation;
        
        ptrLocation->ptrNext = node;
        
        // Verificação de elementos após o nó adicionado. Se for o caso, efetuamos uma operação extra
        if (node->ptrNext != NULL) node->ptrNext->ptrPrev = node;
    }

    void insertBefore(Node* ptrLocation, int iValue)
    {
        // Se a localização do nó é vazia
        if (ptrLocation == NULL)
        {
            cout << "Location is NULL. Impossible to insert." << endl;
            return;
        }

        // Caso a localização seja válida, criamos o nó
        Node* node = newNode(iValue);

        // Verificação se a localização se refere ao primeiro nó
        if (ptrLocation->ptrPrev == nullptr)
        {
            // Inserção do nó para este caso
            ptrLocation->ptrPrev = node;
            node->ptrNext = ptrLocation;
            return;
        }
        // Caso contrário, efetuamos a devida iserção do nó
        Node* ptrTemp = ptrLocation->ptrPrev;
        ptrTemp->ptrNext = node;
        node->ptrNext = ptrLocation;
        node->ptrPrev = ptrTemp;
    }

    void deleteNode(Node** head, Node* ptrDelete)
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

    void freeList(Node** head) 
    {
        // Deeleta o primero nó até não sobrar nenhum
        while (*head != nullptr) 
        {
            deleteNode(head, *head);
        }
    }

    void deleteNodebyValue(Node** head, int iValue)
    {
        // Busca pelo nó com o valor a ser removido
        Node* node = searchNodebyValue(*head, iValue);
        // Remove o nó encontrado
        deleteNode(head, node);
    }

    void printList(Node* head)
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
            Node* current = head;

            cout << "Elements: \n";
            // Percurso até o fim da lista
            while (current != NULL)
            {
                // Impressão dos valores dos nós
                cout << current->iValue << "  ";
                current = current->ptrNext;
            } 
            cout << endl;
        }
    }

    void swapValue(int& irefValue1, int& irefValue2)
    {
        if (irefValue1 == irefValue2) return;

        irefValue1 ^= irefValue2;
        irefValue2 ^= irefValue1;
        irefValue1 ^= irefValue2;
    }

} // namespace LinkedList