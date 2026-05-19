#pragma once
#include <set>
#include <iterator>
#include "classe_archi.hpp"
#include "classe_grafo.hpp"

template <typename T>
void dfs_helper(const unidirected_graph<T>& G, const T& u, std::set<T>& visitati, unidirected_graph<T>& albero_visita) {
    //Il nodo corrente viene segnato come visitato
    visitati.insert(u);

    std::set<T> vicini = G.neighbors(u);
    
    //Iteriamo sui vicini di u
    typename std::set<T>::const_iterator it_vicino;
    for (it_vicino = vicini.begin(); it_vicino != vicini.end(); ++it_vicino) {
        T v = *it_vicino;
        
        //Se il vicino v non è ancora stato visitato
        if (visitati.find(v) == visitati.end()) {
            albero_visita.add_edge(u, v);
            
            //Chiamata ricorsiva sul vicino v
            dfs_helper(G, v, visitati, albero_visita);
        }
    }
}

//Funzione principale
template <typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& G, const T& source) {
    
    unidirected_graph<T> albero_visita; 
    std::set<T> visitati;

    //Lanciamo la ricorsione
    dfs_helper(G, source, visitati, albero_visita);

    //Restituisce l'albero risultante sotto forma di grafo
    return albero_visita;
}