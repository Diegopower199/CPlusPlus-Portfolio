#include <iostream>
#include <vector>

int main()
{
  std::vector<std::string> palabras;
  std::cout << "Introduce un texto ";
  std::string texto = "";
  std::getline(std::cin, texto);

  std::string palabra = "";

  for (auto elem : texto)
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
    if (elem.find("a") != -1)
    {
      std::cout << elem << "\n";
    }
  }
}