#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "figura.h"

class Triangulo : public Figura
{
public:
    Triangulo(float _base, float _altura);
    float getArea() const;
    float getPerimetro() const;
    std::string getTipo() const;

private:
    float base;
    float altura;
};

#endif
