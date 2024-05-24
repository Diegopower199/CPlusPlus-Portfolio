#ifndef ELEMENTOARBOLBINARIO_H
#define ELEMENTOARBOLBINARIO_H

#include "TipoDato.h"
#include <memory>

using namespace std;

class ElementoArbolBinario
{
public:
    TipoDato dato;
    shared_ptr<ElementoArbolBinario> left = nullptr;
    shared_ptr<ElementoArbolBinario> right = nullptr;

public:
    ElementoArbolBinario(const TipoDato &dato_);
};

#endif
