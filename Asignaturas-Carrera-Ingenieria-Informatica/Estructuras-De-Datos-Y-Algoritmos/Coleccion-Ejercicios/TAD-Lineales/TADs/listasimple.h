#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <iostream>
#include "TipoDato.h"
#include "elementolistasimple.h"
#include <functional>

using namespace std;

class ListaSimple
{
public:
    ListaSimple();
    ListaSimple(const TipoDato& dato);

    void print_list(shared_ptr<ElementoListaSimple> lista);
    void for_each(function<void (TipoDato&)> action) const;
    void enumerate(function<void (int, TipoDato&)> action) const;

    int size() const;
    bool empty() const;

    TipoDato& front() const;
    TipoDato& back() const;
    TipoDato& at(int pos) const;

    void push_back(const TipoDato& dato);
    void push_front(const TipoDato& dato);
    void insert(const TipoDato& dato, int pos);

    void pop_back();
    void pop_front();
    void clear();
    void erase(int pos);

    bool equal(const TipoDato&lhs, const TipoDato&rhs);

    void swap(int pos1, int pos2);
    int find(const TipoDato &dato) const;

    shared_ptr<ElementoListaSimple> slice(int begin, int end);
    bool less_than(const TipoDato& lhs, const TipoDato& rhs); // Esta está bien

    //void sort();
    //bool is_sorted() const;

protected:
    shared_ptr<ElementoListaSimple> _front = nullptr;
    shared_ptr<ElementoListaSimple> _back = nullptr;
};

#endif // LISTASIMPLE_H
