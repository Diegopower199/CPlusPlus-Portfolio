#include "cuadrado.h"

Cuadrado::Cuadrado(float _lado) : lado{_lado}
{
    if (_lado <= 0)
        throw std::string{"Dimensiones incorrectas"};
}

float Cuadrado::getArea() const
{
    return (lado * lado);
}

float Cuadrado::getPerimetro() const
{
    return (4 * lado);
}

std::string Cuadrado::getTipo() const
{
    return "\nCuadrado\n";
}
