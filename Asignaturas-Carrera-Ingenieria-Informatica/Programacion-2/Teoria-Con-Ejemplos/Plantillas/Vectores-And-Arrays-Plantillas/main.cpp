#include <iostream>
#include <array>
#include <vector>

template <typename T>
T suma(T const &v1, T const &v2)
{
  return v1 + v2;
}

template <>
std::array<float, 3> suma(std::array<float, 3> const &v1, std::array<float, 3> const &v2)
{
  std::array<float, 3> result;
  for (int pos = 0; pos < 3; pos++)
  {
    result.at(pos) = v1.at(pos) + v2.at(pos);
  }
  return result;
}

template <>
std::vector<float> suma(std::vector<float> const &v1, std::vector<float> const &v2)
{
  std::vector<float> result;
  for (int pos = 0; pos < 3; pos++)
  {
    result.push_back(v1.at(pos) + v2.at(pos));
  }
  return result;
}

int main()
{

  std::vector<float> vector;

  std::vector<float> q = {1, 2, 3};
  std::vector<float> w = {1, 2, 3};

  vector = suma<std::vector<float>>(q, w);

  for (auto elem : vector)
  {
    std::cout << elem << "\n";
  }

  std::array<float, 3> array;

  std::array<float, 3> a = {1, 2, 3};
  std::array<float, 3> b = {1, 2, 3};

  array = suma<std::array<float, 3>>(a, b);

  for (auto elem : array)
  {
    std::cout << elem << "\n";
  }

  std::cout << vector.size();
}
