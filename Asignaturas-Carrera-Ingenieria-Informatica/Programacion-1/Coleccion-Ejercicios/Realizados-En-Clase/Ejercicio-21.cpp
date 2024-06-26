#include <iostream>
#include <array>

int main()
{
  std::array<int, 10> serie = {};

  serie.at(0) = 0;
  serie.at(1) = 1;

  for (int pos = 2; pos < 10; pos++)
  {
    serie.at(pos) = serie.at(pos - 2) + serie.at(pos - 1);
  }

  for (auto elem : serie)
  {
    std::cout << elem << "\n";
  }
}