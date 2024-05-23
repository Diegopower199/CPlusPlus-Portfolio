#include "complejo.h"

#include <iostream>
#include <math.h>

using namespace std;

Complejo::Complejo() : real{0}, imaginario{0}
{
}

Complejo::Complejo(float r, float i) : real{r}, imaginario{i}
{
}

void Complejo::print() const
{
    cout << "Complejo: " << "(" << real << " , " << imaginario << ")" << "\n";
}

float Complejo::modulo() const
{
    return sqrt(real * real + imaginario * imaginario);
}

float Complejo::getReal() const
{
    return real;
}

float Complejo::getImaginario() const
{
    return imaginario;
}

void Complejo::add(Complejo &other)
{
    real = real + other.real;
    imaginario = imaginario + other.imaginario;
}
