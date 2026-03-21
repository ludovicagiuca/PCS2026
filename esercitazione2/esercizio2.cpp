#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    static const int N = 10;
    double ad[N] = {2,10,9,8,10,11,24,38,4,8};
    double min = ad[0];
    double max = ad[0];
    double somma = ad[0];
    
    for (int i = 1; i < N; i += 1) {
       min = std::min(min,ad[i]);
       max = std::max(max,ad[i]);
       somma = somma + ad[i];
    }

    double media = somma/N;

    std::cout << "Minimo: " << min << "\n";
    std::cout << "Massimo: " << max << "\n";
    std::cout << "Media: " << media << "\n";

    double scarto_quadro = std::pow(ad[0] - media , 2);

    for (int i = 1; i < N; i += 1) {
        scarto_quadro = scarto_quadro + std::pow(ad[i] - media , 2);
    }

    double varianza = scarto_quadro/N; //Calcolo la varianza della popolazione (e poi quindi deviazione standard della popolazione), per quella campionaria dovrei dividere per (N-1)
    double deviazione_standard = std::sqrt(varianza);

    std::cout << "Deviazione standard: " << deviazione_standard << "\n";

    return 0;
}