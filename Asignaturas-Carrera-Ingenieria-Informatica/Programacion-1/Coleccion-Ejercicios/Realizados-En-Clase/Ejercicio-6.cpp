#include <iostream>
#include <string>
#include <array>

int main()
{
  std::array<int, 7> notas = {1, 7, 3, 5, 7, 4, 8};
  int posicion = -1;
  bool encontrado = false;

  for (int num : notas)
  {
    posicion = posicion + 1;

    if (num == 7)
    {
      encontrado = true;
      std::cout << "Hemos encontrado el numero " << num << "\n";
      std::cout << "El numero esta en la posicion " << posicion << "\n";
    }
  }

  if (!encontrado)
  {
    std::cout << "No se ha encontrado el numero 7";
  }
}