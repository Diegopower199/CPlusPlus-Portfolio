#include <iostream>
#include <vector>

int main()
{
    std::cout << "¿Cuantos términos desea calcular de la serie?";
    int terminosCalcular = 0;
    std::cin >> terminosCalcular;

    std::vector<double> vec{8, 7};
    double numero = 0;
    double primeraParte = 0;
    double segundaParte = 0;

    for (int i = 2; i < terminosCalcular; i++)
    {
        primeraParte = vec.at(i - 1);
        segundaParte = vec.at(i - 2);

        numero = (primeraParte - segundaParte) / 2;

        vec.push_back(numero);
    }

    double maximoValor = -99999999;
    double minimoValor = 99999999;

    for (auto elem : vec)
    {
        std::cout << elem << ", ";
        if (maximoValor < elem)
        {
            maximoValor = elem;
        }

        if (minimoValor > elem)
        {
            minimoValor = elem;
        }
    }

    std::cout << "\nMaximo valor: " << maximoValor << "\nMinimo valor: " << minimoValor << "\n";

    std::vector<double> numerosPositivos = {};
    std::vector<double> numerosNegativos = {};

    for (auto elem : vec)
    {
        if (elem > 0)
        {
            numerosPositivos.push_back(elem);
        }
        else
        {
            numerosNegativos.push_back(elem);
        }
    }

    std::vector<std::vector<double>> MisSeries = {vec, {1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};

    for (std::vector elem : MisSeries)
    {
        for (double j : elem)
        {
            std::cout << j << ", ";
        }
        std::cout << "\n\n";
    }
}