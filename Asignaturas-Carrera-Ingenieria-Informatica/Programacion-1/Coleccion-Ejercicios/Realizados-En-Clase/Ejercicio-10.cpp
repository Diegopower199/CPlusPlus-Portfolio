#include <iostream>
#include <string>
#include <array>

int main()
{
  std::array<int, 7> notas = {1, 2, 3, 4, 5, 6, 7};
  int posicion = -1;
  int suma = 0;
  int suma2 = 0;

  for (int num : notas)
  {
    posicion = posicion + 1;

    suma = suma + num;
  }

  std::cout << "La media del array es " << suma / notas.size();
}