#include <iostream>
#include <poligono.h>
#include "circuferencia.h"

using namespace std;

int main()
{
    PoligonoRegular miCuadrado(5, 4);
    miCuadrado.computeArea();
    cout << miCuadrado.getArea() << "\n";
    Circuferencia miCircunferencia(3);
    miCircunferencia.computeArea();
    cout << miCircunferencia.getArea() << "\n";
    miCircunferencia.computePerimetro();
    cout << miCircunferencia.getPerimetro() << "\n";

    return 0;
}
