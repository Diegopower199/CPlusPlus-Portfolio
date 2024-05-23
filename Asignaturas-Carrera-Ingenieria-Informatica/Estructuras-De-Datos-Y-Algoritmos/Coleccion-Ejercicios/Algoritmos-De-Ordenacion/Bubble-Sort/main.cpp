#include <iostream>
#include <vector>
#include <algorithm>

void bubble_sort(std::vector<int> &elements)
{
  for (int i = 0; i < elements.size() - 1; i++)
  {
    for (int k = 0; k < elements.size() - 1; k++)
    {
      if (elements[k] > elements[k + 1])
      {
        std::swap(elements[k], elements[k + 1]);
      }
    }
  }
}

int main()
{
  std::vector<int> elements = {5, 3, 8, 4, 2};
  bubble_sort(elements);
  for (int element : elements)
  {
    std::cout << element << " ";
  }
  std::cout << std::endl;
  return 0;
}
