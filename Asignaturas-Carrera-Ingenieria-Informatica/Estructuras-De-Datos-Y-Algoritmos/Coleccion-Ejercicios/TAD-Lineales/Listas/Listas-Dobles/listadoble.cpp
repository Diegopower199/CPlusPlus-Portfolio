

#include "listadoble.h"

listaDoble::listaDoble()
{

}

void listaDoble::for_each(function<void (TipoDato &)> action) const {
    std::shared_ptr<ElementoListaDoble> iterator = front;
    while (iterator != nullptr) {
        action(iterator->dato); // Call the action
        iterator = iterator->next;
    }
}


int listaDoble::size() const{
    shared_ptr<ElementoListaDoble> iterator = front;
    int idx = 0;
    while(iterator != nullptr){
        iterator = iterator->next; // en un momento el siguiente de a lo que apunta itetator pasa a ser igual a nullptr
        idx++;
    }
    return idx;
}

void listaDoble::for_each_reverse(function<void (TipoDato &)> action) const {
    std::shared_ptr<ElementoListaDoble> iterator = back;
    while (iterator != nullptr) {
        action(iterator -> dato); // Call the action over the dato which iterator is pointing
        iterator = iterator -> prev;  // ESTO ES MAGIA
    }

    action(front->dato);
}

void listaDoble::push_back(const TipoDato & dato) {
    std::shared_ptr <ElementoListaDoble> elem = std::make_shared <ElementoListaDoble> (ElementoListaDoble{dato});
    if (front == nullptr) {
        front = elem;
        back = elem;
    }
    else {
        back -> next = elem;
        back = elem;
    }
}
