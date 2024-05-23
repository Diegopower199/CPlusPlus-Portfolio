#ifndef ELEMENTOLISTASIMPLE_H
#define ELEMENTOLISTASIMPLE_H

#include <memory>
#include "TipoDato.h"

using namespace std;

class ElementoListaSimple
{
public:
    // Members
    TipoDato dato;
    shared_ptr<ElementoListaSimple> next = nullptr;

public:
    // Constructor
    ElementoListaSimple(const TipoDato& dato_);

};

#endif // ELEMENTOLISTASIMPLE_H
