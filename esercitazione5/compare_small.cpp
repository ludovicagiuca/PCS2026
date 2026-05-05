#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "different_quicksort.hpp"
#include "randfiller.h"
#include "timecounter.h"


int main() {
    randfiller rf;
    timecounter tc;

    const int num_vettori = 100;

    bool cut_trovato = false;

    for (int size = 5; size <= 100; size += 5) {
        
        //contenitore di 100 vettori 
        std::vector<std::vector<int>> dataset(num_vettori, std::vector<int>(size));

        //inizializzazione con numeri casuali
        for (int i = 0; i < num_vettori; ++i) {
            rf.fill(dataset[i], -10000, 10000); 
        }

        std::cout << "\n" << std::endl;
        std::cout << "ANALISI DIMENSIONE: " << size << std::endl;

        //BubbleSort
        auto dataset_copy1 = dataset; //creiamo una copia per non modificare il dataset iniziale

        tc.tic(); // Inizio misurazione all'esterno del ciclo for 
        for (int i = 0; i < num_vettori; ++i) {
            bubble_sort(dataset_copy1[i]);
        }
        double tempo_totale1 = tc.toc();

        //Calcolo della media 
        double tempo_medio1 = tempo_totale1 / num_vettori;
        std::cout << "\n" << std::endl;
        std::cout << "BubbleSort tempo medio: " << tempo_medio1 << " s" << std::endl;

        //SelectionSort
        auto dataset_copy2 = dataset;

        tc.tic();
        for (int i = 0; i < num_vettori; ++i) {
            selection_sort(dataset_copy2[i]);
        }
        double tempo_totale2 = tc.toc();

        double tempo_medio2 = tempo_totale2 / num_vettori;
        std::cout << "SelectionSort tempo medio: " << tempo_medio2 << " s" << std::endl;

        //InsertionSort
        auto dataset_copy3 = dataset;

        tc.tic();
        for (int i = 0; i < num_vettori; ++i) {
            insertion_sort(dataset_copy3[i]);
        }
        double tempo_totale3 = tc.toc();

        double tempo_medio3 = tempo_totale3 / num_vettori;
        std::cout << "InsertionSort tempo medio: " << tempo_medio3 << " s" << std::endl;

        //QuickSort
        auto dataset_copy4 = dataset;

        tc.tic();
        for (int i = 0; i < num_vettori; ++i) {
            quick_sort(dataset_copy4[i], 0, size - 1);
        }
        double tempo_totale4 = tc.toc();

        double tempo_medio4 = tempo_totale4 / num_vettori;
        std::cout << "QuickSort tempo medio: " << tempo_medio4 << " s" << std::endl;

        //MergeSort
        auto dataset_copy5 = dataset;

        tc.tic();
        for (int i = 0; i < num_vettori; ++i) {
            merge_sort(dataset_copy5[i], 0, size - 1);
        }
        double tempo_totale5 = tc.toc();

        double tempo_medio5 = tempo_totale5 / num_vettori;
        std::cout << "MergeSort tempo medio: " << tempo_medio5 << " s" << std::endl;

        if (tempo_medio3 < tempo_medio4) {
            std::cout << "\n" << std::endl;
            std::cout << "InsertionSort più veloce del QuickSort\n";
        } else {
            std::cout << "\n" << std::endl;
            std::cout << "QuickSort più veloce dell'Insertion\n";
        }

        if (!cut_trovato && tempo_medio3 > tempo_medio4) {
            std::cout << "\n" << std::endl;
            std::cout << "CUT TROVATO CIRCA A n = " << size << std::endl;
            cut_trovato = true;
        }

        //QuickSort ibrido
        auto dataset_copy6 = dataset;

        tc.tic();
        for (int i = 0; i < num_vettori; ++i) {
            differentquick_sort(dataset_copy6[i], 0, size - 1);
        }
        double tempo_totale6 = tc.toc();

        double tempo_medio6 = tempo_totale6 / num_vettori;
        std::cout << "\n" << std::endl;
        std::cout << "QuickSort ibrido tempo medio: " << tempo_medio6 << " s" << std::endl;

        //Sort
        auto dataset_copy7 = dataset;

        tc.tic();
        for (int i = 0; i < num_vettori; ++i) {
            std::sort(dataset.begin(), dataset.end());
        }
        double tempo_totale7 = tc.toc();

        double tempo_medio7 = tempo_totale7 / num_vettori;
        std::cout << "\n" << std::endl;
        std::cout << "Sort tempo medio: " << tempo_medio7 << " s" << std::endl;


    }

    return 0;
}