#ifndef POLIGONO_H
#define POLIGONO_H

#include "figura.h"

class PoligonoRegular : public Figura
{
public:
    PoligonoRegular(float lado, int numero_lados);
    void computeArea();
    float getPerimetro() const;
    float getApotema() const;

private:
    float lado;
    int numero_lados;
    float apotema;
};

#endif
