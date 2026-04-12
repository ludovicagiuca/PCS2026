#include <iostream>
#include <vector>
#include <algorithm>
#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main() {
    randfiller rf;
    timecounter tc;

    // Ciclo sulle dimensioni: 4, 8, 16, ..., 8192
    for (int size = 4; size <= 8192; size *= 2) {
        
        std::vector<int> v_base(size);
        rf.fill(v_base, -10000, 10000);

        std::cout << "Dimensione: " << size << std::endl;

        // BUBBLE SORT
        std::vector<int> v1 = v_base;
        tc.tic();
        bubble_sort(v1);
        double secs = tc.toc();
        std::cout << "bubblesort:" << secs << std::endl;

        // SELECTION SORT
        std::vector<int> v2 = v_base;
        tc.tic();
        selection_sort(v2);
        double secs1 = tc.toc();
        std::cout << "selectionsort:" << secs1 << std::endl;

        // INSERTION SORT
        std::vector<int> v3 = v_base;
        tc.tic();
        insertion_sort(v3);
        double secs2 = tc.toc();
        std::cout << "insertionsort:" << secs2 << std::endl;

        // STD::SORT
        std::vector<int> v4 = v_base;
        tc.tic();
        std::sort(v4.begin(), v4.end());
        double secs3 = tc.toc();
        std::cout << "standardsort:" << secs3 << std::endl;
        
        std::cout << std::endl; // Spazio tra una dimensione e l'altra
    }

    return 0;
}