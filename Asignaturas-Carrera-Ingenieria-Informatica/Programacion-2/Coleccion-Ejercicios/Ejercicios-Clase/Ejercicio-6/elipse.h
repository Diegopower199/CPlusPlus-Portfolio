#ifndef ELIPSE_H
#define ELIPSE_H

#include "figura.h"

class Elipse : public Figura
{
public:
    Elipse(float _semieje, float _semieje2);
    float getArea() const;
    float getPerimetro() const;
    std::string getTipo() const;

private:
    float semieje, semieje2;
};

#endif
