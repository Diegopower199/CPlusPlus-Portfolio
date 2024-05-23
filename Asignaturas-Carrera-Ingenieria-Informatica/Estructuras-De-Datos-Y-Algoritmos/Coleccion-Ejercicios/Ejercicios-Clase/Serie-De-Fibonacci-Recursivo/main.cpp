#include <iostream>

int fibonacci(int index)
{
    if (index == 0)
    {
        return 0; // Primer término de la serie de Fibonacci
    }
    else if (index == 1)
    {
        return 1; // Segundo término de la serie de Fibonacci
    }
    else
    {
        // La serie de Fibonacci es la suma de los dos términos anteriores
        return fibonacci(index - 1) + fibonacci(index - 2);
    }
}

int main()
{
    int n_terms = 8;
    for (int i = 0; i < n_terms; i++)
    {
        std::cout << fibonacci(i) << ", ";
    }
    return 0;
}
