#pragma once
#include <map>
#include <set>
#include <iostream>
#include "classe_archi.hpp"

template<typename T>
class unidirected_graph {
private:
    std::map<T, std::set<T>> grafo;

public:
    //Costruttore di default
    unidirected_graph() {}

    unidirected_graph(const unidirected_graph<T>& other) {
        grafo = other.grafo;
    }

    //Metodo per stampare i vicini
    std::set<T> neighbors(T nodo) const {
        //itor agisce come un puntatore a un map<T,set<T>>
        typename std::map<T, std::set<T>>::const_iterator itor;
        
        itor = grafo.find(nodo);

        //Se itor non punta alla fine del grafo
        if (itor != grafo.end()) {
            //Usiamo l'operatore freccia -> come con i puntatori per accedere al secondo elemento della coppia (il set)
            return itor->second; 
        }

        return std::set<T>();
    }

    //Stampa vicini
    void stampa_completa() const {
        typename std::map<T, std::set<T>>::const_iterator itor;

        for (itor = grafo.begin(); itor != grafo.end(); ++itor) {
            //itor->first: la Chiave (il nodo di partenza)
            //itor->second: il Valore (l'insieme dei vicini)
            
            T nodo_corrente = itor->first;
            const std::set<T>& vicini = itor->second;

            std::cout << "Nodo " << nodo_corrente << " è connesso a ";

            if (vicini.empty()) {
                std::cout << "nessun nodo.";
            } else {
                //Usiamo un altro iteratore (puntatore) per scorrere il set dei vicini
                typename std::set<T>::const_iterator it_vicino;
                for (it_vicino = vicini.begin(); it_vicino != vicini.end(); ++it_vicino) {
                    //Dereferenziamo l'iteratore con * per ottenere il valore del nodo
                    std::cout << *it_vicino << " ";
                }
            }
            
            std::cout << std::endl; //A capo per il prossimo nodo
        }
    }

    //Metodo per aggiungere un arco seguendo la regola "from < to"
    void add_edge(T n1, T n2) {
    //Creiamo l'oggetto arco. 
    //Lui si assicura che node1 sia il più piccolo (from < to).
    unidirected_edge<T> e(n1, n2); 

    grafo[e.from()].insert(e.to());
    }

    //Restituisce tutti i nodi presenti nel grafo
    std::set<T> all_nodes() const {
        std::set<T> nodi;
        typename std::map<T, std::set<T>>::const_iterator itor;

        for (itor = grafo.begin(); itor != grafo.end(); ++itor) {
            //Aggiungiamo la chiave (il nodo "from")
            nodi.insert(itor->first);
            
            //Aggiungiamo tutti i nodi nel set dei vicini (i nodi "to")
            const std::set<T>& vicini = itor->second;
            nodi.insert(vicini.begin(), vicini.end());
        }
        return nodi;
    }

    //Restituisce tutti gli archi del grafo
    std::set<unidirected_edge<T>> all_edges() const {
        std::set<unidirected_edge<T>> archi;
        typename std::map<T, std::set<T>>::const_iterator itor;

        for (itor = grafo.begin(); itor != grafo.end(); ++itor) {
            T from = itor->first;
            const std::set<T>& vicini = itor->second;

            typename std::set<T>::const_iterator it_vicino;
            for (it_vicino = vicini.begin(); it_vicino != vicini.end(); ++it_vicino) {
                //Creiamo l'oggetto arco e lo inseriamo nel set
                archi.insert(unidirected_edge<T>(from, *it_vicino));
            }
        }
        return archi;
    }


    int edge_number(const unidirected_edge<T>& arco) const {
    
    std::set<unidirected_edge<T>> archi = all_edges();
    int contatore = 0;
    
    typename std::set<unidirected_edge<T>>::iterator it;
    for (it = archi.begin(); it != archi.end(); ++it) {
        //Se l'arco corrente corrisponde a quello cercato, restituiamo l'indice
        if (*it == arco) {
            return contatore;
        }
        contatore++;
    }
    //Restituisce -1 se l'arco non è presente nel grafo
    return -1; 
    }


    unidirected_edge<T> edge_at(size_t index) const {
    std::set<unidirected_edge<T>> archi = all_edges();
    
    //Controllo dei limiti (index è size_t, quindi non può essere < 0)
    if (index >= archi.size()) {
        std::cerr << "ERRORE: Indice " << index << " fuori dai limiti" << std::endl;
        return unidirected_edge<T>(); 
    }

    //Cerchiamo l'elemento manualmente
    size_t contatore = 0;
    for (const auto& e : archi) {
        if (contatore == index) {
            return e; //Trovato l'arco all'indice giusto!
        }
        contatore++;
    }

    //Caso di sicurezza (teoricamente non raggiungibile se il controllo sopra è ok)
    return unidirected_edge<T>();
    }


    unidirected_graph<T> operator-(const unidirected_graph<T>& altro_grafo) const {
    unidirected_graph<T> risultato;
    
    //Otteniamo gli archi di entrambi i grafi
    std::set<unidirected_edge<T>> archi_G = this->all_edges();
    std::set<unidirected_edge<T>> archi_G1 = altro_grafo.all_edges();

    typename std::set<unidirected_edge<T>>::iterator it;
    for (it = archi_G.begin(); it != archi_G.end(); ++it) {
        //Se l'arco di G non esiste nell'insieme di archi di G', lo aggiungiamo al risultato
        //Quando la funzione find non trova l'elemento cercato, restituisce un iteratore che punta alla "fine" del set (end()), significa che l'arco non esiste nel secondo grafo.
        if (archi_G1.find(*it) == archi_G1.end()) {
            risultato.add_edge(it->from(), it->to());
        }
    }

    return risultato;
}

};