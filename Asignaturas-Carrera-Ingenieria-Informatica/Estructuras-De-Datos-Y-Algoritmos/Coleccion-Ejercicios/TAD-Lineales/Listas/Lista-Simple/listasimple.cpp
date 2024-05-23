#include "listasimple.h"

ListaSimple::ListaSimple() : _front{nullptr}, _back{nullptr} {}

ListaSimple::ListaSimple(const TipoDato & dato) {
    _front = make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    _back = _front; // both are pointing to the same element
}

void ListaSimple::print_list(shared_ptr<ElementoListaSimple> lista) {
    shared_ptr<ElementoListaSimple> iterator = lista;
    while(iterator != nullptr){
        cout << iterator->dato.name << endl;
        iterator = iterator->next;
    }
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

int ListaSimple::size() const {
    shared_ptr<ElementoListaSimple> iterator = _front;
    int idx = 0;
    while(iterator != nullptr){
        iterator = iterator->next;
        idx++;
    }
    return idx;
}

bool ListaSimple::empty() const {
    return (_front == nullptr && _back == nullptr);
}

TipoDato &ListaSimple::front() const {
    return _front -> dato;
}

TipoDato &ListaSimple::back() const {
    shared_ptr<ElementoListaSimple> lista; shared_ptr<ElementoListaSimple> iterator = lista;
    while (iterator->next != nullptr){
        iterator = iterator->next;
    }
    return iterator -> dato;
}

TipoDato &ListaSimple::at(int pos) const {
    shared_ptr<ElementoListaSimple> lista; shared_ptr<ElementoListaSimple> iterator = lista;
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

void ListaSimple::push_back(const TipoDato& dato) {
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

void ListaSimple::push_front(const TipoDato &dato) {
    shared_ptr<ElementoListaSimple> lista;
    shared_ptr<ElementoListaSimple> elem = make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(empty()){
        lista = elem;
    }else{
        elem->next = lista;
        lista = elem;
    }
}

void ListaSimple::insert(const TipoDato &dato, int pos) {
    shared_ptr<ElementoListaSimple> lista; std::shared_ptr<ElementoListaSimple> elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});

    if (pos == 0) {
        push_front(dato);
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

void ListaSimple::pop_back() {
    shared_ptr<ElementoListaSimple> lista;
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

void ListaSimple::pop_front() {
    shared_ptr<ElementoListaSimple> lista;
    lista = lista->next;
}

void ListaSimple::clear() {
    shared_ptr<ElementoListaSimple> lista;
    lista = nullptr;
}

void ListaSimple::erase(int pos) {
    shared_ptr<ElementoListaSimple> lista;
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


/*
void ListaSimple::swap(int pos1, int pos2) {
    auto& dato1 = at(pos1);
    auto& dato2 = at(pos2);
    swap(dato1, dato2);
}
*/

bool ListaSimple::equal(const TipoDato&lhs, const TipoDato&rhs) {
    return lhs.name == rhs.name;
}

int ListaSimple::find(const TipoDato &dato) {
    shared_ptr<ElementoListaSimple> lista;
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

shared_ptr<ElementoListaSimple> ListaSimple::slice(int begin, int end) {
    shared_ptr<ElementoListaSimple> lista;
    std::shared_ptr<ElementoListaSimple> iterator = lista;
    int idx = 0;
    while (idx != begin) {
        iterator = iterator->next;
        idx++;
    }
    std::shared_ptr<ElementoListaSimple> slice = std::make_shared<ElementoListaSimple>(iterator->dato);
    while (idx != end) {
        iterator = iterator->next;
        idx++;
        push_back(iterator->dato);
    }
    return slice;
}

bool ListaSimple::less_than(const TipoDato &lhs, const TipoDato &rhs) {
    return lhs.name < rhs.name;
}

