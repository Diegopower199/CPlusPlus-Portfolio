#include <iostream>
#include <vector>

struct Familia
{
  int numeroIntegrantes = 0;
  char letraPuerta = ' ';
  std::vector<std::string> nombresMiembrosFamilia = {};
};

int main()
{
  std::string NombreCalle = "";
  std::string NumeroPortal = "";

  Familia familiaPerez, familiaGomez;
  std::vector<Familia> suCasa = {};

  NombreCalle = "Calle del Pez 3";
  familiaPerez.nombresMiembrosFamilia = {"Maria Isabel Gonzalez", "Pepe Pérez", "Manolito Pérez Gonzalez"};
  familiaPerez.numeroIntegrantes = familiaPerez.nombresMiembrosFamilia.size();
  familiaPerez.letraPuerta = 'A';

  suCasa.push_back(familiaPerez);

  NombreCalle = "Calle del Pez 3";
  familiaGomez.nombresMiembrosFamilia = {"Paquita Gómez"};
  familiaGomez.numeroIntegrantes = familiaGomez.nombresMiembrosFamilia.size();
  familiaGomez.letraPuerta = 'B';
  familiaGomez.nombresMiembrosFamilia = {"Paquita Gómez"};

  suCasa.push_back(familiaGomez);

  for (auto elem : suCasa)
  {
    std::cout << elem.numeroIntegrantes << "\n";
  }
}