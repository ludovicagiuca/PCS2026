#pragma once
#include <stack>

//Pila

template <typename T>
class ContenitoreLifo {
private:
    std::stack<T> pila;
public:
//Costruttore di default
    ContenitoreLifo() {}
    
    void put(const T& x) { 
        pila.push(x); 
    }
    
    T get() {
        T elem = pila.top();
        pila.pop();
        return elem;
    }
    
    bool empty() const { 
        return pila.empty(); 
    }
};
