#include <iostream>
#include "listadoble.h"
//La lista es una clase

using namespace std;

int main()
{
    listaDoble lista;
    lista.push_back(TipoDato{"elemento1", "333"});
    lista.push_back(TipoDato{"elemento2", "22"});
    auto print = [](TipoDato& dato){
        cout << dato.name << '\n';
    };

    lista.for_each(print);

    cout << "\n" << lista.size() << '\n';
    //cout << ((lista.getFront())->getDato()).name << '\n';
    cout << "He llegado hasta aqui" << endl;

    auto print2 = [](TipoDato& dato){
        cout << dato.name << '\n';
    };

    lista.for_each_reverse(print2);
    return 0;
}
