#include <vector>
#include <algorithm>

template <typename T>
void insertion_sort(std::vector<T>& vec) {
    int n = vec.size();

    // Se il vettore è vuoto o ha un solo elemento, è già ordinato
    if (n < 2) {
        return;
    }

    for (int i = 1; i <= n - 1; ++i) {
        T value = vec[i];

        // Nota: j deve essere un intero con segno (int) perché la condizione j >= 0 fallirebbe con un unsigned
        int j = i - 1;
        while (j >= 0 && vec[j] > value) {
            std::swap(vec[j + 1], vec[j]);
            j = j - 1;
        }

        vec[j + 1] = value;
    }
}