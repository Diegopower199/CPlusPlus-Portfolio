#include <iostream>
#include <memory>
#include <array>
#include <functional>
#include <vector>

using namespace std;

void print(array<shared_ptr<int>, 10> arr1)
{
    cout << "\nElementos del array: \n";
    for (auto pelem : arr1)
    {
        cout << *pelem << ", ";
    }
    cout << "\n";
}

vector<shared_ptr<int>> filter(array<shared_ptr<int>, 10> const &arr, function<bool(int)> f)
{
    vector<shared_ptr<int>> result;
    for (auto pelem : arr)
    {
        if (f(*pelem))
            result.push_back(pelem);
    }
    return result;
}
int main()
{
    // Apartado 1
    array<shared_ptr<int>, 10> arr1;

    // Apartado 2
    for (int i = 0; i < 10; i++)
    {
        int valor;
        cout << "Introduce un numero: ";
        cin >> valor;
        auto aux = make_shared<int>(valor);
        arr1.at(i) = aux;
    }

    // Apartado 3
    print(arr1);

    // Apartado 4
    auto espar = [](int a)
    {
        return a % 2 == 0;
    };

    auto vec = filter(arr1, espar);

    // Apartado 5
    cout << "\nElementos pares del vector: \n";
    for (auto pelem : vec)
    {
        cout << *pelem << ", ";
    }
    cout << "\n";
}
