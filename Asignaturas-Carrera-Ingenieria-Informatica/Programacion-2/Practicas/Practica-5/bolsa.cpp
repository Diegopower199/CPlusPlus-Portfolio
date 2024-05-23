#include "bolsa.h"
#include <iostream>

Bolsa::Bolsa()
{
}
Bolsa::~Bolsa()
{
}

Bolsa::Bolsa(std::vector<int> &numeros)
{
    for (int pos = 1; pos < 21; pos++)
    {
        numeros.push_back(pos);
    }
}

void erase(std::vector<int> &myNumbers_in, int number_in)
{
    std::vector<int>::iterator iter = myNumbers_in.begin();
    std::vector<int>::iterator endIter = myNumbers_in.end();

    for (; iter != endIter; ++iter)
    {
        if (*iter == number_in)
        {
            myNumbers_in.erase(iter);
        }
    }
}

int Bolsa::sacarBola(std::vector<int> &vectorBolas)
{
    srand(time(NULL));
    int numeroAleatorio = 0;

    numeroAleatorio = (rand() % vectorBolas.size());

    for (int pos = 0; pos < vectorBolas.size(); pos++)
    {
        if (numeroAleatorio == vectorBolas.at(pos))
        {
            erase(vectorBolas, pos + 1);
        }
    }

    return numeroAleatorio;
}

bool Bolsa::quedanBolas(std::vector<int> &vectorBolas)
{
    return vectorBolas.empty();
}
