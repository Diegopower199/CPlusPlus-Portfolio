#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{

    function<void(float)> mostrar = [](float x)
    {
        cout << x << ", ";
    };

    auto forEach = [](function<void(int)> g, vector<int> const &v)
    {
        for (auto elem : v)
        {
            g(elem);
        }
    };

    auto filter = [](function<bool(int)> g, vector<int> const &v)
    {
        vector<int> resultado;
        for (auto elem : v)
        {
            if (g(elem))
                resultado.push_back(elem);
        }
        return resultado;
    };

    auto transform = [](function<int(int)> g, vector<int> const &v)
    {
        vector<int> resultado;
        for (auto elem : v)
        {
            resultado.push_back(g(elem));
        }
        return resultado;
    };

    auto multiplicador = [](int x)
    {
        if (x % 2 == 0)
            return x * 3;
        else
            return x * 5;
    };

    auto multiplosde3 = [](int x)
    {
        return x % 3;
    };

    vector<int> vec{1, 2, 3, 4, 5};
    forEach(multiplicador, vec);

    auto transformada = transform(multiplicador, vec);
    auto filtrada = filter(multiplosde3, transformada);
    forEach(mostrar, filtrada);
}
