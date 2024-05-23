#include "elipse.h"
#include <math.h>

Elipse::Elipse(float _semieje, float _semieje2) : semieje{_semieje}, semieje2{_semieje2}
{
    if (_semieje <= 0 || _semieje2 <= 0)
        throw std::string{"Dimensiones incorrectas"};
}

float Elipse::getArea() const
{
    return (M_PI * semieje * semieje2);
}

float Elipse::getPerimetro() const
{
    return ((2 * M_PI) * (sqrt((semieje * semieje + semieje2 * semieje2) / 2)));
}

std::string Elipse::getTipo() const
{
    return "\nElipse\n";
}
