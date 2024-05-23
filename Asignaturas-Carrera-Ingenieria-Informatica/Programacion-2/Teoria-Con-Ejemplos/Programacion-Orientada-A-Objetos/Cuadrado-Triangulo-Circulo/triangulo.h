#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <iostream>

using namespace std;

class Triangulo
{
public:
    Triangulo();
    float getLadotriangulo() const;
    void setLadotriangulo(float l);

    float getAlturatriangulo() const;
    void setAlturatriangulo(float h);

    float getArea();
    float getPerimetro();
    void print();

private:
    float ladotriangulo;
    float alturatriangulo;
};

#endif
