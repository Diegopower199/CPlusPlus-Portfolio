#include <iostream>
#include "complejo.h"

using namespace std;

int main()
{

    Complejo uno(4, 5);
    Complejo dos{};

    std::cout << uno;

    std::cin >> dos;
    std::cin >> uno;

    std::cout << dos << "\n"
              << uno;
}
