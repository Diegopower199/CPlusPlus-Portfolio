#include <iostream>
#include <vector>

int main()
{
  std::cout << "introduza un texto\n";
  std::string textoUsuario = "";
  std::getline(std::cin, textoUsuario);
  std::vector<std::string> palabras = {};
  std::string word = "";
  for (auto elem : textoUsuario)
  {
    if (elem != ' ')
    {
      word.push_back(elem);
    }
    else
    {
      palabras.push_back(word);
      word.clear();
    }
  }
  palabras.push_back(word);

  for (auto elem : palabras)
  {

    if (elem.at(0) == 'a')
    {
      std::cout << elem << "\n";
    }
  }
}
