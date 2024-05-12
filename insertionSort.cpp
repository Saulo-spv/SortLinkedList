#include <iostream>
#include <cstdlib> 

#include "functions.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

void insertionSort(Node* head) {
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
