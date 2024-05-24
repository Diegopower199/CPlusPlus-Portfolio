#include <iostream>
#include <vector>

using namespace std;

bool esPrimo(int num)
{
    for (int i = 2; i <= num / 2 + 1; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> factores(int num)
{
    vector<int> resultado;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0 && esPrimo(i))
            resultado.push_back(i);
    }
    resultado.push_back(num);
    return resultado;
}

void printVector(vector<int> v)
{
    for (auto elem : v)
    {
        cout << elem << ", ";
    }
}

int main()
{
    cout << "Introduce un numero: ";
    int x;
    cin >> x;
    vector<int> fact = factores(x);
    printVector(fact);
    return 0;
}
