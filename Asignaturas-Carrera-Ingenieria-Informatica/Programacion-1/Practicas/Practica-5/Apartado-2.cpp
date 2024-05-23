#include <iostream>
using namespace std;

int main()
{
  string cadena;
  cout << "Introduce la operacion: ";
  getline(cin, cadena);

  if (cadena.at(0) == '+' || cadena.at(0) == '-')
  {
    char primerNumero = cadena.at(1);
    string cad;
    cad += primerNumero;
    int num = stoi(cad);

    if (cadena.at(0) == '-')
      num = -num;
    for (int i = 2; i < cadena.size(); i += 2)
    {
      char signo = cadena.at(i);
      char numero = cadena.at(i + 1);
      string cad;
      cad += numero;
      int n = stoi(cad);

      if (signo == '-')
        num = num - n;
      if (signo == '+')
        num = num + n;
    }
    cout << "El resultado es: " << num;
  }
  else
  {
    char numero = cadena.at(0);
    string cad;
    cad += numero;
    int num = stoi(cad);

    for (int i = 1; i < cadena.size(); i += 2)
    {
      char signo = cadena.at(i);
      char numero = cadena.at(i + 1);
      string cad;
      cad += numero;
      int n = stoi(cad);

      if (signo == '-')
        num = num - n;
      if (signo == '+')
        num = num + n;
    }
    cout << "El resultado es: " << num;
  }
}