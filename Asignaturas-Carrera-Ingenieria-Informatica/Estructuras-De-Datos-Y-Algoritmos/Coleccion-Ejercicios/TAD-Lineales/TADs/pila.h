#ifndef PILA_H
#define PILA_H

#include "TipoDato.h"
#include "elementolistasimple.h"
#include <functional>
#include <memory>

class Pila
{
public:
    Pila();

    int size() const;
    bool empty(shared_ptr<ElementoListaSimple> lista) const;

    void push(const TipoDato &dato);
    void pop();
    TipoDato &top() const;

private:
    shared_ptr<ElementoListaSimple> _front = nullptr;
};

#endif
