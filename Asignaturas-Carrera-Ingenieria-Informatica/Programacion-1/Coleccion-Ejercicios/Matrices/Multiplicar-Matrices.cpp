#include <iostream>
#include <array>

int mult(std::array<int, 3> f, std::array<int, 3> c)
{
  int num = 0;
  for (int i = 0; i < 3; i++)
  {
    num = f.at(i) * c.at(i) + num;
  }
  return num;
}

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
  std::array<int, 3> f;
  std::array<int, 3> c;
  for (int fila{0}; fila < 3; fila++)
  {
    for (int col{0}; col < 3; col++)
    {
      f = mat.at(fila);
      c.at(0) = mat2.at(0).at(col);
      c.at(1) = mat2.at(1).at(col);
      c.at(2) = mat2.at(2).at(col);
      mat3.at(fila).at(col) = mult(f, c);
    }
  }

  for (int fila{0}; fila < 3; fila++)
  {
    for (int col{0}; col < 3; col++)
    {
      std::cout << mat3.at(fila).at(col) << " ";
    }
    std::cout << "\n";
  }
}