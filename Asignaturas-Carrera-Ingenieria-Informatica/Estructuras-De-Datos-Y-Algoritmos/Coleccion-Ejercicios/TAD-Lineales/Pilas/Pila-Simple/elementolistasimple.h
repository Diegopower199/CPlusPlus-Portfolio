#ifndef ELEMENTOLISTASIMPLE_H
#define ELEMENTOLISTASIMPLE_H

#include "TipoDato.h"
#include <memory>

class ElementoSimpleLista
{

public:
    TipoDato dato;
    std::shared_ptr<ElementoSimpleLista> next = nullptr;
    std::shared_ptr<ElementoSimpleLista> prev = nullptr;

public:
    ElementoSimpleLista(const TipoDato &dato);
};

#endif
