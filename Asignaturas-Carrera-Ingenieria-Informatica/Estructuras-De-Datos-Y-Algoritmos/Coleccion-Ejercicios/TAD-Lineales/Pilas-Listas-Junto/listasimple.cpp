#include "listasimple.h"

ListaSimple::ListaSimple()
{

}

void ListaSimple::for_each(function<void (TipoDato &)> action) const {
    shared_ptr<ElementoListaSimple> iterator = _front;
    while(iterator != nullptr){
        action(iterator->dato);
        iterator = iterator->next;
    }
}

void ListaSimple::enumerate(function<void (int, TipoDato &)> action) const {
    shared_ptr<ElementoListaSimple> iterator = _front;
    int idx = 0;
    while(iterator != nullptr){
        action(idx, iterator->dato);
        iterator = iterator->next;
        idx++;
    }
}

int ListaSimple::size() const{
    shared_ptr<ElementoListaSimple> iterator = _front;
    int idx = 0;
    while(iterator != nullptr){
        iterator = iterator->next;
        idx++;
    }
    return idx;
}

bool ListaSimple::empty(shared_ptr<ElementoListaSimple> lista) const
{
    return (lista == nullptr);
}

TipoDato &ListaSimple::front(shared_ptr<ElementoListaSimple> lista) const
{
    return lista -> dato;
}

TipoDato &ListaSimple::back(shared_ptr<ElementoListaSimple> lista) const
{
    shared_ptr<ElementoListaSimple> iterator = lista;
    while (iterator->next != nullptr){
        iterator = iterator->next;
    }
    return iterator -> dato;
}

TipoDato &ListaSimple::at(shared_ptr<ElementoListaSimple> lista, int pos) const
{
    shared_ptr<ElementoListaSimple> iterator = lista;
    int idx = 0;
    while(iterator != nullptr){
        if(idx == pos){
            break;
        }
        iterator = iterator -> next;
        idx++;
    }
    return iterator->dato;
}

void ListaSimple::push_back(const TipoDato& dato){
    shared_ptr<ElementoListaSimple> elem = make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if (_front == nullptr){
        _front = elem;
        _back = elem;
    }
    else{
        _back->next = elem;
        _back = elem;
    }
}

void ListaSimple::push_front(shared_ptr<ElementoListaSimple>& lista, const TipoDato &dato)
{
    shared_ptr<ElementoListaSimple> elem = make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(empty(lista)){
        lista = elem;
    }else{
        elem->next = lista;
        lista = elem;
    }
}

void ListaSimple::insert(shared_ptr<ElementoListaSimple>& lista, const TipoDato &dato, int pos)
{
    std::shared_ptr<ElementoListaSimple> elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});

    if (pos == 0) {
        push_front(lista, dato);
    }
    else {
        std::shared_ptr<ElementoListaSimple> iterator = lista;
        int idx = 0;
        while (idx != pos - 1) {
            iterator = iterator->next;
            idx++;
        }
        elem->next = iterator->next;
        iterator->next = elem;
    }
}

void ListaSimple::pop_back(shared_ptr<ElementoListaSimple> &lista)
{
    if (lista->next == nullptr) {
        // If the list only has one element
        lista = nullptr;
    }
    else {
        std::shared_ptr<ElementoListaSimple> iterator = lista;
        while (iterator->next->next != nullptr) {
            iterator = iterator->next;
        }
        iterator->next = nullptr;
    }
}

void ListaSimple::pop_front(shared_ptr<ElementoListaSimple> &lista)
{
    lista = lista->next;
}

void ListaSimple::clear(shared_ptr<ElementoListaSimple> &lista)
{
    lista = nullptr;
}

void ListaSimple::erase(shared_ptr<ElementoListaSimple> &lista, int pos)
{
    if (pos == 0) {
        lista = lista->next;
    }
    else {
        std::shared_ptr<ElementoListaSimple> iterator = lista;
        int idx = 0;
        while (idx != pos - 1) {
            iterator = iterator->next;
            idx++;
        }
        iterator->next = iterator->next->next;
    }
}

void ListaSimple::swap(int pos1, int pos2)
{
    shared_ptr<ElementoListaSimple> lista;
    auto& dato1 = at(lista, pos1);
    auto& dato2 = at(lista, pos2);
    swap(dato1, dato2);
}

bool ListaSimple::equal(const TipoDato &lhs, const TipoDato &rhs)
{
    return lhs.name == rhs.name;
}

int ListaSimple::find(const TipoDato &dato) const
{
    shared_ptr<ElementoListaSimple> iterator = lista;
    int found = -1;
    int idx = 0;
    while(iterator != nullptr){
        if(equal(iterator->dato, dato)){
            found = idx;
            break;
        }
        iterator = iterator->next;
        idx++;
    }
    return found;
}

shared_ptr<ElementoListaSimple> ListaSimple::slice(shared_ptr<ElementoListaSimple> lista, int begin, int end)
{
    std::shared_ptr<ElementoListaSimple> iterator = lista;
    int idx = 0;
    while (idx != begin) {
        iterator = iterator->next;
        idx++;
    }
    std::shared_ptr<ElementoListaSimple> slice = std::make_shared<ElementoListaSimple>(iterator->dato);
    while (idx != end) { // until position 'end'
        iterator = iterator->next;
        idx++;
        push_back(slice, iterator->dato);
    }
    return slice;
}

bool ListaSimple::less_than(const TipoDato &lhs, const TipoDato &rhs)
{
    return lhs.name < rhs.name;
}
