#pragma once

#include <memory>
#include "persona.h"

class ElementListaDoble
{
public:
    Persona dato;
    std::shared_ptr<ElementListaDoble> next = nullptr;
    std::shared_ptr<ElementListaDoble> prev = nullptr;

public:
    ElementListaDoble(const Persona &dato_);
};
