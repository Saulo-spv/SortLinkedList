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
    template <typename T>
    bool isSorted(Node<T>* head) {
        Node<T>* current = head;
        while (current->ptrNext != nullptr) {
            if (current->Value > current->ptrNext->Value)
                return false;
            current = current->ptrNext;
        }
        return true;
    }

    // Função de embaralhamento
    template <typename T>
    void shuffleList(Node<T>* head, int size) {

        Node<T>* current = head;
        Node<T>* nodeSwap = nullptr;

        // Embaralhamento dos elementos
        for (int c = 0; c < size; c++) {
            // Gera um índice aleatório j entre 0 e size - c
            int j = rand() % (size - c);

            nodeSwap = current;
            for(int k = 1; k <= j; k++){
                nodeSwap = nodeSwap->ptrNext;
            }

            // Troca os valores dos nós
            swapValue(current->Value, nodeSwap->Value);

            current = current->ptrNext;
        }
    }

    // Função Bogo Sort
    template <typename T>
    void bogoSort(Node<T>* head) {
        // Inicializa a semente para a função rand()
        srand(time(nullptr));

        Node<T>* current = head;
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

    // Instanciação explícita para os tipos inteiros
    template bool isSorted<int>(LinkedList::Node<int>*);
    template void shuffleList<int>(Node<int>*, int);
    template void bogoSort<int>(Node<int>*);

    // Instanciação explícita para os tipos float
    template bool isSorted<float>(LinkedList::Node<float>*);
    template void shuffleList<float>(Node<float>*, int);
    template void bogoSort<float>(Node<float>*);

    // Instanciação explícita para os tipos char
    template void shuffleList<char>(Node<char>*, int);
    template bool isSorted<char>(LinkedList::Node<char>*);
    template void bogoSort<char>(Node<char>*);

} // namespace Sorting