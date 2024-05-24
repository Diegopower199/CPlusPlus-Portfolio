#include <iostream>

#include "listasimple.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    ListaSimple lista;
    lista.push_back(TipoDato{"elem1"});
    lista.push_back(TipoDato{"elem2"});

    auto print = [](int pos, TipoDato &dato)
    {
        cout << pos << ": " << dato.name << endl;
    };
    lista.enumerate(print);

    cout << lista.size() << endl;

    cout << "He llegado hasta aqui" << endl;
    return 0;
}
