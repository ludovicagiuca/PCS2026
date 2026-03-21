#include <iostream>

int main() {
    static const int N = 10;
    double ad[N] = {2,10,9,8,10,11,24,38,4,8};
    bool scambiAvvenuti;

    do {
        scambiAvvenuti = false; // Reset all'inizio di ogni passaggio

        for (int i = 0; i < (N - 1); i++) {
            if (ad[i] > ad[i + 1]) {
                double temp = ad[i]; //salvo il contenuto di A in una variabile nuova
                ad[i] = ad[i + 1]; // metto B al posto di A
                ad[i + 1] = temp; // metto il contenuto di A salvato prima al posto di B vecchio

                scambiAvvenuti = true; // Segnaliamo che è avvenuto uno scambio
            }
        }
    } while (scambiAvvenuti); // Continua finché ci sono scambi

    std::cout << "Array ordinato: ";
    for (int i = 0; i < N; i++) {
        std::cout << ad[i] << " ";
    }

    return 0;
}