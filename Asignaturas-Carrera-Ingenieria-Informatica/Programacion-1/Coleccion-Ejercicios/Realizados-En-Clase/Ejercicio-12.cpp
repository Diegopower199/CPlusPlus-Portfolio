#include <iostream>
#include <array>

int main()
{
  std::array<int, 11> notas = {1, 2, 7, 7, 4, 3, 3, 7, 7, 7, 2};

  int contador7Seguidos = 0;
  int mayorNumeroVeces = 0;

  for (int elem : notas)
  {

    if (elem == 7)
    {
      contador7Seguidos++;
    }
    else
    {
      contador7Seguidos = 0;
    }

    if (contador7Seguidos > mayorNumeroVeces)
    {
      mayorNumeroVeces = contador7Seguidos;
    }
  }

  std::cout << mayorNumeroVeces;
}