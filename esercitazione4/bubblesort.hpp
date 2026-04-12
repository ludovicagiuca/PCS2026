#include <vector>
#include <algorithm>

template<typename T>

void bubble_sort(std::vector<T>& vec) {

    int n = vec.size();

    // Gestione vettori vuoti o con un solo elemento
    if (n < 2) {
        return; // Esci senza fare nulla
    }

    // for i = 0 : n - 2
    for (int i = 0; i <= n - 2; i++) {
        // for j = n - 1 : i + 1
        // Nota: il ciclo decresce da n-1 fino a i+1 inclusi
        for (int j = n - 1; j >= i + 1; j--) {

            if (vec[j] < vec[j - 1]) {
                std::swap(vec[j], vec[j - 1]);
            }
        }
    }
}