#include <iostream>
#include <array>
#include <vector>

int main()
{
  std::vector<std::string> palabras = {"perro", "gato", "guardar", "andres", "luis", "guardar", "botella"};

  std::vector<std::string> guardadas;

  int pos = 0;

  for (auto elem : palabras)
  {
    if (elem == "guardar")
    {
      if (pos != palabras.size() - 1)
      {
        guardadas.push_back(palabras.at(pos + 1));
      }
    }
    pos++;
  }

  for (auto elem : guardadas)
  {
    std::cout << elem << "\n";
  }
}