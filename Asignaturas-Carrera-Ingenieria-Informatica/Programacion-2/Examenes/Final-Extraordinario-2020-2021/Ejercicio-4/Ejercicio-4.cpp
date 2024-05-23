#include <iostream>
#include "integer.h"

using namespace std;

int main()
{

    try
    {
        std::vector<int> factoresNumeroPositivo = {};

        Integer primero{30};
        Integer segundo{6};

        std::cout << primero.isPrime() << "\n";
        factoresNumeroPositivo = primero.getFactors();

        for (int elem : factoresNumeroPositivo)
        {
            std::cout << elem << " ";
        }

        std::cout << "\n";
    }

    catch (string e)
    {
        cout << e << "\n";
    }
}
