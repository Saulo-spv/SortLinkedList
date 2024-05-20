#include <iostream>
#include <cstdlib> 
#include <ctime>

#include "../linkedList.h"
#include "sorting.h"

using namespace std;
using LinkedList::swapValue;

namespace Sorting
{

    // Função para verificar se a lista está ordenada
    bool isSorted(Node* head) {
        Node* current = head;
        while (current->ptrNext != nullptr) {
            if (current->iValue > current->ptrNext->iValue)
                return false;
            current = current->ptrNext;
        }
        return true;
    }

    // Função de embaralhamento
    void shuffleList(Node* head, int size) {

        Node* current = head;
        Node* nodeSwap = nullptr;

        // Embaralhamento dos elementos
        for (int c = 0; c < size; c++) {
            // Gera um índice aleatório j entre 0 e size - c
            int j = rand() % (size - c);

            nodeSwap = current;
            for(int k = 1; k <= j; k++){
                nodeSwap = nodeSwap->ptrNext;
            }

            // Troca os valores dos nós
            swapValue(current->iValue, nodeSwap->iValue);

            current = current->ptrNext;
        }
    }

    // Função Bogo Sort
    void bogoSort(Node* head) {
        // Inicializa a semente para a função rand()
        srand(time(nullptr));

        Node* current = head;
        int size = 0;
        // Calcula o tamanho da lista
        while (current != nullptr) {
            size++;
            current = current->ptrNext;
        }

        while (!isSorted(head)) {
            // Embaralha os elementos
            shuffleList(head, size);
        }
    }

} // namespace Sorting