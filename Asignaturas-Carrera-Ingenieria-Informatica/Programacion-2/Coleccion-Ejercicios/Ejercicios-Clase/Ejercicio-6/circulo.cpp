#include "circulo.h"
#include <math.h>

Circulo::Circulo(float _radio) : radio{_radio}
{
    if (_radio <= 0)
        throw std::string{"Dimensiones incorrectas"};
}

float Circulo::getArea() const
{
    return (2 * 3.14 * radio * radio);
}

float Circulo::getPerimetro() const
{
    return (2 * M_PI * radio);
}

std::string Circulo::getTipo() const
{
    return "\nCirculo\n";
}
