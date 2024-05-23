#include "complejo.h"

Complejo::Complejo()
{
}

Complejo::Complejo(float real, float imaginaria) : real{real}, imaginaria{imaginaria}
{
}

void Complejo::setReal(float &reales)
{
    real = reales;
}

void Complejo::setIm(float &im)
{
    imaginaria = im;
}

float Complejo::getReal() const
{
    return real;
}

float Complejo::getIm() const
{
    return imaginaria;
}

std::ostream &operator<<(std::ostream &os, Complejo n)
{
    os << n.real << ", " << n.imaginaria << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Complejo &n)
{
    is >> n.real;
    is >> n.imaginaria;
    return is;
}
