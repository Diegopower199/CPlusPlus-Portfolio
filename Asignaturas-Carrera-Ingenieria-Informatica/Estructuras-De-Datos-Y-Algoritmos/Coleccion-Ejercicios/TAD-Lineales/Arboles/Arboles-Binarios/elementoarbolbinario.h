#ifndef ELEMENTOARBOLBINARIO_H
#define ELEMENTOARBOLBINARIO_H

#include <memory>
#include "tipodato.h"

class ElementoArbolBinario
{
public:
    TipoDato dato;
    std::shared_ptr<ElementoArbolBinario> left = nullptr;
    std::shared_ptr<ElementoArbolBinario> right = nullptr;

public:
    ElementoArbolBinario(const TipoDato &dato_) : dato{dato_} {};
};

#endif
