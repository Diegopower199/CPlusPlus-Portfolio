#include "triangulo.h"

Triangulo::Triangulo(float _base, float _altura) : base{_base}, altura{_altura}
{
    if (_base <= 0 || _altura <= 0)
        throw std::string{"Dimensiones incorrectas"};
}

float Triangulo::getArea() const
{
    return (base * altura / 2);
}

float Triangulo::getPerimetro() const
{
    return (3 * base);
}

std::string Triangulo::getTipo() const
{
    return "\nTriangulo\n";
}
