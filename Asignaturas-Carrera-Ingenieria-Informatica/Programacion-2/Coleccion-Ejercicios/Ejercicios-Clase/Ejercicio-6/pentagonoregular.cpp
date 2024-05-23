#include "pentagonoregular.h"

Pentagono_Regular::Pentagono_Regular(float _lado, float _apotema) : lado{_lado}, apotema{_apotema}
{
    if (_lado <= 0)
        throw std::string{"Dimensiones incorrectas"};
}

float Pentagono_Regular::getArea() const
{
    return ((5 * lado * apotema) / 2);
}

float Pentagono_Regular::getPerimetro() const
{
    return (lado + lado + lado + lado + lado);
}

std::string Pentagono_Regular::getTipo() const
{
    return "\nPentagono Regular\n";
}
