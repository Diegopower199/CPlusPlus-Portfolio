#include <iostream>

int main()
{
  std::cout << "Introduce un numero ";
  int numeroUsuario = 0;
  std::cin >> numeroUsuario;

  int factorial = 0;
  factorial = numeroUsuario;

  for (int pos = 1; pos < numeroUsuario; pos++)
  {

    factorial = factorial * pos;
  }

  std::cout << factorial;
}