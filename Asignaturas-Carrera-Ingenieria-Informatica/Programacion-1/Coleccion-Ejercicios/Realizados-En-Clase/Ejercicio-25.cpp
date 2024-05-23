#include <iostream>

int main()
{
  int numeroUsuario = 0;
  std::cout << "elige num:";
  std::cin >> numeroUsuario;
  int d{2};

  for (int pos = 2; pos < numeroUsuario / 2; pos++)
  {
    if (numeroUsuario % pos == 0)
    {
      std::cout << "No primo";
      return 0;
    }
  }
  std::cout << "Es primo";
  return 0;
}