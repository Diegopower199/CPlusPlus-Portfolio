#include <iostream>
#include <array>
#include <set>
#include <cmath>

int main()
{
    int indice = 0;
    std::array<double, 10> cadena;
    double numero = 0.0;

    while (indice < 10)
    {
        std::cout << "\nIntroduce numero " << indice << ": ";
        std::cin >> numero;

        cadena.at(indice) = numero;
        indice++;
    }

    double acum{0};
    for (double elem : cadena)
    {
        acum = acum + elem;
    }

    double media = acum / cadena.size();
    std::cout << "La media es: " << media << std::endl;

    std::array<double, 10> desviacionTipica;

    for (int i = 0; i < cadena.size(); i++)
    {
        desviacionTipica.at(i) = pow(cadena.at(i) - media, 2);
    }

    double acumdesv{0};
    for (double elem : desviacionTipica)
    {
        acumdesv = acumdesv + elem;
    }

    std::cout << "La varianza es: " << acumdesv / desviacionTipica.size() << std::endl;
    std::cout << "La desviacion estandar es: " << sqrt(acumdesv / desviacionTipica.size()) << std::endl;

    std::set<double> Conj;
    for (double elem : cadena)
    {
        Conj.insert(elem);
    }

    int cont = 0;

    for (double elem : Conj)
    {
        if (cont == 0)
        {
            std::cout << "El valor minimo es: " << elem << std::endl;
        }
        else if (cont == Conj.size() - 1)
        {
            std::cout << "El valor maximo es: " << elem << std::endl;
        }

        cont++;
    }

    std::cout << "Los numeros introduciso ordenados de menor a mayor, sin repetición son: ";
    for (double elem : Conj)
    {
        std::cout << elem << "_";
    }

    return 0;
}