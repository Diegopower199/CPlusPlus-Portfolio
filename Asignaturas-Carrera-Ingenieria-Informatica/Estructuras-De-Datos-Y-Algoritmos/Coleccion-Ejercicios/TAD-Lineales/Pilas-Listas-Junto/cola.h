#ifndef COLA_H
#define COLA_H

#include "TipoDato.h"
#include <memory>
#include <functional>
//#include "elementolistadoble.h"

using namespace std;

class Cola
{
public:
    Cola();

    int size() const;
    bool empty() const;

    TipoDato& front() const;
    TipoDato& back() const;
    void push(const TipoDato& dato);
    void pop();

private:
    //shared_ptr<ElementoListaDoble> _front = nullptr;
    //shared_ptr<ElementoListaDoble> _back = nullptr;
};

#endif // COLA_H
