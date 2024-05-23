#include <iostream>
#include <vector>
using namespace std;

int rangoDatos(std::vector<std::vector<int>> datos)
{
  int valorMinimo = datos.at(0).at(1);
  int valorMaximo = 0;

  for (int x = 1; x < datos.size(); x++)
  {
    if (valorMinimo > datos.at(x).at(1))
    {
      valorMinimo = datos.at(x).at(1);
    }

    if (valorMaximo < datos.at(x).at(1))
    {
      valorMaximo = datos.at(x).at(1);
    }
  }

  return (valorMaximo - valorMinimo);
}

std::vector<int> modaDatos(std::vector<std::vector<int>> datos)
{
  std::vector<int> moda = {};
  int valorMasRepetido = datos.at(0).at(1);

  cout << datos.size() << "\n";
  for (int x = 1; x < datos.size(); x++)
  {

    cout << " " << datos.at(x).at(0) << "   " << valorMasRepetido << "\n";

    if (valorMasRepetido == datos.at(x).at(1))
    {
      moda.push_back(datos.at(x).at(0));
    }
    else if (valorMasRepetido < datos.at(x).at(1))
    {
      valorMasRepetido = datos.at(x).at(1);
      moda.clear();
      moda.push_back(datos.at(x).at(0));
    }
  }

  return moda;
}

double medianaDatos(std::vector<std::vector<int>> datos)
{
  std::vector<int> medianaOrdenada = {};
  double resultadoMediana = 0;
  for (int x = 1; x < datos.size(); x++)
  {
    medianaOrdenada.push_back(datos.at(x).at(1));
  }

  int aux = 0;

  for (int x = 0; x < medianaOrdenada.size(); x++)
  {
    for (int j = x + 1; j < medianaOrdenada.size(); j++)
    {
      if (medianaOrdenada[x] > medianaOrdenada[j])
      {
        aux = medianaOrdenada[x];
        medianaOrdenada[x] = medianaOrdenada[j];
        medianaOrdenada[j] = aux;
      }
    }
  }

  // Si el tamaño es par hace falta hacer lo siguiente n/2 y (n/2)+1 y todo esto entre 2
  // Si el tamaño es impa hace falta hacer los siguiente (n + 1 / 2)

  if (medianaOrdenada.size() % 2 == 0)
  {
    resultadoMediana = (medianaOrdenada.at((medianaOrdenada.size() / 2) - 1) + medianaOrdenada.at(((medianaOrdenada.size() / 2) + 1) - 1));
    resultadoMediana = resultadoMediana / 2;
  }
  else
  {
    resultadoMediana = medianaOrdenada.at(((medianaOrdenada.size() + 1) / 2) - 1);
  }

  for (auto elem : medianaOrdenada)
  {
    cout << elem << ", ";
  }

  return resultadoMediana;
}

int main()
{
  std::vector<std::vector<int>> contenedorDatos = {{1, 3}, {2, 5}, {3, 2}, {4, 3}, {5, 5}, {6, 4}, {7, 4}};
  cout << rangoDatos(contenedorDatos);

  std::vector<int> modaTotal = modaDatos(contenedorDatos);

  cout << "\n[";
  for (auto elem : modaTotal)
  {
    cout << elem << ", ";
  }
  cout << "]\n";

  cout << "\nResultado mediana: " << medianaDatos(contenedorDatos);
}