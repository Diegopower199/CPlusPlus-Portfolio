#include <iostream>
#include "fruta.h"
#include "ElementoListaDoble.h"
#include "LinkedList.h"

using namespace std;

int main()
{
    Fruta f1("naranja", 0.80, "valencia");
    Fruta f2("platano", 1.20, "canarias");
    LinkedList<Fruta> frutas;
    frutas.push_back(f1);
    frutas.push_back(f2);
    std::function<void(Fruta & fru)> f = [](Fruta &fru)
    {
        cout << fru << "\n";
    };
    frutas.for_each(f);
}
