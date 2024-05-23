#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo
{
public:
    Complejo();
    Complejo(float r, float i);

    void print() const;
    float modulo() const;

    float getReal() const;
    float getImaginario() const;

    void add(Complejo &other);

private:
    float real;
    float imaginario;
};

#endif
