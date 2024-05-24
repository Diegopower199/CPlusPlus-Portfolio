#include <iostream>
#include <functional>
#include <vector>

int main()
{

  std::function<void(int)> mostrar = [](int x)
  {
    std::cout << x << "\n";
  };

  auto mostrarPares = [](int x)
  {
    if (x % 2 == 0)
    {
      std::cout << x << "\n";
    }
  };

  auto tripleValoresVector = [](int x)
  {
    std::cout << 3 * x << "\n";
  };

  auto forEach = [](std::vector<int> const &v, std::function<void(int)> g)
  {
    for (auto elem : v)
    {
      g(elem);
    }
  };

  std::vector<int> miVector = {1, 2, 3, 4, 5};

  forEach(miVector, mostrar);
  forEach(miVector, mostrarPares);
  forEach(miVector, tripleValoresVector);
}