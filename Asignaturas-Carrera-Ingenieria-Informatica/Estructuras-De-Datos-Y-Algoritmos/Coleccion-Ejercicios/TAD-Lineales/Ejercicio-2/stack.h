#ifndef STACK_H
#define STACK_H

#include "ElementoListaSimple.h"
#include "TipoDato.h"

class Stack
{
public:
    Stack();

    int size() const;

    void push(const TipoDato &dato);
    void pop();
    TipoDato &top() const;

private:
    shared_ptr<ElementoListaSimple> front = nullptr;
};

#endif
