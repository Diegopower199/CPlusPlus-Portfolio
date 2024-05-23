#include <iostream>
using namespace std;

string unionFuncion(string palabra1, string palabra2)
{
  string letrasAmbasPalabrasSinRepeticion = "";
  for (auto elem : palabra1)
  {
    if (letrasAmbasPalabrasSinRepeticion.find(elem, 0) == 18446744073709551615)
    {
      letrasAmbasPalabrasSinRepeticion.push_back(elem);
    }
  }

  for (int pos = 0; pos < palabra2.length(); pos++)
  {

    if (letrasAmbasPalabrasSinRepeticion.find(palabra2.at(pos), 0) == 18446744073709551615)
    { // Si no la encuentra
      letrasAmbasPalabrasSinRepeticion.push_back(palabra2.at(pos));
    }
  }

  return letrasAmbasPalabrasSinRepeticion;
}

string interseccionFuncion(string palabra1, string palabra2)
{
  string letrasCoincidentesSinRepeticion = "";

  for (int pos = 0; pos < palabra2.length(); pos++)
  {

    if (palabra1.find(palabra2.at(pos), 0) != 18446744073709551615)
    { // Si la encuentra

      if (letrasCoincidentesSinRepeticion.find(palabra2.at(pos), 0) == 18446744073709551615)
      { // Para evitar la repeticion de un mismo caracter
        letrasCoincidentesSinRepeticion.push_back(palabra2.at(pos));
      }
    }
  }

  return letrasCoincidentesSinRepeticion;
}

string diferenciaFuncion(string palabra1, string palabra2)
{
  string letrasPalabra1DiferentesSinRepeticion = palabra1;

  for (int pos = 0; pos < palabra2.length(); pos++)
  {

    if (letrasPalabra1DiferentesSinRepeticion.find(palabra2.at(pos), 0) != 18446744073709551615)
    { // Si la encuentra
      if (letrasPalabra1DiferentesSinRepeticion.find(palabra2.at(pos), 0) == 18446744073709551615)
      { // Para evitar la repeticion de un mismo caracter
        letrasPalabra1DiferentesSinRepeticion.erase(letrasPalabra1DiferentesSinRepeticion.find(palabra2.at(pos)), 1);
      }
    }
  }

  return letrasPalabra1DiferentesSinRepeticion;
}

int main()
{
  std::string palabra1 = "arboles";
  std::string palabra2 = "arboleda";
  cout << "FUNCION UNION: " << unionFuncion(palabra1, palabra2);
  cout << "\nFUNCION INTERSECION: " << interseccionFuncion(palabra1, palabra2);
  cout << "\nFUNCION DIFERENCIA: " << diferenciaFuncion(palabra1, palabra2);
}