#ifndef NUMEROPOSITIVO_H
#define NUMEROPOSITIVO_H

#include <string>

class NumeroPositivo
{
public:
    NumeroPositivo(float numero);

    float getNumero() const;
    void setNumero(float value);
    float divideBy(float otherNumber);
    float multiplyBy(float otherNumber);
    float add(float otherNumber);

private:
    float numero;
};

#endif
