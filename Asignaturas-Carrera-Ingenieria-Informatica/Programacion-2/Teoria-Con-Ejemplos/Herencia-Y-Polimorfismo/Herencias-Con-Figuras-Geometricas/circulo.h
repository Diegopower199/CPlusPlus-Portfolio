#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"

class Circulo : public Figura
{
public:
    Circulo();

    void computeArea();

private:
    float radio;
};

#endif
