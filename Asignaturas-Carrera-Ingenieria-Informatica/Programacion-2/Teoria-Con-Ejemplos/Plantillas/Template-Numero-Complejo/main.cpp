#include <iostream>
#include "complejo.h"
using namespace std;

template <typename T>
T suma(T const &a, T const &b)
{
    return a + b;
}

Complejo operator+(Complejo const &t1, Complejo const &t2)
{
    float real = t1.getReal() + t2.getReal();
    float im = t1.getImaginario() + t2.getImaginario();
    return Complejo{real, im};
}

int main()
{
    std::cout << suma<int>(3, 4) << "\n";
    std::cout << suma<std::string>("hola ", "mundo") << "\n";
    std::cout << suma<float>(3.2, 4.5) << "\n";

    Complejo uno{1, 2};
    Complejo dos{1, 2};

    auto laSuma = suma(uno, dos);
    return 0;
}