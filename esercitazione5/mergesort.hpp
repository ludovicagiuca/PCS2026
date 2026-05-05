#include <iostream>
#include <vector>
#include <string>
#include <cassert>

template <typename T>
void fusion(std::vector<T>& A, size_t p, size_t q, size_t r) {
    //verifichiamo che gli indici abbiano senso con assert
    assert(p <= q && q <= r); 
    assert(r < A.size());

    size_t n1 = q - p + 1; //quanto è lungo il primo sottoarray
    size_t n2 = r - q; //quanto è lungo il secondo sottoarray

    //Creiamo i sotto-array L e R
    std::vector<T> L(n1);
    std::vector<T> R(n2);

    //faccio una copia nei vettori temporanei
    for (size_t i = 0; i < n1; i++) {
        assert(p + i < A.size());
        L[i] = A[p + i];
    }
    for (size_t j = 0; j < n2; j++) {
        assert(q + j + 1 < A.size());
        R[j] = A[q + j + 1];
    }

    size_t i = 0, j = 0, k = p;

    //fusione
    while (i < n1 && j < n2) {
        assert(i < L.size() && j < R.size() && k < A.size());
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    //copia i rimanenti elementi di L (se ce ne sono) invece di usare la condizione di fine inf
    while (i < n1) {
        assert(i < L.size() && k < A.size());
        A[k] = L[i];
        i++; k++;
    }

    //copia i rimanenti elementi di R (se ce ne sono)
    while (j < n2) {
        assert(j < R.size() && k < A.size());
        A[k] = R[j];
        j++; k++;
    }

    //verifica finale per vedere se abbiamo riempito la lunghezza prevista
    assert(k == r + 1);
}

template <typename T>
void merge_sort(std::vector<T>& v) {
    if (!v.empty())
        merge_sort(v, 0, v.size() - 1);
}

template <typename T>
void merge_sort(std::vector<T>& sl, size_t sinistra, size_t destra) {
    if (sinistra < destra) {
        size_t centro = sinistra + (destra - sinistra) / 2;
        merge_sort(sl, sinistra, centro);
        merge_sort(sl, centro + 1, destra);
        fusion(sl, sinistra, centro, destra);
    }
}
