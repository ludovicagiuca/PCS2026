#pragma once
#include <iostream>

template<typename T>
class unidirected_edge {
private:
    T node1;
    T node2;

public:
    //Costruttore di default
    unidirected_edge() {
        node1 = 0;
        node2 = 0;
    }

    //Costruttore che fa specificare i due nodi
    unidirected_edge(const T& n1, const T& n2) {
        if (n1 < n2) {
                node1 = n1;
                node2 = n2;
            } else {
                node1 = n2;
                node2 = n1;
            }
    }
    

    //Metodo che restituisce il nodo sorgente
    T from() const {
        return node1;
    }

    //Metodo che restituisce il nodo di destinazione
    T to() const {
        return node2;
    }

    //operator<: per ordinare gli archi
    bool operator<(const unidirected_edge<T>& other) const {
        if (node1 != other.node1) {
            return node1 < other.node1;
        }
        return node2 < other.node2;
    }

    //operator==: due archi sono uguali se hanno gli stessi nodi
    bool operator==(const unidirected_edge<T>& other) const {
        return (node1 == other.node1 && node2 == other.node2);
    }

};

//operator<<: per la stampa
template<typename T>
std::ostream&
operator<<(std::ostream& os, const unidirected_edge<T>& edge)
{
    os << "(" << edge.from() << ", " << edge.to() << ")";
    return os;
};
