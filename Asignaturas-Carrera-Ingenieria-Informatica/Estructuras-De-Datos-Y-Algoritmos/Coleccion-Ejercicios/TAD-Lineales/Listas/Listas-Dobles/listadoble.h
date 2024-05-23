#ifndef LISTADOBLE_H
#define LISTADOBLE_H


#include "TipoDato.h"
#include <memory>
#include <functional>
#include "elementolistadoble.h"
using namespace std;

class listaDoble {
public:
    listaDoble();
    void for_each(function<void(TipoDato& dato)> action) const;
    TipoDato dato;

    int size() const;

    void for_each_reverse(function<void (TipoDato &)> action) const;

    void push_back (const TipoDato & dato);
private:
    shared_ptr<ElementoListaDoble> front = nullptr;
    shared_ptr<ElementoListaDoble> back = nullptr;
};

#endif // LISTADOBLE_H
