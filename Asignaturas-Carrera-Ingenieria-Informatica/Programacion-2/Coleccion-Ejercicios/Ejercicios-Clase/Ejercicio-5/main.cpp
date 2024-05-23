#include <iostream>
#include "complejo.h"
#include "matriz2.h"
#include "vector3.h"

using namespace std;

template <typename T>
T suma(T const &a, T const &b)
{
    return a + b;
}

template <>
Complejo suma(Complejo const &a, Complejo const &b)
{
    float real = a.getReal() + b.getReal();
    float im = a.getImaginario() + b.getImaginario();
    return Complejo{real, im};
}

Vector3 suma(Vector3 const &a, Vector3 const &b)
{
    auto x = a.getX() + b.getX();
    auto y = a.getY() + b.getY();
    auto z = a.getZ() + b.getZ();
    return Vector3{x, y, z};
}

template <typename T>
T resta(T const &a, T const &b)
{
    return a - b;
}

Complejo resta(Complejo const &a, Complejo const &b)
{
    float real = a.getReal() - b.getReal();
    float im = a.getImaginario() - b.getImaginario();
    return Complejo{real, im};
}

Vector3 resta(Vector3 const &a, Vector3 const &b)
{
    auto x = a.getX() - b.getX();
    auto y = a.getY() - b.getY();
    auto z = a.getZ() - b.getZ();
    return Vector3{x, y, z};
}

template <typename T>
T multiplicacion(T const &a, T const &b)
{
    return a * b;
}

Complejo multiplicar(Complejo const &a, Complejo const &b)
{
    auto z = a.getReal() * b.getReal() - a.getImaginario() * b.getImaginario();
    auto y = a.getReal() * b.getImaginario() + a.getImaginario() * b.getReal();
    return Complejo{z, y};
}

Vector3 multiplicacion(Vector3 const &a, Vector3 const &b)
{
    auto x = a.getX() * b.getX();
    auto y = a.getY() * b.getY();
    auto z = a.getZ() * b.getZ();
    return Vector3{x, y, z};
}

int main() {}
