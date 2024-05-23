#include <iostream>
#include <array>

int main()
{
  std::array<int, 7> notas = {3, 7, 7, 6, 4, 3, 2};

  int contadorVeces = 0;

  for (int num : notas)
  {
    if (num == 7)
    {
      contadorVeces++;
    }
  }

  std::cout << "El numero 7 aparece " << contadorVeces << " veces";
}