#ifndef ELEMENTOARBOLBINARIO_H
#define ELEMENTOARBOLBINARIO_H

#include "TipoDato.h"
#include <memory>

using namespace std;

class ElementoArbolBinario {
public:
    // Members
    TipoDato dato;
    shared_ptr<ElementoArbolBinario> left = nullptr;
    shared_ptr<ElementoArbolBinario> right = nullptr;
public:
    // Constructor
    ElementoArbolBinario(const TipoDato & dato_);
};

#endif // ELEMENTOARBOLBINARIO_H
