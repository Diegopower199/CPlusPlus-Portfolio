#include <iostream>

int fibonacci(int index)
{
    if (index == 0)
    {
        return 0;
    }
    else if (index == 1)
    {
        return 1;
    }
    else
    {
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
