#include <iostream>
#include "Persona.h"

using namespace std;

int main()
{
    Persona<std::string, int> primeraPersona{"Julio", 23};
    std::cout << primeraPersona.nombre() << ": " << primeraPersona.age() << "\n";
}
