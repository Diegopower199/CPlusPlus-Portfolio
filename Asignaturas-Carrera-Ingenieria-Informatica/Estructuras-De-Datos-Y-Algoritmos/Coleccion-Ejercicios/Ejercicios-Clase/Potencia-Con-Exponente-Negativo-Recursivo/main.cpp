#include <iostream>

double pow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n > 0)
    {
        return x * pow(x, n - 1);
    }
    else
    {
        return 1 / (x * pow(x, 1 - n));
    }
}

int main()
{
    std::cout << "2^-2 = " << pow(2, -2) << std::endl;
    std::cout << "2^-3 = " << pow(2, -3) << std::endl; 
    return 0;
}
