#include <iostream>

int main()
{
  std::cout << "Introduce un numero positivo: ";
  int num = 0;
  std::cin >> num;
  int divisor = 2;

  while (divisor < num)
  {
    if (num % divisor == 0)
    {
      std::cout << "No es primo";
      return 0;
    }

    divisor++;
  }

  std::cout << "Es primo! yay! \n";
  return 0;
}