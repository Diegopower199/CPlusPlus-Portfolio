#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <functional>

std::vector<int> filter(std::vector<int> v, std::function<bool(int)> f)
{
    std::vector<int> result;
    for (auto elem : v)
    {
        if (f(elem))
            result.push_back(elem);
    }
    return result;
}

int main()
{
    srand(time(NULL));
    std::vector<int> v = {};
    std::vector<int> v3 = {};

    for (int pos = 0; pos < 150; pos++)
    {
        v.push_back((rand() % 11) + 5);
    }

    std::function<bool(int)> filtroV1 = [](int a)
    {
        return (a > 12);
    };

    std::function<bool(int)> filtroV2 = [](int a)
    {
        return (a % 5 == 0);
    };

    for (auto elem : v)
    {
        v3.push_back(elem * 2);
    }

    std::vector<int> v1 = filter(v, filtroV1);
    std::vector<int> v2 = filter(v, filtroV2);

    for (auto elem : v1)
    {
        std::cout << elem << ", ";
    }
}
