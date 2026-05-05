#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include<cstdlib>
#include "sort.hpp"
#include "bubblesort.hpp"
#include "randfiller.h"


bool bubble_test() {
    randfiller rf;
    const int NUM_ITER = 100;

    srand(unsigned(time(NULL))); //creare un generatore di numeri casuali basandoti sull'epoch corrente


    for (int i = 0; i < NUM_ITER; ++i) {
        // Scelta della dimensione (es. tra 10 e 500)
        int size = (std::rand() % 491) +10; //int size = (std::rand() % (max - min + 1)) + min;

        std::vector<int> v(size);
        // Riempimento con numeri positivi e negativi
        rf.fill(v, -1000, 1000);

        bubble_sort(v);

        // Verifica
        if (!is_sorted(v)) {
            std::cerr << "Vettore non ordinato alla iterazione " << i << std::endl;
            return false; 
        }
    }
    
    return true; // Tutti i 100 vettori sono stati ordinati correttamente
}

bool string_bubble_test() {
    // Creazione di un vettore di stringhe scelte a piacere
    std::vector<std::string> v = {
        "penna", "calcolatrice", "acqua", "fogli", "matita", 
        "computer", "astuccio", "occhiali"
    };

    bubble_sort(v);

    // Verifica dell'ordinamento
    if (!is_sorted(v)) {
        std::cerr << "Vettore di stringhe non ordinato correttamente" << std::endl;
        return false;
    }

    return true;
}

int main() {
    bool all_passed = true;

    if (bubble_test()) {
        std::cout << "Test numeri: PASS" << std::endl;
    } else {
        std::cout << "Test numeri: FAIL" << std::endl;
        all_passed = false;
    }

    if (string_bubble_test()) {
        std::cout << "Test stringhe: PASS" << std::endl;
    } else {
        std::cout << "Test stringhe: FAIL" << std::endl;
        all_passed = false;
    }

    // Se all_passed è ancora true, restituisce EXIT_SUCCESS (0)
    // Altrimenti restituisce EXIT_FAILURE (solitamente 1)
    if (all_passed) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}