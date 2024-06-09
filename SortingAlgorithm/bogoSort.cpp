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
            LinkedList::shuffleList(head, size);
        }
    }

    // Instanciação explícita para os tipos inteiros
    template bool isSorted(LinkedList::Node<int>*);
    template void bogoSort(Node<int>*);

    // Instanciação explícita para os tipos float
    template bool isSorted(LinkedList::Node<float>*);
    template void bogoSort(Node<float>*);

    // Instanciação explícita para os tipos char
    template bool isSorted(LinkedList::Node<char>*);
    template void bogoSort(Node<char>*);

} // namespace Sorting