#include <iostream>
#include <functional>
#include <array>

int main()
{

  std::function<int(int, int)> suma = [](int numero1, int numero2)
  {
    return numero1 + numero2;
  };

  std::function<int(int, int)> resta = [](int numero1, int numero2)
  {
    return numero1 - numero2;
  };

  std::function<int(int, int)> multiplicacion = [](int numero1, int numero2)
  {
    return numero1 * numero2;
  };

  std::function<int(int, int)> division = [](int numero1, int numero2)
  {
    return numero1 / numero2;
  };

  std::cout << "0. Hacer la suma de los dos numeros";
  std::cout << "1. Hacer la resta de los dos numeros";
  std::cout << "2. Hacer la division de los dos numeros";
  std::cout << "3. Hacer la multiplicacion de los dos numeros";

  int opcion = 0;
  std::cin >> opcion;

  std::cout << "Introduce dos numeros: ";
  float a;
  float b;

  std::cin >> a >> b;

  std::array<std::function<float(float, float)>, 4> operaciones{suma, resta, division, multiplicacion};

  std::cout << operaciones.at(opcion)(a, b);

  return 0;
}