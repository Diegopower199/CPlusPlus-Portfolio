#include <iostream>
#include <memory>

struct Pedido{
   int cantidad;
   std::string fruta;
};

struct ElementoLista {
   Pedido pedido;
   std::shared_ptr<ElementoLista> next = nullptr;
};

class Lista {
private:
    std::shared_ptr <ElementoLista> _front = nullptr;
    std::shared_ptr <ElementoLista> _back = nullptr;

public:
    Lista();
    Lista (const Pedido& dato);

    void push (const Pedido& dato);

    bool empty (std::shared_ptr <ElementoLista> lista);
    int size (std::shared_ptr <ElementoLista> lista);

    Pedido& front (std::shared_ptr <ElementoLista> lista);
    Pedido& back (std::shared_ptr <ElementoLista> lista);
    Pedido& at (std::shared_ptr <ElementoLista> lista, int pos);

    void pop_back(std::shared_ptr <ElementoLista> lista);
    void pop_front (std::shared_ptr <ElementoLista> lista);
    void clear (std::shared_ptr <ElementoLista> lista);

    void push_back(std::shared_ptr <ElementoLista> lista, const Pedido& dato);
    void push_front (std::shared_ptr <ElementoLista> lista, const Pedido& dato);

    void swap(std::shared_ptr<ElementoLista>& lista, int pos1, int pos2);

    // FUNCION FIND
    bool equal(const Pedido& lhs, const Pedido& rhs);
    int find(std::shared_ptr<ElementoLista> lista, const Pedido& dato);
};

Lista::Lista() {
    _front = nullptr;
    _back = nullptr;
}

Lista::Lista (const Pedido& dato) {
    _front = std::make_shared <ElementoLista> (ElementoLista{dato});
    _back = _front;
}

void Lista::push (const Pedido& dato) {
    std::shared_ptr <ElementoLista> elem = std::make_shared <ElementoLista> (ElementoLista{dato});
    if (_front == nullptr) {
        _front = elem;
        _back = elem;
    }
    else {
        _back -> next = elem;
        _back = elem;
    }
}

bool Lista::empty (std::shared_ptr <ElementoLista> lista) {
    return (_front == nullptr && _back == nullptr);
}

int Lista::size (std::shared_ptr <ElementoLista> lista) {
    if (lista == nullptr) {
        return 0;
    }
    return 1 + size(lista ->next);
}

Pedido& Lista::front (std::shared_ptr <ElementoLista> lista) {
    return lista ->pedido;
}
Pedido& Lista::back (std::shared_ptr <ElementoLista> lista){
    std::shared_ptr <ElementoLista> iterador = lista;
    while (iterador -> next != nullptr) {
        iterador = iterador -> next;
    }
    return iterador -> pedido;
}

Pedido& Lista::at (std::shared_ptr <ElementoLista> lista, int pos){
    std::shared_ptr <ElementoLista> iterador = lista;
    int idx = 0;

    while (iterador != nullptr) {
        if (idx == pos) {
            break;
        }
        iterador = iterador -> next;
        idx++;
    }
    return iterador -> pedido;
}



void Lista::pop_back(std::shared_ptr <ElementoLista> lista) {
    if (lista -> next == nullptr) {
        lista = nullptr;
    }
    else {
        std::shared_ptr <ElementoLista> iterador = lista;
        while (iterador -> next -> next != nullptr) {
            iterador = iterador -> next;
        }
        iterador -> next = nullptr;
    }
}




void Lista::pop_front (std::shared_ptr <ElementoLista> lista) {
    lista = lista -> next;
}

void Lista::clear (std::shared_ptr <ElementoLista> lista) {
    lista = nullptr;
}




void Lista::push_back(std::shared_ptr<ElementoLista> lista, const Pedido &dato) {
    // Create the element to hold the incoming dato
    std::shared_ptr<ElementoLista> elem = std::make_shared<ElementoLista>(ElementoLista{dato});

    if (empty(lista)) {
        lista = elem;  // Now it is the only element in the list
    }
    else {
        // Traverse the list to the latest element
        std::shared_ptr<ElementoLista> iterator = lista;
        while (iterator->next != nullptr) {
            iterator = iterator->next;
        }
        // The new element will become the latest one
        iterator->next = elem;
    }
}



void Lista::push_front (std::shared_ptr <ElementoLista> lista, const Pedido& dato) {
    std::shared_ptr <ElementoLista> elem = std::make_shared <ElementoLista> (ElementoLista{dato});

    if (empty(lista)) {
        lista = elem;
    }
    else {
        elem -> next = lista;
        lista = elem;
    }
}


void Lista::swap(std::shared_ptr<ElementoLista>& lista, int pos1, int pos2) {
    Pedido& dato1 = at(lista, pos1);  // Note the reference
    Pedido& dato2 = at(lista, pos2);  // Note the reference
    std::swap(dato1, dato2);
}



bool Lista::equal(const Pedido& lhs, const Pedido& rhs) {
    return (lhs.fruta == rhs.fruta && lhs.cantidad == rhs.cantidad);
}

int Lista::find(std::shared_ptr<ElementoLista> lista, const Pedido& dato) {
    std::shared_ptr<ElementoLista> iterator = lista;
    int found = -1; // If not found, it will return -1
    int idx = 0;
    while (iterator != nullptr) {
        if (equal(iterator->pedido, dato)) {  // Use external function to compare
            found = idx;
            break;
        }
        iterator = iterator->next;
        idx++;
    }
    return found;
}

bool Lista::equal (const Pedido& lhs, const Pedido& rhs) {
    return (lhs.fruta == rhs.fruta && lhs.cantidad == rhs.cantidad);
}


int Lista::find (std::shared_ptr <ElementoLista> lista, const Pedido& dato) {
    std::shared_ptr <ElementoLista> iterador = lista;
    int found = -1;
    int idx = 0;
    while (iterador != nullptr) {
        if (equal(iterador -> pedido, dato)) {
            found = idx;
            break;
        }
        iterador = iterador -> next;
        idx++;
    }
    return found;
}




int main() {
    Lista llena;
    Lista vacia;

    Pedido fruta1 = {3, "manzanas"};
    llena.push(fruta1);

    Pedido fruta2 = {2, "peras"};
    llena.push(fruta2);

    Pedido fruta3 = {2, "manzanas"};
    llena.push(fruta3);

    Pedido fruta4 = {20, "naranjas"};
    llena.push(fruta4);

    std::shared_ptr<ElementoLista> e1 = std::make_shared<ElementoLista>(ElementoLista{fruta1});
    std::shared_ptr<ElementoLista> e2 = std::make_shared<ElementoLista>(ElementoLista{fruta2});
    std::shared_ptr<ElementoLista> e3 = std::make_shared<ElementoLista>(ElementoLista{fruta3});

    std::shared_ptr<ElementoLista> e10 = std::make_shared<ElementoLista>(ElementoLista{fruta1});

        // Los podemos poner en "orden" (uno detrás de otro)
    e1->next = e2;
    e2->next = e3;

        // La lista la representamos por el primer elemento
    std::shared_ptr<ElementoLista> listaLlena = e1;

// ENTRAR A ESTE ENLACE https://replit.com/@diegogs2323/GummyBitterArray#main.cpp

    std::cout << "Tamaño de la lista: " << llena.size(e1) << "\n";
    std::cout << "La lista esta vacia: " << llena.empty(e1) << "\n"; // 0 Esta con cosas
    std::cout << "La lista esta vacia: " << vacia.empty(e1) << "\n"; // 1 Esta vacia


    //llena.push_front(e1);
}
