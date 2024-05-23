#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <ostream>
#include <istream>

class Complejo
{
    friend std::ostream &operator<<(std::ostream &os, Complejo n);
    friend std::istream &operator>>(std::istream &is, Complejo &n);

public:
    Complejo();

    Complejo(float real, float imaginaria);

    void setReal(float &reales);
    float getReal() const;

    void setIm(float &im);
    float getIm() const;

private:
    float real;
    float imaginaria;
};

std::ostream &operator<<(std::ostream &os, Complejo n);
std::istream &operator>>(std::istream &is, Complejo &n);

#endif
