#include <iostream>
#include "templates.h"
#include <functional>

using namespace std;

int main()
{
  // Las funciones tempoplatizadas se deben declarar y definir SIEMPRE en archivos .h
  print<int>(3); // 3
  print<string>("hola");

  // Plantillas templatizadas con struct
  Persona yo{"Alberto", 23};
  print<Persona>(yo);

  // Múltiples tipos templatizados
  print<int, string>(1, "hola");            // T -> int, Y -> string
  print<string, string>("hola", "que tal"); // T -> string, Y ->string

  // Ejemplos del uso del forEach
  vector<int> v{1, 2, 3, 4};
  forEach<vector<int>, int>(v, [](auto elem)
                            { cout << elem << "\n"; });
}
