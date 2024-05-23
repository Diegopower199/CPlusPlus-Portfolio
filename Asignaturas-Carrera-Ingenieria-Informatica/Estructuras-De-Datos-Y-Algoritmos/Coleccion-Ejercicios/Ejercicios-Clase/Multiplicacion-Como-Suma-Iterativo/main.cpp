#include <iostream>

int main()
{
    int a = 2;
    int n = 3;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = a + result;
    }
    std::cout << "a + n = " << result << std::endl;
}