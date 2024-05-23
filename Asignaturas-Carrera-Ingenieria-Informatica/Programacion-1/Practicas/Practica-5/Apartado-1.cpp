#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <stdio.h>

using namespace std;

auto apartado1 = [](vector<int> const &v)
{
  vector<int> resultado;
  for (auto elem : v)
  {
    if (elem % 2 == 0)
    {
      resultado.push_back(elem);
    }
  }
  return resultado;
  100 f
};

auto apartado2 = [](vector<int> const &v)
{
  vector<int> resultado;
  for (auto elem : v)
  {
    if (elem % 2 == 0)
    {
      if (elem % 3 == 0)
      {
        if (elem < 20)
        {
          resultado.push_back(elem);
        }
      }
    }
  }
  return resultado;
};

auto forEach = [](vector<int> const &v1, function<void(int)> v2)
{
  for (auto elem : v1)
    v2(elem);
};

int main()
{
  srand(time(NULL));
  vector<int> aleatorios;
  for (int i = 0; i <= 100; i++)
  {
    int numero = rand() % 100;
    aleatorios.push_back(numero);
  }

  cout << "El vector de numeros aleatorios es: " << "\n";
  for (auto elem : aleatorios)
  {
    cout << elem << "\n";
  }
  cout << "El vector de numeros pares es: " << "\n";
  vector<int> pares = apartado1(aleatorios);
  for (auto elem : pares)
  {
    cout << elem << "\n";
  }

  cout << "El vector de numero pares, multiplos de 3 y menores de 20 es: " << "\n";
  vector<int> indice2 = apartado2(aleatorios);
  for (auto elem : indice2)
  {
    cout << elem << "\n";
  }
}

// Otra forma con filter
/*#include <iostream>
#include <time.h>
#include <vector>
#include <functional>
    using namespace std;

vector<int> filter(vector<int> const &v1, function<bool(int)> const &op)
{
  vector<int> resultado;
  for (auto elem : v1)
  {
    if (op(elem))
      resultado.push_back(elem);
  }
  return resultado;
}

int main()
{
  srand(time(NULL));
  vector<int> mivector;
  for (int i = 0; i < 100; i++)
  {
    int aleatorio = rand() % 100 + 1;
    mivector.push_back(aleatorio);
  }

  cout << "El vector de numero aleatorios es: " << endl;
  for (auto elem : mivector)
  {
    cout << elem << "-";
  }

  cout << endl;
  auto apartado1 = [](int x)
  {
    return (x % 2 == 0);
  };
  vector<int> v2 = filter(mivector, apartado1);
  cout << "EL segundo vector es: " << endl;
  for (auto elem : v2)
  {
    cout << elem << "-";
  }

  cout << endl;

  auto apartado2 = [](int x)
  {
    return (x % 2 == 0 && x % 3 == 0 && x < 20);
  };

  vector<int> v3 = filter(mivector, apartado2);
  cout << "EL tercer vector es: " << endl;
  for (auto elem : v3)
  {
    cout << elem << "-";
  }

  cout << endl;
}
*/