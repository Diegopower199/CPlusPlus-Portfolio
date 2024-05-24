#include <iostream>
#include <array>

int main()
{

  std::array<std::array<int, 3>, 3> mat;

  std::cout << "Matriz 1: \n";
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

  std::array<std::array<int, 3>, 3> mat2;
  std::cout << "Matriz 2: \n";
  for (int fila{0}; fila < 3; fila++)
  {
    for (int col{0}; col < 3; col++)
    {
      std::cout << "Introduce el elemento " << fila << ", " << col << ": ";
      int num;
      std::cin >> num;
      mat2.at(fila).at(col) = num;
    }
  }

  std::array<std::array<int, 3>, 3> mat3;
  std::cout << "Matriz suma: \n";
  for (int fila{0}; fila < 3; fila++)
  {
    for (int col{0}; col < 3; col++)
    {
      mat3.at(fila).at(col) = mat.at(fila).at(col) + mat2.at(fila).at(col);
      std::cout << mat3.at(fila).at(col) << " ";
    }
    std::cout << "\n";
  }
}