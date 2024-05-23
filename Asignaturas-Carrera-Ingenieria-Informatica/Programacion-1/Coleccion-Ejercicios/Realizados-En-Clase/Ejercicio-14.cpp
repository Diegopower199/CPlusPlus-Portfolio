#include <iostream>
#include <vector>

int main()
{
  std::vector<int> notas = {1, 3, 4, 5, 6, 7};
  std::vector<int> numeroPares = {};
  int pos = 0;

  for (int num : notas)
  {
    if (num % 2 == 0)
    {
      numeroPares.push_back(num);
    }
    pos++;
  }

  for (auto num : numeroPares)
  {
    std::cout << num << "\n";
  }
}