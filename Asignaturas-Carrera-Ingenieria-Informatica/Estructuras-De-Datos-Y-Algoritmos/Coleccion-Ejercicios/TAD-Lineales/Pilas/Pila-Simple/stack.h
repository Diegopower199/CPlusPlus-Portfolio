#ifndef STACK_H
#define STACK_H

#include "TipoDato.h"
#include <memory>
#include <functional>
#include "elementolistasimple.h"

class Stack
{
public:
    Stack();

    int size();
    bool empty();

    void push(const TipoDato &dato);
    void pop();

    void for_each(std::function<void(TipoDato &)> action);

    TipoDato &top();
    TipoDato dato;

protected:
    std::shared_ptr<ElementoSimpleLista> front = nullptr;
    std::shared_ptr<ElementoSimpleLista> back = nullptr;
};

#endif
