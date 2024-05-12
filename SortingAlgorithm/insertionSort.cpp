#include <iostream>
#include <cstdlib> 

#include "../linkedList.h"
#include "sorting.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

void insertionSort(Node* head) {
    // Condição de lista vazia ou unitária
    if(head == NULL || head->ptrNext == NULL) {
        cout << "It can't be ordened" << endl;
        return;
    }

    Node* order = head->ptrNext; // Começa do segundo nó
    Node* temp = NULL;
    while(order != NULL){
        Node* current = order->ptrPrev; // Inicia do nó anterior a order
        Node* temp = order;
        while(current != NULL && temp->iValue < current->iValue){
            swapValue(current->iValue, temp->iValue);
            current = current->ptrPrev;
            temp = temp->ptrPrev; // Move o ponteiro order para trás também
        }
        order = order->ptrNext; // Move order para o próximo nó
    }
}
