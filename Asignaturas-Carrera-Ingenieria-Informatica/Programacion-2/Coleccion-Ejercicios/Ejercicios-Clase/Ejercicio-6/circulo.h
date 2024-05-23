#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"

class Circulo : public Figura
{
public:
    Circulo(float _radio);

    float getArea() const;
    float getPerimetro() const;
    std::string getTipo() const;

private:
    float radio;
};

#endif
