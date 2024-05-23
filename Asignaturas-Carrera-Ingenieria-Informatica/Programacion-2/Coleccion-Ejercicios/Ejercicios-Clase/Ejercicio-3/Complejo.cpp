#include "Complejo.h"
#include <iostream>
#include <math.h>

using namespace std;

Complejo::Complejo(float a, float b)
{
    Real = a;
    Imaginario = b;
}

float Complejo::getReal() const
{
    return Real;
}

void Complejo::setReal(float value)
{
    Real = value;
}

float Complejo::getImaginario() const
{
    return Imaginario;
}

void Complejo::setImaginario(float value)
{
    Imaginario = value;
}

void Complejo::Suma(float a, float b, float c, float d)
{
    cout << "Suma: (" << a + c << " , " << b + d << ")" << "\n";
}

void Complejo::Multiplicacion(float a, float b, float c, float d)
{
    cout << "Multiplicacion: (" << a * c << " , " << b * d << ")" << "\n";
}

void Complejo::Modulo(float a, float b)
{
    float dentro = (a * a) + (b * b);
    cout << pow(dentro, 0.5) << "\n";
}

void Complejo::print()
{
    cout << "(" << Real << " , " << Imaginario << ")" << "\n";
}

void Complejo::pedirDatos()
{
    cout << "Introduce la parte real del numero: ";
    cin >> Real;
    cout << "Introduce la parte imaginaria: ";
    cin >> Imaginario;
}
