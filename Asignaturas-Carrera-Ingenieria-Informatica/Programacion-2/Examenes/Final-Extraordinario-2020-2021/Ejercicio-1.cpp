#include <iostream>
#include <vector>

std::vector<int> factorDeNumero(int numero)
{
    std::vector<int> resultado;
    int valorActual = 2;
    int valorInicial = numero;
    while (valorActual <= numero && valorActual < valorInicial)
    {
        if (numero % valorActual == 0)
        {
            resultado.push_back(valorActual);

            while (numero % valorActual == 0)
            {
                numero = numero / valorActual;
            }
        }

        valorActual++;
    }
    return resultado;
}

int main()
{

    std::cout << "Introduce un numero: ";
    int numero = 0;
    std::cin >> numero;

    std::vector<int> resultado = {};

    resultado = factorDeNumero(numero);

    for (int elem : resultado)
    {
        std::cout << elem << " ";
    }
}
