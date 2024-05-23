#include <iostream>
#include "complejo.h"
#include <memory>

using namespace std;

Complejo add(Complejo const &c1, Complejo const &c2)
{
    float real = c1.getReal() + c2.getReal();
    float imaginario = c1.getImaginario() + c2.getImaginario();

    Complejo r{real, imaginario};

    return r;
}
int main()
{
    float real, imaginario;
    cout << "Introduce la parte real e imaginaria separados por espacio: " << endl;
    cin >> real >> imaginario;
    Complejo comp{real, imaginario};
    comp.print();
}
