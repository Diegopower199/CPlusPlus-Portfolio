#include <iostream>
#include <vector>

bool primo(int x)
{
  if (x == 1 || x == 2)
  {
    return true;
  }
  for (int pos = 2; pos < x; pos++)
  {

    if (x % pos == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  std::vector<int> numerosPrimosUsuario = {};
  int calculoPrimosUsuario = 0;
  std::cout << "Cuantos numeros primos desea calcular: ";
  std::cin >> calculoPrimosUsuario;
  int numeros = 1;

  while (numerosPrimosUsuario.size() < calculoPrimosUsuario)
  {

    if (primo(numeros))
    {
      numerosPrimosUsuario.push_back(numeros);
    }
    numeros++;
  }

  for (int pos = 0; pos < numerosPrimosUsuario.size(); pos++)
  {
    std::cout << numerosPrimosUsuario.at(pos) << "\n";
  }
}