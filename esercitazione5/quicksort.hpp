#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

template <typename T>
size_t partition(std::vector<T>& A, size_t p, size_t r) {
    assert(p <= r && r < A.size());

    T x = A[r];         //il pivot è l'ultimo elemento
    size_t i = p;      //confine degli elementi minori (fuori dalla array all'inizio)
    
    for (size_t j = p; j < r; ++j) {
        if (A[j] <= x) {
            std::swap(A[i], A[j]);
            i++;
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
void quick_sort(std::vector<T>& A, size_t p, size_t r) {
    if (p >= r) return; 
    
    assert( r < A.size());

        //q è l'indice dove il pivot è stato messo
        size_t q = partition(A, p, r);
        
        //ordiniamo ricorsivamente le due metà

        if(q > p) {
            quick_sort(A, p, q - 1);
        }
        
        quick_sort(A, q + 1, r);
}