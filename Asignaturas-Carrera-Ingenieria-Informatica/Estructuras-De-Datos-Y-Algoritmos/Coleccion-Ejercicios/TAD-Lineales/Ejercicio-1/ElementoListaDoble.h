#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H

#include <memory>

#include "TipoDato.h"

class ElementoListaDoble
{
public:
    TipoDato datos;
    std::shared_ptr<ElementoListaDoble> next = nullptr;
    std::shared_ptr<ElementoListaDoble> prev = nullptr;

public:
    ElementoListaDoble(const TipoDato &datos);
};

#endif
