#ifndef TRIANGULOEQUILATERO_H
#define TRIANGULOEQUILATERO_H

#include "figura.h"
#include <math.h>

class TrianguloEquilatero : public Figura
{
public:
    TrianguloEquilatero(float _base);
    float getArea() const;
    float getPerimetro() const;
    std::string getTipo() const;

private:
    float base;
};

#endif
