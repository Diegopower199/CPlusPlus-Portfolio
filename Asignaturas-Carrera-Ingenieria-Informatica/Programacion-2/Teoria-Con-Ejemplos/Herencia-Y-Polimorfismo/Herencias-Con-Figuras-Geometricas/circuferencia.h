#ifndef CIRCUFERENCIA_H
#define CIRCUFERENCIA_H

#include "figura.h"

class Circuferencia : public Figura
{
public:
    Circuferencia(float radio);
    void computeArea();
    void computePerimetro();

private:
    float radio;
};

#endif
