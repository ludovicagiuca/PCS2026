#pragma once
#include <map>
#include <set>
#include <queue> //Inclusa per std::priority_queue
#include <iostream>
#include <utility> //Inclusa per std::pair
#include "classe_grafo.hpp"
#include "classe_archi.hpp"

template<typename T>
void dijkstra(
    const unidirected_graph<T>& G, 
    const T& s, 
    const std::map<unidirected_edge<T>, double>& W, //Mappa dei pesi degli archi
    std::map<T, T>& pred,                          //Mappa dei predecessori
    std::map<T, double>& dist                      //Mappa delle distanze
) {
    std::set<T> nodi = G.all_nodes();
    
    //Se ha_distanza[i] è false, equivale a dire che dist[i] = +inf
    std::map<T, bool> ha_distanza; 
    
    //Primo ciclo
    for (typename std::set<T>::const_iterator it = nodi.begin(); it != nodi.end(); ++it) {
        T i = *it;
        pred[i] = T();          
        ha_distanza[i] = false; 
    }
    
    pred[s] = s;
    dist[s] = 0.0;
    ha_distanza[s] = true; //La sorgente ha una distanza finita pari a 0
    
    std::priority_queue<
        std::pair<double, T>, 
        std::vector<std::pair<double, T>>, 
        std::greater<std::pair<double, T>> //Mette in alto l'elemento con valore più basso (e quindi priorita maggiore nel nostro caso)
    > PQ;
    
    //Inseriamo il nodo sorgente nella PQ per far partire il loop
    PQ.push(std::make_pair(0.0, s));
    
    //Loop principale
    while (!PQ.empty()) {
        
        //Estrazione del minimo tramite i metodi top() e pop() della std::priority_queue
        std::pair<double, T> top_element = PQ.top();
        PQ.pop();
        
        double d_u = top_element.first;
        T u = top_element.second;
        
        //Se abbiamo già trovato una strada più corta per 'u', questo elemento estratto è vecchio e va scartato.
        if (ha_distanza[u] && d_u > dist[u]) {
            continue;
        }
        
        //Recuperiamo i vicini di u
        std::set<T> vicini = G.neighbors(u);
        
        for (typename std::set<T>::const_iterator it_v = vicini.begin(); it_v != vicini.end(); ++it_v) {
            T w = *it_v;
            
            //Recuperiamo il peso dell'arco (u, w) tramite la classe unidirected_edge
            unidirected_edge<T> arco_corrente(u, w);
            double peso_u_w = 0.0;
            
            typename std::map<unidirected_edge<T>, double>::const_iterator it_w = W.find(arco_corrente);
            if (it_w != W.end()) {
                peso_u_w = it_w->second;
            } else {
                continue; //Salta se l'arco non ha un peso associato
            }
            
            if (!ha_distanza[w] || dist[w] > dist[u] + peso_u_w) {
                dist[w] = dist[u] + peso_u_w;
                pred[w] = u;
                ha_distanza[w] = true; //Adesso 'w' ha una distanza finita valida
                
                //Inseriamo la nuova distanza nella coda (equivale al DecreaseKey)
                PQ.push(std::make_pair(dist[w], w));
            }
        }
    }
}