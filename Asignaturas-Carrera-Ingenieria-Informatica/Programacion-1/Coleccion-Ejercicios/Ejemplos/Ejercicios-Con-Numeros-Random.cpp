#include <iostream>
#include <stdlib.h>

int main()
{
  srand(time(NULL));

  int numero = rand() % 10;
  std::cout << numero << "\n";
  std::cout << rand() % 10 << "\n";
  std::cout << rand() % 10 << "\n";
  std::cout << rand() % 10 << "\n";

  std::cout << "\n"
            << "\n";

  srand(2);

  int numero2 = rand() % 10;
  std::cout << numero2 << "\n";
  std::cout << rand() % 10 << "\n";
  std::cout << rand() % 10 << "\n";
  std::cout << rand() % 10 << "\n";
  std::cout << rand() % 10 << "\n";
}