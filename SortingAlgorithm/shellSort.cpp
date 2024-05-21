// Implementação do Shell Sort para uma lista duplamente encadeada.
// O algoritmo utiliza uma sequência de gaps decrescentes para ordenar
// sublistas espaçadas pelo gap. Começa encontrando o comprimento da lista
// e utiliza a função regresseK para retroceder k posições na lista a partir de um nó dado.
// Durante a ordenação, funciona de maneira semelhante ao Insertion Sort,
// movendo os elementos maiores para a posição correta dentro de suas sublistas ordenadas.
// A cada iteração, o gap é reduzido até atingir 1, garantindo que
// a lista seja finalmente ordenada de forma crescente.

#include <iostream>
#include "../linkedList.h"
#include "sorting.h"

using namespace std;
using namespace LinkedList;

namespace Sorting
{
    // Função auxiliar para retroceder k posições em uma lista duplamente encadeada a partir de um nó dado.
    Node* regresseK(Node* node, int gap) {
        for (int c = 0; c < gap; c++) {
            if (node->ptrPrev != nullptr) {
                node = node->ptrPrev;
            } else {
                return nullptr; // Retorna nullptr se chegou ao início da lista
            }
        }
        return node;
    }

    void shellSort(Node* head) {
        int iSize = 0;
        Node* temp = head;

        // Encontra o comprimento da lista
        while (temp != nullptr) {
            iSize++;
            temp = temp->ptrNext;
        }

        // Shell sort com sequência de gaps (n/64, n/4096 ..., 1)
        for (int gap = iSize / 64; gap > 0; gap /= 64) {
            // Itera sobre os nós da lista para o gap atual
            for (Node* start = head; start != nullptr; start = start->ptrNext) {
                Node* current = start;
                Node* temp = regresseK(current, gap);
                
                // Insertion Sort modificado para sublistas espaçadas pelo gap
                while (temp != nullptr && temp->iValue > current->iValue) {
                    swapValue(temp->iValue, current->iValue);
                    current = temp;
                    temp = regresseK(current, gap); // Continua retrocedendo 'gap' posições
                }
            }
        }
    }
} // namespace Sorting
