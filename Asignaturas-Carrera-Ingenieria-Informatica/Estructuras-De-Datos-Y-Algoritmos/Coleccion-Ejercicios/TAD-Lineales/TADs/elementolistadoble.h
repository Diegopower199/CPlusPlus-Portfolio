#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H

#include <memory>
#include "TipoDato.h"

using namespace std;

class ElementoListaDoble
{
public:
    TipoDato dato;
    shared_ptr<ElementoListaDoble> next = nullptr;
    shared_ptr<ElementoListaDoble> prev = nullptr;

public:
    ElementoListaDoble(const TipoDato &dato_);
};

#endif
