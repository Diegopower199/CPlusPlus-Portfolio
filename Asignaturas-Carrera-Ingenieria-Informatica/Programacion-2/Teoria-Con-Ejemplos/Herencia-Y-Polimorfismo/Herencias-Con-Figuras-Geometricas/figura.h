#ifndef FIGURA_H
#define FIGURA_H

class Figura
{
public:
    Figura();
    float getArea() const;
    float getPerimetro() const;

protected:
    float area;
    float perimetro;
};

#endif
