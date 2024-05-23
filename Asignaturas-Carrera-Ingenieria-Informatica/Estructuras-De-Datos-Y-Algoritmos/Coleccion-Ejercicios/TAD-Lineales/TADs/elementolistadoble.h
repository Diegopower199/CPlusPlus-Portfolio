#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H

#include <memory>
#include "TipoDato.h"

using namespace std;

class ElementoListaDoble
{
public:
    // Members
    TipoDato dato;
    shared_ptr<ElementoListaDoble> next = nullptr;
    shared_ptr<ElementoListaDoble> prev = nullptr;

public:
    // Constructor
    ElementoListaDoble(const TipoDato& dato_);

};

#endif // ELEMENTOLISTADOBLE_H
