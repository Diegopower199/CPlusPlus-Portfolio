#include <iostream>
#include <array>

int main()
{
  std::array<std::array<int, 3>, 3> mat;
  for (int fila{0}; fila < 3; fila++)
  {
    for (int col{0}; col < 3; col++)
    {
      std::cout << "Introduce el elemento " << fila << ", " << col << ": ";
      int num;
      std::cin >> num;
      mat.at(fila).at(col) = num;
    }
  }
  for (int fila{0}; fila < 3; fila++)
  {
    for (int col{0}; col < 3; col++)
    {
      std::cout << mat.at(col).at(fila) << " ";
    }
  }
}