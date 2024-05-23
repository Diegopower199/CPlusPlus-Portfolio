#include "cuadrado.h"

Cuadrado::Cuadrado()
{
}

float Cuadrado::getArea() const
{
    return lado * lado;
}

void Cuadrado::setLado(float l)
{
    if (l < 0)
        l = 0;
    else
        lado = l;
}

float Cuadrado::getPerimetro() const
{
    return lado * 4;
}

void Cuadrado::print()
{
    cout << "Cuadrado de lado " << lado << "\n";
    cout << "Area: " << getArea() << "\n";
    cout << "Perimetro: " << getPerimetro() << "\n";
}

float Cuadrado::getLado() const
{
    return lado;
}
