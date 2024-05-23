#include <iostream>

using namespace std;

int minimoComunMultiplo(int numero1, int numero2)
{
    int menor = numero1;
    int mayor = numero2;

    if (numero1 > numero2)
    {
        menor = numero2;
        mayor = numero1;
    }

    int resultado = mayor;

    while (resultado % mayor != 0 || resultado % menor != 0)
    {

        resultado++;
    }

    return resultado;
}

int main()
{
    int numero1 = 0;
    int numero2 = 0;
    std::cout << "Introduce el numero 1: ";
    std::cin >> numero1;

    std::cout << "\nIntroduce el numero 2: ";
    std::cin >> numero2;

    std::cout << minimoComunMultiplo(numero1, numero2);
}
