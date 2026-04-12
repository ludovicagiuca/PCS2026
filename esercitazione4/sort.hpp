#include <vector>

template<typename T>
bool is_sorted(const std::vector<T>& vec) {
    // Un vettore di lunghezza 0 o 1 è sempre ordinato
    if (vec.size() <= 1) {
        return true;
    }

    // Scorriamo il vettore e confrontiamo ogni elemento con il successivo
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1]) {
            // Trovata una coppia non in ordine: il vettore non è ordinato
            return false;
        }
    }

    // Se arriviamo alla fine senza ritornare false, il vettore è ordinato
    return true;
}