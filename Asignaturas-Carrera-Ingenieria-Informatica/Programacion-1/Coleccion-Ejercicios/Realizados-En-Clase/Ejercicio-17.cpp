#include <iostream>
#include <vector>

int main()
{
  std::cout << "Introduce 3 numeros: ";
  int numeroA = 0;
  int numeroB = 0;
  int numeroC = 0;
  std::cin >> numeroA >> numeroB >> numeroC;

  std::vector<int> multiplos;

  int num = numeroA;

  while (num <= numeroB)
  {
    if (num % numeroC == 0)
    {
      multiplos.push_back(num);
    }
    num++;
  }

  for (int elem : multiplos)
  {
    std::cout << elem << "\n";
  }
}