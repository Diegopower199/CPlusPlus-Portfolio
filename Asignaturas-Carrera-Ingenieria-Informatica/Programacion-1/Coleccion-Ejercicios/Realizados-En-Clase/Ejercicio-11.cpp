#include <iostream>
#include <array>

int main()
{
  std::array<int, 16> notas = {6, 6, 3, 6, 5, 7, 4, 5, 6, 8, 4, 5, 2, 1, 4, 8};

  std::array<int, 10> contadorVeces = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for (int num : notas)
  {
    contadorVeces.at(num)++;
  }

  int pos = 0;
  int maxValorEncontrado = 0;
  int elMaximo = 0;

  for (int num : contadorVeces)
  {

    if (num > maxValorEncontrado)
    {
      elMaximo = pos;
      maxValorEncontrado = num;
    }
    pos++;
  }

  std::cout << "El numero que mas aparece es el " << elMaximo << "\n";

  std::cout << "El numero " << elMaximo << " aparece " << maxValorEncontrado << " veces" << "\n";
}