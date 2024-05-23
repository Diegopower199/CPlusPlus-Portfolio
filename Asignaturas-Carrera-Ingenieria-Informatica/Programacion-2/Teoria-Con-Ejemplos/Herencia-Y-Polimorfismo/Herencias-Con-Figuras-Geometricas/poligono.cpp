#include "poligono.h"
#include "math.h"

PoligonoRegular::PoligonoRegular(float lado, int numero_lados) : lado{lado}, numero_lados{numero_lados}
{
}

void PoligonoRegular::computeArea()
{
    area = getPerimetro() * getApotema() / 2;
}

float PoligonoRegular::getPerimetro() const
{
    return lado * numero_lados;
}

float PoligonoRegular::getApotema() const
{
    return lado / (2 * std::tan(M_PI / numero_lados));
}
