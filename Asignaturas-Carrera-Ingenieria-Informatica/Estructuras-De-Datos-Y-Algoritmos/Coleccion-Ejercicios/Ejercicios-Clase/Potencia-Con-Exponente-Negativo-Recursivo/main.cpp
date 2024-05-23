#include <iostream>

double pow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n > 0)
    {
        // Si el exponente es positivo, multiplicamos 'x' por sí mismo 'n' veces
        return x * pow(x, n - 1);
    }
    else
    {
        // Si el exponente es negativo, calculamos el inverso de 'x' elevado a la potencia positiva correspondiente
        return 1 / (x * pow(x, 1 - n));
    }
}

int main()
{
    std::cout << "2^-2 = " << pow(2, -2) << std::endl; // 0.25
    std::cout << "2^-3 = " << pow(2, -3) << std::endl; // 0.125
    return 0;
}
