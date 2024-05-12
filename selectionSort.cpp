#include <iostream>
#include <cstdlib> 

#include "functions.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

void selectionSort_Aux(Node* ptrAtual)
{
    // Condição de parada (final da lista)
    if (ptrAtual->ptrNext == NULL) return;

    // Criação de nó dinâmico
    Node* current = ptrAtual;

    // Percurso até o fim da lista
    while (current != NULL)
    {
        // Se algum nó for menor que o atual, atualizamos o atual
        if (current->iValue < ptrAtual->iValue) swapValue(ptrAtual->iValue,ptrAtual->iValue);
        current = current->ptrNext;
    }

    // Chamamos recursivamente a função
    selectionSort_Aux(ptrAtual->ptrNext);
}

void selectionSort(Node* head)
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
        selectionSort_Aux(head);
    }
}

void optimizedSelectionSort_Aux(Node* ptrAtual)
{
    // Condição de parada (final da lista)
    if (ptrAtual->ptrNext == NULL) return;

    // Criação de nó dinâmico
    Node* current = ptrAtual;
    // Criação de nó pivô
    Node* ptrPivot = ptrAtual;

    // Percurso até o fim da lista
    while (current != NULL)
    {
        // Se algum nó for menor que o pivô, atualizamos o pivô
        if (current->iValue < ptrPivot->iValue) ptrPivot = current;
        current = current->ptrNext;
    }

    // Se o pivô não for o nó atual, efetuamos a troca
    if (ptrPivot != ptrAtual) swapValue(ptrPivot->iValue,ptrAtual->iValue);

    // Chamamos recursivamente a função
    selectionSort_Aux(ptrAtual->ptrNext);
}

void optimizedSelectionSort(Node* head)
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
        optimizedSelectionSort_Aux(head);
    }
}