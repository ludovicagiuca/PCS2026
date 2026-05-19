#pragma once
#include <queue>

//Coda

template <typename T>
class ContenitoreFifo {
private:
    std::queue<T> coda;
public:
//Costruttore di default
    ContenitoreFifo() {}

    void put(const T& x) {
        coda.push(x);
    }

    T get() {
        T elem = coda.front();
        coda.pop();
        return elem;
    }
    
    bool empty() const {
        return coda.empty();
    }
};
