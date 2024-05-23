#include <memory>
#include <iostream>
#include <array>
#include <vector>
#include <functional>

using namespace std;

vector<shared_ptr<int>> filter(array<shared_ptr<int>, 10> const &arr, function<bool(int)> f)
{
    vector<shared_ptr<int>> result;
    for (auto pelem : arr)
    {
        if (f(*pelem))
            result.push_back(make_shared<int>(*pelem));
    }

    return result;
}

int main()
{
    array<shared_ptr<int>, 10> arr1;
    for (int i = 0; i < 10; i++)
    {
        int valor;
        cout << "Introduce un num: ";
        cin >> valor;
        auto paux = make_shared<int>(valor);
        arr1.at(i) = paux;
    }

    for (auto pelem : arr1)
    {
        cout << *pelem << "\n";
    }

    auto espar = [](int a)
    {
        return a % 2 == 0;
    };

    auto vec = filter(arr1, espar);

    for (auto pelem : vec)
    {
        cout << *pelem << "\n";
    }
}
