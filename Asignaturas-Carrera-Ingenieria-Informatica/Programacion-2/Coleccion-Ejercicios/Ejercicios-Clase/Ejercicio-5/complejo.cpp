#include "complejo.h"

Complejo::Complejo() : real{0}, imaginario{0} {}

Complejo::Complejo(float r, float i) : real{r}, imaginario{i} {}

float Complejo::getReal() const
{
    return real;
}

void Complejo::setReal(float value)
{
    real = value;
}

float Complejo::getImaginario() const
{
    return imaginario;
}

void Complejo::setImaginario(float value)
{
    imaginario = value;
}

Complejo operator+(Complejo const &c1, Complejo const &c2)
{
    Complejo result{c1.real + c2.real, c1.imaginario + c2.imaginario};
    return result;
}

Complejo operator-(Complejo const &c1, Complejo const &c2)
{
    Complejo result{c1.real - c2.real, c1.imaginario - c2.imaginario};
    return result;
}

Complejo operator*(Complejo const &c1, Complejo const &c2)
{
    Complejo result{c1.real * c2.real - c1.imaginario * c2.imaginario, c1.imaginario * c2.imaginario};
    return result;
}
