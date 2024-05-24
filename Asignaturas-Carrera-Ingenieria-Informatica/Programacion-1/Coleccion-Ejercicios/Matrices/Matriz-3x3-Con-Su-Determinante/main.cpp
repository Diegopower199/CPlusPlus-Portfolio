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

  int determinante = (mat.at(0).at(0) * mat.at(1).at(1) * mat.at(2).at(2) + mat.at(1).at(0) * mat.at(2).at(1) * mat.at(0).at(2) + mat.at(0).at(1) * mat.at(1).at(2) * mat.at(2).at(0)) - (mat.at(0).at(2) * mat.at(1).at(1) * mat.at(2).at(0) + mat.at(1).at(2) * mat.at(2).at(1) * mat.at(0).at(0) + mat.at(1).at(0) * mat.at(0).at(1) * mat.at(2).at(2));

  std::cout << determinante;
}