#include <iostream>
#include "../linkedList.h"
#include "sorting.h"

using namespace std;
using namespace LinkedList;

namespace Sorting
{
    // Função auxiliar para retroceder k posições em uma lista duplamente encadeada a partir de um nó dado.
    template <typename T>
    Node<T>* regresseK(Node<T>* node, int gap) {
        for (int c = 0; c < gap; c++) {
            if (node->ptrPrev != nullptr) {
                node = node->ptrPrev;
            } else {
                return nullptr; // Retorna nullptr se chegou ao início da lista
            }
        }
        return node;
    }

    template <typename T>
    void shellSort(Node<T>* head) {
        // Condição de lista vazia ou unitária
        if(head == NULL || head->ptrNext == NULL) {
            cout << "It can't be ordened" << endl;
            return;
        }

        int iSize = 0;
        Node<T>* temp = head;

        // Encontra o comprimento da lista
        while (temp != nullptr) {
            iSize++;
            temp = temp->ptrNext;
        }

        Node<T>* current;
        // Mude para a sequência de gap desejada
        for (int gap = iSize / 2; gap > 0; gap /= 2) {
            // Itera sobre os nós da lista para o gap atual
            for (Node<T>* start = head; start != nullptr; start = start->ptrNext) {
                current = start;
                temp = regresseK(current, gap);
                
                // Insertion Sort modificado para sublistas espaçadas pelo gap
                while (temp != nullptr && temp->Value > current->Value) {
                    swapValue(temp->Value, current->Value);
                    current = temp;
                    temp = regresseK(current, gap); // Continua retrocedendo 'gap' posições
                }
            }
        }
    }

    // Instanciação explícita para os tipos inteiros
    template Node<int>* regresseK(Node<int>*, int);
    template void shellSort(Node<int>*);

    // Instanciação explícita para os tipos float
    template Node<float>* regresseK(Node<float>*, int);
    template void shellSort(Node<float>*);
    
    // Instanciação explícita para os tipos char
    template Node<char>* regresseK(Node<char>*, int);
    template void shellSort(Node<char>*);

} // namespace Sorting
