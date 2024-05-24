#ifndef COLA_H
#define COLA_H

#include "TipoDato.h"
#include <memory>
#include <functional>

using namespace std;

class Cola
{
public:
    Cola();

    int size() const;
    bool empty() const;

    TipoDato &front() const;
    TipoDato &back() const;
    void push(const TipoDato &dato);
    void pop();

private:
};

#endif