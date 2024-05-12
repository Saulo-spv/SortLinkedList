#include <iostream>
#include <cstdlib> 
#include <chrono>

#include "functions.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

int main(){

    Node* head1 = NULL;

    for(int exec = 0; exec < 1000; exec++) {
        // Criação do cabeçaço da lista
        head1 = NULL;

        for(int c = 1; c <= 1000; c++) {
            int iNum = rand();
            addElementFront(&head1, iNum);
        }

        // Ordena a lista
        auto timeStart = high_resolution_clock::now();
        insertionSort(head1);
        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << endl;
    }

    return 0;
}
