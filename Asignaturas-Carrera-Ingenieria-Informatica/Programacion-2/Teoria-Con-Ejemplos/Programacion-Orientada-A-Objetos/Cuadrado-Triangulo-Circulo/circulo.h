#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>

using namespace std;

class Circulo
{
public:
    Circulo();
    float getArea() const;
    float getLongitud() const;

    float getRadio() const;
    void setRadio(float value);
    void print();

private:
    float radio;
};

#endif
