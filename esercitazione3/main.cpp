#include <iostream>
#include "rationalclass.hpp"

int main() {
    std::cout << "--- Test Base & Semplificazione ---" << std::endl;
    rational<int> r1(4, 4);   // Deve diventare 1/1
    rational<int> r2(15, -5); // Deve diventare -3/1

    std::cout << "4/4 semplificato: " << r1 << std::endl;
    std::cout << "15/-5 semplificato: " << r2 << std::endl;


    std::cout << "\n--- Operazioni Standard ---" << std::endl;
    rational<int> a(1, 3);
    rational<int> b(1, 4);
    
    std::cout << "1/3 + 1/4: " << (a + b) << std::endl; // 7/12
    std::cout << "1/3 - 1/4: " << (a - b) << std::endl; // 1/12
    std::cout << "1/3 * 1/4: " << (a * b) << std::endl; // 1/12
    std::cout << "1/3 / 1/4: " << (a / b) << std::endl; // 4/3


    std::cout << "\n--- Casi Limite: Infinito ---" << std::endl;
    rational<int> inf(1, 0);    // +Inf
    rational<int> neg_inf(-7, 0); // -Inf
    
    std::cout << "Infinito positivo: " << inf << std::endl;
    std::cout << "Infinito negativo: " << neg_inf << std::endl;
    std::cout << "1/3 + Inf: " << (a + inf) << std::endl;       // +Inf
    std::cout << "Inf + Inf: " << (inf + inf) << std::endl;     // +Inf
    std::cout << "Inf - Inf: " << (inf - inf) << std::endl;     // NaN

    
    std::cout << "\n--- Casi Limite: NaN ---" << std::endl;
    rational<int> nan(0, 0); //
    
    std::cout << "Valore NaN: " << nan << std::endl;
    std::cout << "1/3 + NaN: " << (a + nan) << std::endl;       // NaN
    std::cout << "Inf * 0: " << (inf * rational<int>(0, 1)) << std::endl; // NaN
    std::cout << "1/3 / NaN: " << (a / nan) << std::endl; // NaN

    return 0;
}