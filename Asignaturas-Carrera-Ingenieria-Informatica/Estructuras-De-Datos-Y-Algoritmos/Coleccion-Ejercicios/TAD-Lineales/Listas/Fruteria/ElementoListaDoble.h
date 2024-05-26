#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H
#include <memory>
#include <iostream>
#include "fruta.h"

template <typename T>
class ElementoListaDoble
{
public:
    ElementoListaDoble(const T &dato_) : dato{dato_} {};
    T dato;
    std::shared_ptr<ElementoListaDoble> next = nullptr;
    std::shared_ptr<ElementoListaDoble> prev = nullptr;
};

#endif
