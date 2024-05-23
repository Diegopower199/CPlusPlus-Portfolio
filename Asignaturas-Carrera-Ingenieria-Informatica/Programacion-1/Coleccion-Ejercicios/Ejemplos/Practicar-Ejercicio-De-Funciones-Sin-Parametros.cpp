#include <iostream>
#include <vector>

std::vector<std::string> aWords()
{
  std::vector<std::string> palabras2 = {};
  std::string fraseUsuario = "";
  std::cout << "Introduce un texto: ";
  std::getline(std::cin, fraseUsuario);
  std::string palabra = "";

  for (char elem : fraseUsuario)
  {
    if (elem != ' ')
    {
      palabra.push_back(elem);
    }
    else
    {
      palabras2.push_back(palabra);
      palabra = "";
    }
  }

  if (palabra.size() > 0)
  {
    palabras2.push_back(palabra);
  }

  return palabras2;
}

int main()
{
  std::vector<std::string> words = aWords();
  for (auto elem : words)
  {
    std::cout << elem << "\n";
  }
}
