#include "integer.h"
#include <iostream>
#include <string>
#include <vector>

Integer::Integer()
{
}

Integer::Integer(int _numeroPositivo)
{
    if (_numeroPositivo < 0)
    {
        throw std::string{"Error, debe ser un numero positivo"};
    }
    else
    {
        setNumeroPositivo(_numeroPositivo);
    }
}

int Integer::getNumeroPositivo() const
{
    return numeroPositivo;
}

void Integer::setNumeroPositivo(int value)
{
    numeroPositivo = value;
}

std::vector<int> Integer::getFactors()
{
    std::vector<int> resultado;
    int valorActual = 2;
    int valorInicial = numeroPositivo;
    while (valorActual <= numeroPositivo && valorActual < valorInicial)
    {
        if (numeroPositivo % valorActual == 0)
        {

            resultado.push_back(valorActual);

            while (numeroPositivo % valorActual == 0)
            {
                numeroPositivo = numeroPositivo / valorActual;
            }
        }

        valorActual++;
    }
    return resultado;
}

bool Integer::isPrime()
{

    int divisor = 2;

    while (divisor < numeroPositivo)
    {
        if (numeroPositivo % divisor == 0)
        {
            return false;
        }

        divisor++;
    }

    return true;
}

Integer operator*(Integer const &c1, Integer const &c2)
{
    int menor = c1.numeroPositivo;
    int mayor = c2.numeroPositivo;

    Integer result;

    if (c1.numeroPositivo > c2.numeroPositivo)
    {
        menor = c2.numeroPositivo;
        mayor = c1.numeroPositivo;
    }

    int resultado = mayor;

    while (resultado % mayor != 0 || resultado % menor != 0)
    {
        resultado++;
    }

    result = {resultado};

    return result;
}

Integer operator/(Integer const &c1, Integer const &c2)
{
    int menor = c1.numeroPositivo;
    int mayor = c2.numeroPositivo;
    Integer result;

    if (c1.numeroPositivo > c2.numeroPositivo)
    {
        menor = c2.numeroPositivo;
        mayor = c1.numeroPositivo;
    }

    int resultado = menor;

    while (mayor % resultado != 0 || menor % resultado != 0)
    {
        resultado--;
    }

    result = {resultado};

    return result;
}
