#include <iostream>
#include <vector>
#include <functional>

int main()
{
  std::function<float(std::vector<float>)> media = [](std::vector<float> v)
  {
    float suma = 0;
    for (auto elem : v)
    {
      suma += elem;
    }
    return suma / v.size();
  };

  std::function<float(std::vector<float> const &)> suma = [](std::vector<float> const &v)
  {
    float suma = 0;
    for (auto elem : v)
    {
      suma += elem;
    }
    return suma;
  };

  std::function<float(std::vector<float> const &)> max = [](std::vector<float> const &v)
  {
    float max = -999999999;

    for (auto elem : v)
    {
      if (max < elem)
      {
        max = elem;
      }
    }
    return max;
  };

  std::function<float(std::vector<float> const &)> resta = [](std::vector<float> const &v)
  {
    float resta = v.at(0);
    for (int i = 1; i < v.size(); i++)
    {
      resta = resta - v.at(i);
    }
    return resta;
  };

  std::function<float(std::vector<float> const &)> modulo = [](std::vector<float> const &v)
  {
    float suma = 0;
    for (auto elem : v)
    {
      suma = suma + elem * elem;
    }
    return suma;
  };

  std::function<float(std::function<float(std::vector<float> const &)>, std::function<float(std::vector<float> const &)>, std::vector<std::vector<float>> const &)> comp = [](std::function<float(std::vector<float> const &)> f1, std::function<float(std::vector<float> const &)> f2, std::vector<std::vector<float>> const &vv)
  {
    std::vector<float> g;

    for (auto v : vv)
    {
      g.push_back(f2(v));
    }
    return f1(g);
  };

  std::cout << comp(suma, media, {{1, 5}, {3, 7}}) << "\n";
  std::cout << comp(max, max, {{1, 5}, {3, 7}}) << "\n";
  std::cout << comp(max, suma, {{1, 5}, {3, 7}}) << "\n";
  std::cout << comp(max, resta, {{1, 5}, {3, 7}}) << "\n";
  std::cout << comp(media, modulo, {{1, 5}, {3, 7}}) << "\n";
  std::cout << comp(modulo, suma, {{1, 5}, {3, 7}}) << "\n";
}