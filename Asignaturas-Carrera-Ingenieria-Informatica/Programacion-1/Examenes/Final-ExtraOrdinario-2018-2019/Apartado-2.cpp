#include <iostream>
#include <array>
#include <stdlib.h>
#include <time.h>
#include <vector>

std::vector<int> multiplosTresCinco(std::array<int, 100> numeros)
{
  std::vector<int> multiplos = {};

  for (auto elem : numeros)
  {
    if (elem % 3 == 0 || elem % 5 == 0)
    {
      multiplos.push_back(elem);
    }
  }
  return multiplos;
}

int main()
{
  std::array<int, 100> numeros = {};
  std::vector<int> multiplos = {};
  srand(time(NULL));

  for (int pos = 0; pos < 100; pos++)
  {
    numeros.at(pos) = (rand() % 1000) + 1;
  }

  std::cout << "100 numeros aleatorios: ";

  for (auto elem : numeros)
  {
    std::cout << elem << ", ";
  }

  multiplos = multiplosTresCinco(numeros);

  std::cout << "\n\nNumeros multiplos de 3 o 5: ";

  for (auto elem : multiplos)
  {
    std::cout << elem << ", ";
  }
}