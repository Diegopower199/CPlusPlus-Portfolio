#include <iostream>

int sum_n_times(int a, int n)
{
    return a + sum_n_times(a, n - 1);
}

int main()
{
    int a = 2;
    int n = 3;
    int result = sum_n_times(2, 3);
    std::cout << "a * n = " << result << std::endl;
}