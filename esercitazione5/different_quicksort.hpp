#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

template <typename T>
size_t partition1(std::vector<T>& A, size_t p, size_t r) {
    assert(p <= r && r < A.size());

    T x = A[r];         //il pivot è l'ultimo elemento
    size_t i = p;      //confine degli elementi minori (fuori dalla array all'inizio)
    
    for (size_t j = p; j < r; ++j) {
        if (A[j] <= x) {
            std::swap(A[i], A[j]);
            ++i;
        }
    }
    
    //posizionamento finale del pivot
    std::swap(A[i], A[r]);
    size_t q = i;

    //tutti gli elementi a sinistra di q devono essere <= pivot
    for (size_t k = p; k < q; ++k) assert(A[k] <= A[q]);
    //tutti gli elementi a destra di q devono essere > pivot
    for (size_t k = q + 1; k <= r; ++k) assert(A[k] >= A[q]);

    return q;

}

template <typename T>
void insertion_sort1(std::vector<T>& vec, size_t p, size_t r) {
    //se il sottovettore ha meno di 2 elementi
    if (p >= r) return;

    for (size_t i = p + 1; i <= r; ++i) {
        T value = vec[i];

        size_t j = i;
        while (j > p && vec[j - 1] > value) {
            std::swap(vec[j], vec[j - 1]);
            --j;
        }

        vec[j] = value;
    }
}

template <typename T>
void differentquick_sort(std::vector<T>& A, size_t p, size_t r) {
    const int CUT = 40;

    if (p >= r) return;
    assert(r < A.size());

    if (r - p + 1 <= CUT) {
        insertion_sort1(A, p, r);
        return;
    }

    //q è l'indice dove il pivot è stato piazzato
    size_t q = partition1(A, p, r);
        
    //ordiniamo ricorsivamente le due metà
    if (q > p) {
        differentquick_sort(A, p, q - 1);
    }

    if ( q + 1 <= r) {
        differentquick_sort(A, q + 1, r);
    }
}
