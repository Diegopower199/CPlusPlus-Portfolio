#include "circuferencia.h"

Circuferencia::Circuferencia(float radio) : radio{radio}
{
}
void Circuferencia::computeArea()
{
    area = 3.14 * radio * radio;
}

void Circuferencia::computePerimetro()
{
    perimetro = 2 * 3.14 * radio;
}
