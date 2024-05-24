#include <iostream>

void saludar(std::string nombre, int edad)
{
  std::cout << "Hola " << nombre << " tiene " << edad << " años" << "\n";
}

int suma(int numero1, int numero2)
{
  return numero1 + numero2;
}

int main()
{
  int resultado = suma(3, 4);
  std::cout << resultado << "\n";
  saludar("Alberto", 20);
  saludar("Sara", 10);
}