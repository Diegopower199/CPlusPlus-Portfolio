#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo
{
public:
    Complejo(float r, float i);

    float getReal() const;

    float getImaginario() const;

private:
    float r;
    float i;
};

#endif
