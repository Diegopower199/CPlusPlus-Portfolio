#include <iostream>

int main()
{
  std::cout << "Introduce un texto ";
  std::string textoUsuario = "";
  std::getline(std::cin, textoUsuario);

  int contadorVeces = 0;

  for (char num : textoUsuario)
  {
    if (num == 'a')
    {
      contadorVeces = contadorVeces + 1;
    }
  }
  std::cout << "Aparecen " << contadorVeces << " veces";
}