#include <iostream>

#include "stack.h"

int main() {
    Stack pila;

    std::cout << "Hola";

    auto print = [] ( TipoDato & dato) {
        std::cout << dato.numeros << "\n";

    };

    pila.push(TipoDato{122});

    pila.push(TipoDato{888});

    pila.push(TipoDato{555});

     std::cout << "PASO-1, ELEMENTOS DE LA PILA: ";


    pila.for_each(print);

    std::cout << "\n\nPASO-2, TAMANNO PILA=" << pila.size() << "\n\n";



    std::cout << "PASO-3, El primer elemento de la pila es: ";
    pila.top();

    std::cout << "\n\n";

    std::cout << "PASO-4, ELIMINAR EL PRIMER ELEMENTO: ";

    pila.pop();

    std::cout << "\n\nPASO-2, TAMANNO PILA=" << pila.size() << "\n\n";

    pila.for_each(print);

    std::cout << "EL PROGRAMA HA FINALIZADO";




}
