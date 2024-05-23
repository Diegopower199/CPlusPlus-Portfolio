#ifndef CUADRADO_H
#define CUADRADO_H

#include "figura.h"

class Cuadrado : public Figura
{
public:
    Cuadrado(float _lado);
    float getArea() const;
    float getPerimetro() const;
    std::string getTipo() const;

private:
    float lado;
};

#endif
