#include <iostream>
#include <array>
#include <memory>

int caminoMasCorto(std::array<std::array<int, 5>, 5> matriz, int origen, int destino, int distanciaRecorrida)
{
  if (origen == destino)
  {
    return distanciaRecorrida;
  }

  int mejorResultado = 0;
  bool avance = false;

  for (int columna = 0; columna < 5; columna++)
  {
    if (matriz.at(origen).at(columna) == 1)
    {
      std::array<std::array<int, 5>, 5> matriz2 = matriz;

      matriz2.at(origen).at(columna) = 0;
      matriz2.at(columna).at(origen) = 0;
      int distanciaDevuelta = caminoMasCorto(matriz2, columna, destino, distanciaRecorrida + 1);

      avance = true;

      if (mejorResultado == 0)
      {
        mejorResultado = distanciaDevuelta;
      }
      else if (distanciaDevuelta == 0)
      {
      }
      else if (distanciaDevuelta < mejorResultado)
      {
        mejorResultado = distanciaDevuelta;
      }
    }
  }

  if (avance == true)
  {
    return mejorResultado;
  }
  else
  {
    return 0;
  }
}

int main()
{

  std::array<std::string, 5> paradasMetro = {"Alonso Martinez", "Tribunal", "Bilbao", "San Bernardo", "Arguelles"};

  std::array<std::array<int, 5>, 5> matrizDeMetro = {{{0, 1, 1, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}}};

  std::string paradaInicialNombre = "";
  std::string paradaDestinoNombre = "";
  std::getline(std::cin, paradaInicialNombre);
  std::getline(std::cin, paradaDestinoNombre);

  int paradaInicialNumero = 0;
  int paradaDestinoNumero = 0;

  for (int pos = 0; pos < paradasMetro.size(); pos++)
  {
    if (paradaInicialNombre == paradasMetro.at(pos))
    {
      paradaInicialNumero = pos;
    }

    else if (paradaDestinoNombre == paradasMetro.at(pos))
    {
      paradaDestinoNumero = pos;
    }
  }

  std::cout << caminoMasCorto(matrizDeMetro, paradaInicialNumero, paradaDestinoNumero, 0);
}
