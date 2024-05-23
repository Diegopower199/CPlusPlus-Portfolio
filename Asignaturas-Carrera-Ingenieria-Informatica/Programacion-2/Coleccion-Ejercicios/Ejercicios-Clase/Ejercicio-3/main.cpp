#include <iostream>
#include "Complejo.h"
#include <math.h>

using namespace std;

int main()
{
  Complejo resultado;
  Complejo primerNumero;
  Complejo segundoNumero;

  cout << "PRIMERA PARTE ";
  cout << "\n";
  primerNumero.pedirDatos();
  cout << "\n";
  cout << "SEGUNDA PARTE ";
  cout << "\n";
  segundoNumero.pedirDatos();
  cout << "\n";

  resultado.Suma(primerNumero.getReal(), primerNumero.getImaginario(), segundoNumero.getReal(), segundoNumero.getImaginario());

  resultado.Multiplicacion(primerNumero.getReal(), primerNumero.getImaginario(), segundoNumero.getReal(), segundoNumero.getImaginario());

  cout << "Modulo 1: ";
  resultado.Modulo(primerNumero.getReal(), primerNumero.getImaginario());
  cout << "Modulo 2: ";
  resultado.Modulo(segundoNumero.getReal(), segundoNumero.getImaginario());
}
