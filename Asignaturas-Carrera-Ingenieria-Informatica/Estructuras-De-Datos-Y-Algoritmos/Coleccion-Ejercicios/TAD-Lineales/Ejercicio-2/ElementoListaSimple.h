#ifndef ELEMENTOLISTASIMPLE_H
#define ELEMENTOLISTASIMPLE_H

#include <memory>
#include "TipoDato.h"

using namespace std;

class ElementoListaSimple
{
public:
    TipoDato datos;
    std::shared_ptr<ElementoListaSimple> next = nullptr;

public:
    ElementoListaSimple(const TipoDato &datos);
};

#endif
