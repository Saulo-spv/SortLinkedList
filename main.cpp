#include <iostream>
#include <cstdlib> 
#include <chrono>

#include "linkedList.h"
#include "SortingAlgorithm/sorting.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

int main() {
    Node<float>* head1 = nullptr;

    addElementFront(&head1, 92.55f);
    addElementFront(&head1, 1.69f);
    addElementFront(&head1, 67.69f);
    addElementFront(&head1, 54.0f);
    addElementFront(&head1, 62.0f);
    addElementFront(&head1, 56.9f);
    addElementFront(&head1, 72.0f);
    addElementFront(&head1, 77.77f);
    addElementFront(&head1, 59.003f);
    addElementFront(&head1, 78.0f);   

    Sorting::shellSort(head1); // Use outro algoritmo de ordenação, caso queira

    printList(head1);

    // Libera a memória da lista
    freeList(&head1); 

/*
    // Inicializa a semente para a função rand()
    srand(time(nullptr));

    for (int exec = 0; exec < 100; exec++) {
        // Criação do cabeçalho da lista
        head1 = nullptr;

        for (int c = 1; c <= 10000; c++) {
            int iNum = 1 + (rand() % 100);
            addElementFront(&head1, iNum);
        }

        // Ordena a lista
        auto timeStart = high_resolution_clock::now();

        Sorting::shellSort(head1); // Use outro algoritmo de ordenação, caso queira

        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << "Execution " << exec + 1 << ": " << timeDuration.count() << " nanoseconds" << endl;

        // Libera a memória da lista
        freeList(&head1);
    }
*/


    return 0;
}
