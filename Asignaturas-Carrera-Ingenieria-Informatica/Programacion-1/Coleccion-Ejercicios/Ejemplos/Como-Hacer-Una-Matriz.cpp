#include <iostream>
#include <array>

int main()
{
  std::array<std::array<float, 3>, 3> matriz1;

  std::array<std::array<float, 3>, 3> matriz2;

  for (int fila = 0; fila < 3; fila++)
  {
    for (int col = 0; col < 3; col++)
    {
      std::cout << "Introduce el elemento " << fila + 1 << ", " << col + 1 << ": ";
      float num = 0;
      std::cin >> num;
      matriz1.at(fila).at(col) = num;
    }
  }

  for (int fila = 0; fila < 3; fila++)
  {
    for (int col = 0; col < 3; col++)
    {
      float num = (rand() % 20) + 5;
      matriz2.at(fila).at(col) = num;
    }
  }

  for (auto fila : matriz1)
  {
    for (auto elem : fila)
    {
      std::cout << elem << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\n";

  for (auto fila : matriz2)
  {
    for (auto elem : fila)
    {
      std::cout << elem << " ";
    }
    std::cout << "\n";
  }
}