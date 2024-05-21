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
        // Condição de lista vazia ou unitária
        if(head == NULL || head->ptrNext == NULL) {
            cout << "It can't be ordened" << endl;
            return;
        }

        int iSize = 0;
        Node* temp = head;

        // Encontra o comprimento da lista
        while (temp != nullptr) {
            iSize++;
            temp = temp->ptrNext;
        }

        cout << "Lista inicial:" << endl;
        printList(head);

        Node* current;
        // Shell sort com sequência de gaps (n/2, n/4 ..., 1)
        for (int gap = iSize / 2; gap > 0; gap /= 2) {
            // Itera sobre os nós da lista para o gap atual
            for (Node* start = head; start != nullptr; start = start->ptrNext) {
                current = start;
                temp = regresseK(current, gap);
                
                // Insertion Sort modificado para sublistas espaçadas pelo gap
                while (temp != nullptr && temp->iValue > current->iValue) {
                    swapValue(temp->iValue, current->iValue);
                    current = temp;
                    temp = regresseK(current, gap); // Continua retrocedendo 'gap' posições
                }
            }
            // Imprime o estado da lista após cada gap
            cout << "Lista após gap " << gap << ": " << endl;
            printList(head);
        }
    }
} // namespace Sorting
