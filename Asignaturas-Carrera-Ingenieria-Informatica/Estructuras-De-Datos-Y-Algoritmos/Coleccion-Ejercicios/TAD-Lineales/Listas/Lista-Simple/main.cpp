#include <iostream>
#include "listasimple.h"


int main() {
    std::cout << "Hello World!" << "\n";
    ListaSimple lista;
    lista.push_back(TipoDato{"elem1, dni1"});
    lista.push_back(TipoDato{"elem2, dni1"});

    auto print = [] ( TipoDato & dato) {
        std::cout << dato.name << "\n";
    };

    lista.for_each(print);

    std::cout << "\n";

    auto print2 = [] (int pos, TipoDato & dato) {
        std::cout << pos << ": " << dato.name << "\n";
    };

    lista.enumerate(print2); //

    std::cout << "\n";

    std::cout << "Tamano de la lista: " << lista.size() << "\n";

    std::cout << "He llegado hasta aqui!" << "\n";

    return 0;
}

