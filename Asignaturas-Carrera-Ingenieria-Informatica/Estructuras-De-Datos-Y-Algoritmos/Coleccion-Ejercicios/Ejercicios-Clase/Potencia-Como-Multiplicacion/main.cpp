#include <iostream>

int prod_n_times(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }

    return a * prod_n_times(a, n - 1);
}

int main()
{
    int a = 2;
    int n = 3;
    int result = prod_n_times(a, n);
    std::cout << "a^n = " << result << std::endl;
    return 0;
}
