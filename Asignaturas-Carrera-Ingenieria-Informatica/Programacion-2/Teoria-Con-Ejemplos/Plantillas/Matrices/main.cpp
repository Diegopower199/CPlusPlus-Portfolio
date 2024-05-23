#include <iostream>
#include <matriz.h>
#include <array>

int main()
{
    std::array<std::array<float, 3>, 3> a = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matriz<std::array<std::array<float, 3>, 3>> value = {a};

    std::cout << value;
}
