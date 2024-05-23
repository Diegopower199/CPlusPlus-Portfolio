#include <iostream>

class Padre
{
public:
  Padre()
  {
    std::cout << "Constructor Padre\n";
  }
  ~Padre()
  { // OJO! se llaman cuándo finaliza el ámbito de la variable, y la llamada será en orden inverso al constructor
    std::cout << "Destructor Padre\n";
  }
};

// HIja -> Padre
class Hija : public Padre
{
public:
  Hija()
  {
    std::cout << "Constructor Hija\n";
  }
  ~Hija()
  { // OJO! se llaman cuándo finaliza el ámbito de la variable, y la llamada será en orden inverso al constructor
    std::cout << "Destructor Hija\n";
  }
};

// Nieta -> Hija
class Nieta : public Hija
{
public:
  Nieta()
  {
    std::cout << "Constructor Nieta\n";
  }
  ~Nieta()
  { // OJO! se llaman cuándo finaliza el ámbito de la variable, y la llamada será en orden inverso al constructor
    std::cout << "Destructor Nieta\n";
  }
};

int main()
{
  Nieta miClase;
  std::cout << "hago cosas\n";
  return 1;
}
