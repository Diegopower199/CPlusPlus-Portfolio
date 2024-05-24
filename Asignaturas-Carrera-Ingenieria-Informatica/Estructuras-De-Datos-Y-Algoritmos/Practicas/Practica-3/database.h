#pragma once

#include <memory>
#include <functional>

#include "empleado.h"

class ElementoArbolBinario
{
public:
    Empleado dato;
    std::shared_ptr<ElementoArbolBinario> left = nullptr;
    std::shared_ptr<ElementoArbolBinario> right = nullptr;

public:
    ElementoArbolBinario(const Empleado &dato_) : dato{dato_} {};
};

class BinarySearchTree
{
private:
    std::shared_ptr<ElementoArbolBinario> root = nullptr;

public:
    BinarySearchTree();

    void push(const Empleado &);

    int size() const;
    void for_each(std::function<void(Empleado &)> action) const;
    const Empleado &find(int id) const;
};
