#include <vector>
#include <algorithm>

template <typename T>
void selection_sort(std::vector<T>& vec) {

    int n = vec.size();

    // Gestione vettori vuoti o con un solo elemento
    if (n < 2) {
        return; // Esci senza fare nulla
    }

    for (int i = 0; i <= n - 2; ++i) {
        int min_index = i;

        for (int j = i + 1; j <= n - 1; ++j) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            std::swap(vec[i], vec[min_index]);
        }
    }
}