#ifndef ELEMENTOLISTASIMPLE_H
#define ELEMENTOLISTASIMPLE_H

#include <memory>
#include "TipoDato.h"

using namespace std;

class ElementoListaSimple
{
public:
    TipoDato dato;
    shared_ptr<ElementoListaSimple> next = nullptr;

public:
    ElementoListaSimple(const TipoDato &dato_);
};

#endif
