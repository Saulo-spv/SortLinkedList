#include <iostream>
#include <cstdlib> 

#include "../linkedList.h"
#include "sorting.h"

using namespace std;
using LinkedList::swapValue;

namespace Sorting
{
    template <typename T>
    void bubbleSort(Node<T>* head) {

        // Condição de lista vazia ou unitária
        if(head == NULL || head->ptrNext == NULL) {
            cout << "It can't be ordened" << endl;
            return;
        }

        Node<T>* currentOuter = head; // Ponteiro para percorrer a lista externamente
        Node<T>* currentInner = NULL; // Ponteiro para percorrer a lista internamente

        // Percorre a lista com dois loops
        while(currentOuter->ptrNext != NULL){
            currentInner = head;
            while(currentInner->ptrNext != NULL){
                // Compara e troca os elementos se necessário
                if(currentInner->Value > currentInner->ptrNext->Value){
                    swapValue(currentInner->Value, currentInner->ptrNext->Value);
                }
                currentInner = currentInner->ptrNext;
            }
            currentOuter = currentOuter->ptrNext;
        }
    }

    template <typename T>
    void optimizedBubbleSort(Node<T>* head) {

        // Condição de lista vazia ou unitária
        if(head == NULL || head->ptrNext == NULL) {
            cout << "It can't be ordened" << endl;
            return;
        }

        // Inicializa o ponteiro 'last' e o coloca no final da lista
        Node<T>* last = head;
        while(last->ptrNext != NULL) {
            last = last->ptrNext;
        }

        Node<T>* current = NULL;

        // Inicializa um flag que indica se ouve trocas naquela iteração
        bool swapped = true;

        // Enquanto não houver trocas em alguma iteração
        while(swapped){
            current = head;
            swapped = false;

            // Percorre a lista e compara elementos adjacentes
            while(current != last){
                // Se o valor atual for maior que o próximo, troca os valores
                if(current->Value > current->ptrNext->Value){
                    swapValue(current->Value, current->ptrNext->Value);
                    // Define 'swapped' como verdadeiro, indicando que houve uma troca
                    swapped = true;
                }
                current = current->ptrNext;
            }
            // Atualiza 'last' para o nó anterior, pois os proximos ja estão ordenados
            last = last->ptrPrev;
        }
    }

    // Instanciação explícita para os tipos inteiros
    template void bubbleSort<int>(LinkedList::Node<int>*);
    template void optimizedBubbleSort<int>(LinkedList::Node<int>*);

    // Instanciação explícita para os tipos float
    template void bubbleSort<float>(LinkedList::Node<float>*);
    template void optimizedBubbleSort<float>(LinkedList::Node<float>*);
    
    // Instanciação explícita para os tipos char
    template void bubbleSort<char>(LinkedList::Node<char>*);
    template void optimizedBubbleSort<char>(LinkedList::Node<char>*);

} // namespace Sorting