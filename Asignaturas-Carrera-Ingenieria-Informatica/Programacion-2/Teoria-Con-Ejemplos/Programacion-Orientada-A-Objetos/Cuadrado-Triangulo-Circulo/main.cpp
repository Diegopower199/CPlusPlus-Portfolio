#include <iostream>
#include "triangulo.h"
#include "cuadrado.h"
#include "circulo.h"

using namespace std;

int main()
{

    Cuadrado miCuadrado;
    miCuadrado.setLado(5);
    miCuadrado.print();
    cout << "\n-----\n\n";

    Circulo uncirculo;
    uncirculo.setRadio(12);
    uncirculo.print();
    cout << "\n-----\n\n";

    Triangulo untriangulo;
    untriangulo.setLadotriangulo(5);
    untriangulo.setAlturatriangulo(5);
    untriangulo.print();
}
