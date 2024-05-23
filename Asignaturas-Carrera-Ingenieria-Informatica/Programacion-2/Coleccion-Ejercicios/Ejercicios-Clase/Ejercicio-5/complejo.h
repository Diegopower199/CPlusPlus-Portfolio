#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo
{
    friend Complejo operator+(Complejo const &c1, Complejo const &c2);
    friend Complejo operator-(Complejo const &c1, Complejo const &c2);
    friend Complejo operator*(Complejo const &c1, Complejo const &c2);

public:
    Complejo();
    Complejo(float r, float i);

    float getReal() const;
    void setReal(float value);

    float getImaginario() const;
    void setImaginario(float value);

private:
    float real, imaginario;
};

#endif
