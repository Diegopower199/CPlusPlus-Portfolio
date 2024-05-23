#ifndef PENTAGONOREGULAR_H
#define PENTAGONOREGULAR_H

#include "figura.h"

class Pentagono_Regular : public Figura
{
public:
    Pentagono_Regular(float _lado, float _apotema);

    float getArea() const;
    float getPerimetro() const;
    std::string getTipo() const;

private:
    float lado;
    float apotema;
};

#endif
