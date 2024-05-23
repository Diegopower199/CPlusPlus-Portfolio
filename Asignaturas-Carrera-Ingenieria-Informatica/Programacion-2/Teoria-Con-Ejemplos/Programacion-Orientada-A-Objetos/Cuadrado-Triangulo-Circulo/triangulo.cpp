#include "triangulo.h"

Triangulo::Triangulo()
{
}

float Triangulo::getLadotriangulo() const
{
    return ladotriangulo;
}

void Triangulo::setLadotriangulo(float l)
{
    ladotriangulo = l;
}

float Triangulo::getAlturatriangulo() const
{
    return alturatriangulo;
}

void Triangulo::setAlturatriangulo(float h)
{
    if (h < 0)
        alturatriangulo = 0;
    else
        alturatriangulo = h;
}

float Triangulo::getArea()
{
    return (ladotriangulo * alturatriangulo) / 2;
}

float Triangulo::getPerimetro()
{
    return ladotriangulo * 3;
}

void Triangulo::print()
{
    cout << "Triangulo de lado " << ladotriangulo << "\n";
    cout << "Area: " << getArea() << "\n";
    cout << "Perimetro: " << getPerimetro() << "\n";
}
