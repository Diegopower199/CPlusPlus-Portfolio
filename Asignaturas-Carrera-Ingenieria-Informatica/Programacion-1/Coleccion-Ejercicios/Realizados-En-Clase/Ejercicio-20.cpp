#include <iostream>
#include <vector>

int main()
{
  std::cout << "Introduce una cadena de texto: ";
  std::string textoUsuario = "";
  std::getline(std::cin, textoUsuario);
  std::vector<std::string> palabras = {};

  std::string palabra = "";

  for (auto elem : textoUsuario)
  {
    if (elem != ' ')
    {
      palabra.push_back(elem);
    }
    else
    {
      palabras.push_back(palabra);
      palabra = "";
    }
  }

  palabras.push_back(palabra);

  for (auto elem : palabras)
  {
    std::cout << elem << ", ";
  }
}