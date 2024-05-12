#include <iostream>
#include <cstdlib> 

#include "../linkedList.h"
#include "sorting.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

void selectionSort(Node* head)
{
    // Condição de lista vazia ou unitária
    if (head == NULL || head->ptrNext == NULL)
    {
        cout << "It can't be ordened" << endl;
        return;
    }

    // Criação de nós para controle dos loops
    Node* outerLoop = head;
    Node* innerLoop = NULL;

    // Percurso até o fim da lista
    while (outerLoop != NULL)
    {
        innerLoop = outerLoop->ptrNext;

        while (innerLoop != NULL)
        {
        // Se algum nó for menor que o atual, atualizamos o atual
        if (outerLoop->iValue > innerLoop->iValue) swapValue(outerLoop->iValue,innerLoop->iValue);
        innerLoop = innerLoop->ptrNext;
        }

        outerLoop = outerLoop->ptrNext;
    }
}


void optimizedSelectionSort(Node* head)
{
    // Condição de lista vazia ou unitária
    if (head == NULL || head->ptrNext == NULL)
    {
        cout << "It can't be ordened" << endl;
        return;
    }

    // Criação de nós para controle dos loops
    Node* outerLoop = head;
    Node* innerLoop = NULL;
    
    // Criação de nó pivô
    Node* ptrPivot = head;

    // Percurso até o fim da lista
    while (outerLoop != NULL)
    {
        // Atualização dos paramêtros
        innerLoop = outerLoop->ptrNext;
        ptrPivot = outerLoop;

        while (innerLoop != NULL)
        {
        // Se algum nó for menor que o pivô, atualizamos o pivô
        if (ptrPivot->iValue > innerLoop->iValue) ptrPivot = innerLoop;
        innerLoop = innerLoop->ptrNext;
        }

        // Troca de valores
        swapValue(ptrPivot->iValue,outerLoop->iValue);

        outerLoop = outerLoop->ptrNext;
    }
}
