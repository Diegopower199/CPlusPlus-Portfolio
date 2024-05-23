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

  auto doble = [](int x)
  {
    return 2 * x;
  };

  auto restos = [](int x)
  {
    return x % 2;
  };

  auto mayor3 = [](int x)
  {
    return x >= 3;
  };

  auto t = [](int x)
  {
    if (x % 2 == 0)
    {
      return x * 3;
    }
    else
    {
      return x * 5;
    }
  };

  auto multilplosTres = [](std::vector<int> v, std::function<int(int)> g)
  {
    std::vector<int> resultado = {};
  };

  auto filter = [](std::vector<int> v, std::function<bool(int)> g)
  {
    std::vector<int> resultado = {};

    for (auto elem : v)
    {
      if (elem >= 3)
      {
        resultado.push_back(g(elem));
      }
    }
    return resultado;
  };

  auto transform = [](std::vector<int> const &v, std::function<int(int)> g)
  {
    std::vector<int> result;

    for (auto elem : v)
    {
      result.push_back(g(elem));
    }
    return result;
  };

  auto forEach = [](std::vector<int> const &v, std::function<void(int)> g)
  {
    for (auto elem : v)
    {
      g(elem);
    }
  };

  std::vector<int> miVector = {1, 2, 3, 4, 5};
  std::vector<int> elDoble = transform(miVector, doble);
  std::vector<int> entreDosVector = transform(miVector, restos);
  std::vector<int> filtrados = filter(entreDosVector, mayor3);

  forEach(miVector, mostrar);
  forEach(miVector, mostrarPares);
  forEach(miVector, tripleValoresVector);

  forEach(entreDosVector, mostrar);

}