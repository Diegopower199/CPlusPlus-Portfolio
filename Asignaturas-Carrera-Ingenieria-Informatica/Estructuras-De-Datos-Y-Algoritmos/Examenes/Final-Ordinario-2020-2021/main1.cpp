#include <iostream>
#include "lista.h"
using namespace std;

int main()
{
    ElementoLista a{{3, "manzana"}};
    ElementoLista b{{2, "pera"}, make_shared<ElementoLista>(a)};
    ElementoLista c{{2, "manzana"}, make_shared<ElementoLista>(b)};

    Lista l;
    l.setInicio(c);

    Lista other;
    other = l.unificar();

    other.print();
}
