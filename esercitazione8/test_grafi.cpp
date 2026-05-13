#include <iostream>
#include <cassert>
#include "classe_archi.hpp"
#include "classe_grafo.hpp"

int main() {
    //Test Classe unidirected_edge (ordinamneto automatico)
    std::cout << "\nTest unidirected_edge" << std::endl;
    
    unidirected_edge<int> e1(8, 2); 
    assert(e1.from() == 2);
    assert(e1.to() == 8);
    std::cout << "Arco e1 (8,2) ordinato correttamente: " << e1 << std::endl;

    unidirected_edge<int> e2(2, 8);
    std::cout << "Controllo se e1 (8,2) e e2 (2,8) sono uguali: ";

    if (e1 == e2) {
        //Se l'operatore == restituisce true
        std::cout << "Ok, gli archi sono uguali." << std::endl;
    } else {
        //Se l'operatore == restituisce false
        std::cout << "ERRORE! Gli archi sono diversi." << std::endl;
}


    //Test Classe unidirected_graph
    std::cout << "\nTest unidirected_graph" << std::endl;
    unidirected_graph<int> g;

    //Test add_edge e all_nodes
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(1, 3);
    
    std::set<int> nodes = g.all_nodes();
    assert(nodes.size() == 3);
    std::cout << "Nodi totali nel grafo: " << nodes.size() << "(Ci aspettiamo 3)" << std::endl;

    //Test neighbors
    std::set<int> n1 = g.neighbors(1);
    std::cout << "Vicini del nodo 1: ";
    for(int v : n1) std::cout << v << " "; //Attesi: 2, 3
    std::cout << std::endl;

    //Test all_edges e edge_number / edge_at
    std::set<unidirected_edge<int>> edges = g.all_edges();
    assert(edges.size() == 3);
    
    unidirected_edge<int> test_edge(1, 3);
    int idx = g.edge_number(test_edge);
    std::cout << "Indice dell'arco (1,3): " << idx << std::endl;
    
    unidirected_edge<int> found = g.edge_at(idx);
    assert(found == test_edge);
    std::cout << "Arco trovato all'indice " << idx << ": " << found << std::endl;

    //Test Differenza tra grafi
    unidirected_graph<int> g1;
    g1.add_edge(1, 2); //In comune con g

    unidirected_graph<int> diff = g - g1;
    std::cout << "Differenza G - G1 (archi in G ma non in G1):" << std::endl;
    diff.stampa_completa(); 
    //Dovrebbe contenere solo (1,3) e (2,3)

    std::cout << "\nTutti i test completati con successo!" << std::endl;

    return 0;
}