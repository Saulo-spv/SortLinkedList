#include <iostream>
#include <cstdlib> 

#include "../linkedList.h"
#include "sorting.h"

using namespace std;
using LinkedList::swapValue;

namespace Sorting
{

    template <typename T>
    void selectionSort(Node<T>* head)
    {
        // Condição de lista vazia ou unitária
        if (head == NULL || head->ptrNext == NULL)
        {
            cout << "It can't be ordened" << endl;
            return;
        }

        // Criação de nós para controle dos loops
        Node<T>* outerLoop = head;
        Node<T>* innerLoop = NULL;

        // Percurso até o fim da lista
        while (outerLoop != NULL)
        {
            innerLoop = outerLoop->ptrNext;

            while (innerLoop != NULL)
            {
            // Se algum nó for menor que o atual, atualizamos o atual
            if (outerLoop->Value > innerLoop->Value) swapValue(outerLoop->Value,innerLoop->Value);
            innerLoop = innerLoop->ptrNext;
            }

            outerLoop = outerLoop->ptrNext;
        }
    }

    template <typename T>
    void optimizedSelectionSort(Node<T>* head)
    {
        // Condição de lista vazia ou unitária
        if (head == NULL || head->ptrNext == NULL)
        {
            cout << "It can't be ordened" << endl;
            return;
        }

        // Criação de nós para controle dos loops
        Node<T>* outerLoop = head;
        Node<T>* innerLoop = NULL;
        
        // Criação de nó pivô
        Node<T>* ptrPivot = head;

        // Percurso até o fim da lista
        while (outerLoop != NULL)
        {
            // Atualização dos paramêtros
            innerLoop = outerLoop->ptrNext;
            ptrPivot = outerLoop;

            while (innerLoop != NULL)
            {
            // Se algum nó for menor que o pivô, atualizamos o pivô
            if (ptrPivot->Value > innerLoop->Value) ptrPivot = innerLoop;
            innerLoop = innerLoop->ptrNext;
            }

            // Troca de valores
            swapValue(ptrPivot->Value,outerLoop->Value);

            outerLoop = outerLoop->ptrNext;
        }
    }

    // Instanciação explícita para os tipos inteiros
    template void selectionSort<int>(LinkedList::Node<int>*);
    template void optimizedSelectionSort<int>(LinkedList::Node<int>*);

    // Instanciação explícita para os tipos float
    template void optimizedSelectionSort<float>(LinkedList::Node<float>*);

    // Instanciação explícita para os tipos char
    template void selectionSort<char>(LinkedList::Node<char>*);
    template void optimizedSelectionSort<char>(LinkedList::Node<char>*);

} // namespace Sorting