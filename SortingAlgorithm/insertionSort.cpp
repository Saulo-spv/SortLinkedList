#include <iostream>
#include <cstdlib> 

#include "../linkedList.h"
#include "sorting.h"

using namespace std;
using LinkedList::swapValue;

namespace Sorting
{

    template <typename T>
    void insertionSort(Node<T>* head) {
        // Condição de lista vazia ou unitária
        if(head == NULL || head->ptrNext == NULL) {
            cout << "It can't be ordened" << endl;
            return;
        }

        Node<T>* order = head->ptrNext; // Começa do segundo nó
        Node<T>* temp = NULL;
        while(order != NULL){
            Node<T>* current = order->ptrPrev; // Inicia do nó anterior a order
            Node<T>* temp = order;
            while(current != NULL && temp->Value < current->Value){
                swapValue(current->Value, temp->Value);
                current = current->ptrPrev;
                temp = temp->ptrPrev; // Move o ponteiro order para trás também
            }
            order = order->ptrNext; // Move order para o próximo nó
        }
    }

    // Instanciação explícita para os tipos inteiros
    template void insertionSort<int>(LinkedList::Node<int>*);

    // Instanciação explícita para os tipos float
    template void insertionSort<float>(LinkedList::Node<float>*);

    // Instanciação explícita para os tipos char
    template void insertionSort<char>(LinkedList::Node<char>*);

} // namespace Sorting