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

    auto mostrarPares = [](int x)
    {
        if (x % 2 == 0)
            cout << x << ", ";
    };

    auto mostrarTriple = [](int x)
    {
        cout << 3 * x << ", ";
    };

    auto g_forEach = [](function<void(int)> f, vector<int> const &v)
    {
        for (auto elem : v)
        {
            if (elem % 2 == 0)
                f(elem);
        }
    };

    auto doble = [](int x)
    {
        return 2 * x;
    };

    auto triple = [](int x)
    {
        return 3 * x;
    };

    auto restos = [](int x)
    {
        return x % 2;
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

    auto mayor3 = [](int x)
    {
        return x >= 3;
    };

    vector<int> vec{1, 2, 3, 4, 5, 6};
    g_forEach(mostrar, vec);
    forEach(mostrarPares, vec);
    forEach(mostrarTriple, vec);

    vector<int> eldoble = transform(doble, vec);

    auto resultado = transform(restos, vec);
    forEach(mostrar, resultado);

    auto filtrados = filter(mayor3, resultado);
    forEach(mostrar, filtrados);
}
