#include <iostream>

struct Persona
{
  std::string nombre;
  int edad;
};

struct Coche
{
  std::string a;
  std::string b;
};

template <typename T>
void print(T const &a)
{
  std::cout << a << "\n";
}

template <>
void print(Persona const &a)
{
  std::cout << "nombre: " << a.nombre << "\n";
  std::cout << "edad: " << a.edad << "\n";
}

template <>
void print(Coche const &a)
{
  std::cout << "El coche de nacho tiene: " << a.a << " y " << a.b;
}

#include <iostream>

int main()
{
  Persona yo{"Alberto", 23};

  Coche nacho{"ruedas", "espejos"};
  print<Persona>(yo);

  print<Coche>(nacho);

  return 0;
}