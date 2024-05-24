#ifndef ELEMENTOARBOL_H
#define ELEMENTOARBOL_H

#include <memory>
#include "TipoDato.h"
#include <vector>

using namespace std;

class ElementoArbol
{
public:
    TipoDato dato;
    vector<shared_ptr<ElementoArbol>> children;

public:
    ElementoArbol(const TipoDato &dato_);
};

#endif
