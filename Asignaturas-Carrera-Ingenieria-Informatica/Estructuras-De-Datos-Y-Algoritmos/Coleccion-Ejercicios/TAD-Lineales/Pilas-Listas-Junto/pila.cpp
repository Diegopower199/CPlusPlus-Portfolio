#include "pila.h"

Pila::Pila()
{

}

int Pila::size() const{
    shared_ptr<ElementoListaSimple> iterator = _front;
    int idx = 0;
    while(iterator != nullptr){
        iterator = iterator->next;
        idx++;
    }
    return idx;
}

bool Pila::empty(shared_ptr<ElementoListaSimple> lista) const{
    return (lista == nullptr);
}

void Pila::push(const TipoDato &dato){
    auto elem = make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(_front != nullptr){
        elem->next = _front->next;
        _front = elem;
    }else{
        _front = elem;
    }
}

void Pila::pop(){
    if(_front != nullptr){
        _front = _front -> next;
    }
}

TipoDato &Pila::top() const{
    return _front -> dato;
}
