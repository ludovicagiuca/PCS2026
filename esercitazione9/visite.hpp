#pragma once
#include "fifo.hpp"
#include"lifo.hpp"
#include <set>
#include <iterator>
#include "classe_archi.hpp"
#include "classe_grafo.hpp"

template <typename T, typename Container>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& G, const T& source, Container& struttura) {

    //Grafo che conterrà l'albero risultante dalla visita
    unidirected_graph<T> albero_visita; 

    //Set per tenere traccia dei nodi già visitati
    std::set<T> visitati;

    //Inseriamo il nodo sorgente
    struttura.put(source);
    visitati.insert(source);

    while (!struttura.empty()) {

        T u = struttura.get();

        std::set<T> vicini = G.neighbors(u);

        //Iteriamo su ciascun vicino v di u, ciclo con iteratore
        typename std::set<T>::const_iterator it_vicino;
        for (it_vicino = vicini.begin(); it_vicino != vicini.end(); ++it_vicino) {

            T v = *it_vicino;
            
            //Se il vicino v non è ancora presente nel set dei visitati
            if (visitati.find(v) == visitati.end()) {
                visitati.insert(v);

                //Aggiungiamo l'arco che connette u a v all'albero della visita
                albero_visita.add_edge(u, v); 

                //Inseriamo il nodo nella struttura (pila o coda) per esplorare i suoi vicini in seguito
                struttura.put(v);
                
            }
        }
    }

    //Restituisce l'albero risultante sotto forma di grafo
    return albero_visita;
}