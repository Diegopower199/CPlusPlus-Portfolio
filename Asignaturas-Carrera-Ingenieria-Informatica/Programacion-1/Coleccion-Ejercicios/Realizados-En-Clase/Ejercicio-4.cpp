#include <iostream>
#include <string>

int main()
{
  std::cout << "Introduzca un texto: ";
  std::string textoUsuario = "";
  std::string palabra = "password";
  std::getline(std::cin, textoUsuario);
  int encontrarPalabra = textoUsuario.find(palabra);

  if (encontrarPalabra == -1)
  {
  }
  else
  {
    int medirPalabra = palabra.size();
    int posInicial = textoUsuario.find(" ", encontrarPalabra + medirPalabra);
    int posFinal = textoUsuario.find(" ", posInicial + 1);
    std::string palabraNueva = textoUsuario.substr(posInicial, posFinal - posInicial);
    std::cout << palabraNueva;
  }
}

// TAMBIEN SE PUEDE HACER DE ESTA MANERA
/*#include <iostream>

int main()
{
  std::cout << "Introduce un texto \n";
  std::string textoUsuario = "";
  std::string palabra = "password";
  std::getline(std::cin, textoUsuario);
  int encontrarPalabra = textoUsuario.find("password");
  int medirPalabra = palabra.size();

  if (encontrarPalabra == -1)
  {
    std::cout << "No hemos encontrado nada";
  }
  else
  {
    int posicionInicial = encontrarPalabra + medirPalabra + 1; // Empieza en la palabra que queremos mostrar
    int posicionFinal = textoUsuario.find(" ", posicionInicial);
    std::string palabraNueva = textoUsuario.substr(posicionInicial, posicionFinal - posicionInicial);
    std::cout << "La palabra despues de password es " << palabraNueva;
  }
}*/