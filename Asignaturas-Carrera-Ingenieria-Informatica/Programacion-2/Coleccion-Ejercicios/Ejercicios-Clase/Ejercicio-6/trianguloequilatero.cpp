#include "trianguloequilatero.h"

TrianguloEquilatero::TrianguloEquilatero(float _base) : base{_base}
{
    if (_base <= 0)
        throw std::string{"Dimensiones incorrectas"};
}

float TrianguloEquilatero::getArea() const
{
    return ((sqrt(3) / 4) * base * base);
}

float TrianguloEquilatero::getPerimetro() const
{
    return (3 * base);
}

std::string TrianguloEquilatero::getTipo() const
{
    return "\nTrianguloEquilatero\n";
}
