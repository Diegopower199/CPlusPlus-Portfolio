#include <iostream>
#include <array>
using namespace std;

int main()
{
  array<array<int, 3>, 3> mat;
  for (int fila{0}; fila < 3; fila++)
  {
    for (int col{0}; col < 3; col++)
    {
      cout << "Introduce el elemento " << fila << ", " << col << ": ";
      int num;
      cin >> num;
      mat.at(fila).at(col) = num;
    }
  }
  for (auto fila : mat)
  {
    for (auto elem : fila)
    {
      cout << elem << " ";
    }
    cout << "\n";
  }
}