#include <iostream>
#include "classe_grafo.hpp"
#include "fifo.hpp"
#include "lifo.hpp"
#include "visite.hpp"
#include "dfs_ricorsivo.hpp"
#include "dijkstra.hpp"
#include "graphviz.hpp"

using fifo = ContenitoreFifo<int>;
using lifo = ContenitoreLifo<int>;

int main() {
    unidirected_graph<int> G;

    G.add_edge(1, 2);
    G.add_edge(1, 3);
    G.add_edge(1, 4);
    G.add_edge(1, 6);
    G.add_edge(2, 4); 
    G.add_edge(2, 5);
    G.add_edge(2, 5);
    G.add_edge(2, 7);
    G.add_edge(3, 6);
    G.add_edge(4, 6);
    G.add_edge(4, 7);
    G.add_edge(5, 7);
    G.add_edge(6, 7);
    G.add_edge(6, 8);
    G.add_edge(7, 9);
    G.add_edge(8, 9);

    std::cout << "--- GRAFO ORIGINALE G ---" << std::endl;
    G.stampa_completa();
    genera_dot(G, "grafo_originale");
    std::cout << "-------------------------\n" << std::endl;
    

    //EFFETTUA UNA VISITA IN PROFONDITA (DFS)
    lifo s;
    auto dfsG = graph_visit(G, 1, s);

    std::cout << "--- ALBERO RISULTANTE DFS (da nodo 1) ---" << std::endl;
    dfsG.stampa_completa();
    genera_dot(dfsG, "albero_dfs");
    std::cout << "-----------------------------------------\n" << std::endl;
    

    //EFFETTUA UNA VISITA IN AMPIEZZA (BFS)
    fifo q;
    auto bfsG = graph_visit(G, 1, q);

    std::cout << "--- ALBERO RISULTANTE BFS (da nodo 1) ---" << std::endl;
    bfsG.stampa_completa();
    genera_dot(bfsG, "albero_bfs");
    std::cout << "-----------------------------------------" << std::endl;
    

    //VISITA IN PROFONDITA RICORSIVA
    auto dfs_recursiveG = recursive_dfs(G, 1);
    std::cout << "--- ALBERO RISULTANTE DFS RICORSIVA (da nodo 1) ---" << std::endl;
    dfs_recursiveG.stampa_completa();
    genera_dot(dfs_recursiveG, "albero_dfsrecursive");
    std::cout << "-----------------------------------------" << std::endl;
    


    unidirected_graph<std::string> G1;

    //Creiamo la mappa dei pesi per gli archi
    std::map<unidirected_edge<std::string>, double> pesi;

    //Aggiungiamo gli archi al grafo e i relativi pesi alla mappa
    G1.add_edge("A", "B"); 
    pesi[unidirected_edge<std::string>("A", "B")] = 4.0;
    G1.add_edge("A", "C");
    pesi[unidirected_edge<std::string>("A", "C")] = 2.0;
    G1.add_edge("B", "C");
    pesi[unidirected_edge<std::string>("B", "C")] = 1.0;
    G1.add_edge("B", "D"); 
    pesi[unidirected_edge<std::string>("B", "D")] = 5.0;
    G1.add_edge("C", "D"); 
    pesi[unidirected_edge<std::string>("C", "D")] = 8.0;
    G1.add_edge("C", "E"); 
    pesi[unidirected_edge<std::string>("C", "E")] = 10.0;
    G1.add_edge("D", "E"); 
    pesi[unidirected_edge<std::string>("D", "E")] = 2.0;

    std::map<std::string, std::string> predecessori;
    std::map<std::string, double> distanze;

    //Scegliamo il nodo di partenza
    std::string sorgente = "A";

    std::cout << "--- Esecuzione di Dijkstra dal nodo: " << sorgente << " ---\n" << std::endl;
    
    dijkstra(G1, sorgente, pesi, predecessori, distanze);

    //Stampa dei risultati
    std::set<std::string> tutti_i_nodi = G1.all_nodes();
    
    
    for (typename std::set<std::string>::const_iterator it = tutti_i_nodi.begin(); it != tutti_i_nodi.end(); ++it) {
    std::string nodo = *it; //Recuperiamo il valore del nodo corrente
    
    std::cout << "Nodo: " << nodo << " -> ";
    
    //Cerchiamo il nodo nella mappa delle distanze usando l'iteratore della mappa
    typename std::map<std::string, double>::const_iterator it_dist = distanze.find(nodo);
    
    if (it_dist != distanze.end()) {
        //Se l'abbiamo trovato, stampiamo la distanza (che è il .second dell'iteratore)
        std::cout << "Distanza minima: " << it_dist->second;
        
        //Cerchiamo il predecessore nella mappa dei predecessori
        typename std::map<std::string, std::string>::const_iterator it_pred = predecessori.find(nodo);
        
        std::cout << ", Predecessore: ";
        //Controlliamo se ha un predecessore valido (se non è vuoto e diverso dalla sorgente stessa)
        if (it_pred != predecessori.end() && !it_pred->second.empty()) {
            std::cout << it_pred->second;
        } else {
            std::cout << "Nessuno";
        }
        
        std::cout << std::endl;
    } else {
        std::cout << "Non raggiungibile dalla sorgente." << std::endl;
    }
    }

    return 0;
}

