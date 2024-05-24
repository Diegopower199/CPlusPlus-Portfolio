#include "numeropositivo.h"

NumeroPositivo::NumeroPositivo(float numero) : numero{numero} {}

float NumeroPositivo::getNumero() const
{
    return numero;
}

void NumeroPositivo::setNumero(float value)
{
    if (value <= 0)
    {
        throw std::string{"El numero debe ser postivo\n"};
    }
    else
    {
        numero = value;
    }
}

float NumeroPositivo::divideBy(float otherNumber)
{
    if (otherNumber <= 0)
    {
        throw std::string{"El numero debe ser mayor que 0\n"};
    }
    else
    {
        return (numero / otherNumber);
    }
}

float NumeroPositivo::multiplyBy(float otherNumber)
{
    if (otherNumber <= 0)
    {
        throw std::string{"El numero debe ser mayor que 0\n"};
    }
    return (numero * otherNumber);
}

float NumeroPositivo::add(float otherNumber)
{
    if (numero + otherNumber <= 0)
    {
        throw std::string{"El resultado debe ser mayor que 0\n"};
    }
    else
    {
        return (numero + otherNumber);
    }
}
