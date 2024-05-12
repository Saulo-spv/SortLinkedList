#include <iostream>
#include <cstdlib> 

#include "../linkedList.h"
#include "sorting.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

void bubbleSort(Node* head) {

    // Condição de lista vazia ou unitária
    if(head == NULL || head->ptrNext == NULL) {
        cout << "It can't be ordened" << endl;
        return;
    }

    Node* currentOuter = head; // Ponteiro para percorrer a lista externamente
    Node* currentInner = NULL; // Ponteiro para percorrer a lista internamente

    // Percorre a lista com dois loops
    while(currentOuter->ptrNext != NULL){
        currentInner = head;
        while(currentInner->ptrNext != NULL){
            // Compara e troca os elementos se necessário
            if(currentInner->iValue > currentInner->ptrNext->iValue){
                swapValue(currentInner->iValue, currentInner->ptrNext->iValue);
            }
            currentInner = currentInner->ptrNext;
        }
        currentOuter = currentOuter->ptrNext;
    }
}

void optimizedBubbleSort(Node* head) {

    // Condição de lista vazia ou unitária
    if(head == NULL || head->ptrNext == NULL) {
        cout << "It can't be ordened" << endl;
        return;
    }

    // Inicializa o ponteiro 'last' e o coloca no final da lista
    Node* last = head;
    while(last->ptrNext != NULL) {
        last = last->ptrNext;
    }

    Node* current = NULL;

    // Inicializa um flag que indica se ouve trocas naquela iteração
    bool swapped = true;

    // Enquanto não houver trocas em alguma iteração
    while(swapped){
        current = head;
        swapped = false;

        // Percorre a lista e compara elementos adjacentes
        while(current != last){
            // Se o valor atual for maior que o próximo, troca os valores
            if(current->iValue > current->ptrNext->iValue){
                swapValue(current->iValue, current->ptrNext->iValue);
                // Define 'swapped' como verdadeiro, indicando que houve uma troca
                swapped = true;
            }
            current = current->ptrNext;
        }
        // Atualiza 'last' para o nó anterior, pois os proximos ja estão ordenados
        last = last->ptrPrev;
    }
}