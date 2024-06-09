#include <iostream>
#include <cstdlib>
#include <chrono>

#include "linkedList.h"
#include "SortingAlgorithm/sorting.h"
#include "binaryTree.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::cerr;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

int main() {
/*
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
*/

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

/*
   LinkedList::Node<int>* head1 = nullptr;
    for (int c = 1; c <= 10; c++) {
        addElementFront(&head1, c);
    }

    BinaryTree::Node<int>* tree;

    // Criar 100 árvores binárias, com 200000 nós cada
    // Analisar o tempo de cada tipo de busca
    for (int i = 0; i < 100; i++) {

        auto timeStart = high_resolution_clock::now();
        LinkedList::shuffleList(head1, 10);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << "Execution " << i + 1 << " shuffle: " << timeDuration.count() << " nanoseconds" << endl;

        // Cria a árvore com os valores embaralhados
        LinkedList::Node<int>* current = head1;
        tree = BinaryTree::createTreeNode<int>(current->Value);
        current = current->ptrNext;
        while (current != nullptr) {
            BinaryTree::insertNode(tree, current->Value);
            current = current->ptrNext;
        }

        // Gera um valor de busca aleatório
        int searchValue = rand() % 200000 + 1;

        // Medição do tempo para DFS
        auto timeStartDfs = high_resolution_clock::now();
        BinaryTree::dfsSearchNode<int>(tree, searchValue);
        auto timeStopDfs = high_resolution_clock::now();
        auto timeDurationDfs = duration_cast<nanoseconds>(timeStopDfs - timeStartDfs);
        cout << "Execution " << i + 1 << " DFS: " << timeDurationDfs.count() << " nanoseconds" << endl;

        // Medição do tempo para BFS
        auto timeStartBfs = high_resolution_clock::now();
        BinaryTree::bfsSearchNode<int>(tree, searchValue);
        auto timeStopBfs = high_resolution_clock::now();
        auto timeDurationBfs = duration_cast<nanoseconds>(timeStopBfs - timeStartBfs);
        cout << "Execution " << i + 1 << " BFS: " << timeDurationBfs.count() << " nanoseconds" << endl;

    }

*/

  srand(time(NULL));

    const int size = 10000;
    int values[size];
    LinkedList::Node<int>* head = nullptr;
    BinaryTree::Node<int>* tree = nullptr;

    for (int iteration = 1; iteration <= 100; ++iteration) {
        // Gerar um array com 200000 valores
        for (int i = 0; i < size; ++i) {
            values[i] = rand() % 1000000 + 1;
        }

        head = nullptr;
        tree = nullptr;

        // Medir o tempo de criação da lista ligada
        auto start = high_resolution_clock::now();
        for (int i = 0; i < size; ++i) {
            LinkedList::addElementEnd(&head, values[i]);
        }
        auto end = high_resolution_clock::now();
        auto durationList = duration_cast<nanoseconds>(end - start).count();
        cout << "Iteration " << iteration << "  List:  " << durationList << " nanoseconds" << endl;

        // Medir o tempo de criação da árvore binária de busca
        start = high_resolution_clock::now();
        tree = BinaryTree::createTreeNode<int>(values[0]);
        for (int i = 0; i < size; ++i) {
            BinaryTree::insertNode(tree, values[i]);
            
        }
        end = high_resolution_clock::now();
        auto durationTree = duration_cast<nanoseconds>(end - start).count();
        cout << "Iteration " << iteration << "  Tree:  " << durationTree << " nanoseconds" << endl;
        cout << endl;
    }

    return 0;

}