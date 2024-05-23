#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>

using namespace std;

class Cuadrado
{
public:
    Cuadrado();
    float getArea() const;
    float getPerimetro() const;

    void setLado(float l);
    float getLado() const;
    void print();

private:
    float lado;
};

#endif
