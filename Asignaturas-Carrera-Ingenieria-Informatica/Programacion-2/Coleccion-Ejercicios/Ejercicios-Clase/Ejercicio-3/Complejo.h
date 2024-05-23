#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

using namespace std;

class Complejo
{
public:
    Complejo(float = 0, float = 0);
    void pedirDatos();

    float getReal() const;
    void setReal(float value);

    float getImaginario() const;
    void setImaginario(float value);

    void Suma(float, float, float, float);
    void Multiplicacion(float, float, float, float);
    void Modulo(float, float);
    void print();

private:
    float Real;
    float Imaginario;
};

#endif
