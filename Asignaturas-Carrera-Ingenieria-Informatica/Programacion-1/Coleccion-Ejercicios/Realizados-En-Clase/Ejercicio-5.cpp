#include <iostream>
#include <string>
#include <array>

int main()
{
  std::array<int, 7> notas = {2, 3, 5, 7, 1, 2, 7};
  int pos = -1;
  bool encontrado = false;

  for (int num : notas)
  {
    pos = pos + 1;

    if (num == 7)
    {
      encontrado = true;
      std::cout << "El array tiene el " << num << "\n";
      std::cout << "Esta en la posicion " << pos << "\n";
      break;
    }
  }
  if (!encontrado)
  {
    std::cout << "El array no tiene 7\n";
  }
}