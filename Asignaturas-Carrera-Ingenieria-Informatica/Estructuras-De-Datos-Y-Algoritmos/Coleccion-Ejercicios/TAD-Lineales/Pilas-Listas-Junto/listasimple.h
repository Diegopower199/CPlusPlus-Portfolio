#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "TipoDato.h"
#include "elementolistasimple.h"
#include <functional>

using namespace std;

class ListaSimple
{
public:
    ListaSimple();

    void for_each(function<void (TipoDato&)> action) const;
    void enumerate(function<void (int, TipoDato&)> action) const;

    int size() const;
    bool empty(shared_ptr<ElementoListaSimple> lista) const;

    TipoDato& front(shared_ptr<ElementoListaSimple> lista) const;
    TipoDato& back(shared_ptr<ElementoListaSimple> lista) const;
    TipoDato& at(shared_ptr<ElementoListaSimple> lista, int pos) const;

    void push_back(const TipoDato& dato);
    void push_front(shared_ptr<ElementoListaSimple>& lista, const TipoDato& dato);
    void insert(shared_ptr<ElementoListaSimple>& lista, const TipoDato& dato, int pos);

    void pop_back(shared_ptr<ElementoListaSimple>& lista);
    void pop_front(shared_ptr<ElementoListaSimple>& lista);
    void clear(shared_ptr<ElementoListaSimple>& lista);
    void erase(shared_ptr<ElementoListaSimple>& lista, int pos);

    bool equal(const TipoDato& lhs, const TipoDato& rhs);
    // Implementar en el cpp
    void swap(int pos1, int pos2);
    int find(const TipoDato& dato) const;

    shared_ptr<ElementoListaSimple> slice(shared_ptr<ElementoListaSimple> lista, int begin, int end);
    bool less_than(const TipoDato& lhs, const TipoDato& rhs); // Esta está bien

    //void sort();
    //bool is_sorted() const;

private:
    shared_ptr<ElementoListaSimple> _front = nullptr;
    shared_ptr<ElementoListaSimple> _back = nullptr;
};

#endif // LISTASIMPLE_H
