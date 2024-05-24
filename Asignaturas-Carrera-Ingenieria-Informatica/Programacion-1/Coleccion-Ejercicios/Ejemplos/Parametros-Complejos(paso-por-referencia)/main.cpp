#include <iostream>

void foo(int &a)
{
  a = 5;
  std::cout << a << "\n";
}

void cambiarNumero(int &c)
{
  std::cin >> c;
  std::cout << c << "\n";
}

int main()
{
  int b = 4;
  foo(b);
  std::cout << b;

  std::cout << "\n"
            << "\n";
  int e = 1;

  cambiarNumero(e);
  std::cout << e << "\n";
  std::cout << e << "\n";
  std::cout << e << "\n";
  std::cout << e << "\n";
}