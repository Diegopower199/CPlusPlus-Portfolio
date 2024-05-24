#ifndef FIGURA_H
#define FIGURA_H

#include <string>

class Figura
{
public:
    Figura();
    virtual ~Figura(){};

    virtual float getArea() const = 0;
    virtual float getPerimetro() const = 0;
    virtual std::string getTipo() const = 0;
};

#endif
