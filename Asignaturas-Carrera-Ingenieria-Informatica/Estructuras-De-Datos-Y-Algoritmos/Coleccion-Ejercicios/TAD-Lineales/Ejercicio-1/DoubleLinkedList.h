#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <functional>

#include "ElementoListaDoble.h"

class DoubleLinkedList
{
public:
    DoubleLinkedList();

    void for_each(std::function<void(TipoDato &)> action) const;

    void for_each_reverse(std::function<void(TipoDato &)> action) const;

    int size() const;
    bool empty() const;

    void push_back(const TipoDato &dato);
    void push_front(const TipoDato &dato);

private:
    std::shared_ptr<ElementoListaDoble> front = nullptr;
    std::shared_ptr<ElementoListaDoble> back = nullptr;
};

#endif
