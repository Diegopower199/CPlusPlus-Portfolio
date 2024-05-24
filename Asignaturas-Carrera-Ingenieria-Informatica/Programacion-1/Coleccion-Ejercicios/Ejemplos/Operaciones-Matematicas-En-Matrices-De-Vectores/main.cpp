#include <iostream>
#include <vector>
#include <functional>
#include <math.h>

using namespace std;

int main()
{
    function<float(vector<float>)> media = [](vector<float> const &v)
    {
        float suma = 0;
        for (auto elem : v)
        {
            suma += elem;
        }
        return suma / v.size();
    };

    function<float(vector<float>)> max = [](vector<float> const &v)
    {
        float max = -9999999;
        for (auto elem : v)
        {
            if (max < elem)
                max = elem;
        }
        return max;
    };

    function<float(function<float(vector<float> const &)>, vector<vector<float>> const &)> suma = [](function<float(vector<float>)> const &f, vector<vector<float>> const &vv)
    {
        float lasuma = 0;
        for (auto vec : vv)
        {
            lasuma += f(vec);
        }
        return lasuma;
    };

    cout << "La suma de las medias es: " << suma(media, {{2, 4}, {1, 5}}) << endl;
    cout << "La suma de los maximos es: " << suma(max, {{2, 4}, {1, 5}}) << endl;

    function<float(vector<float> const &)> suma_ = [](vector<float> const &v)
    {
        float suma = 0;
        for (auto elem : v)
        {
            suma += elem;
        }
        return suma;
    };

    function<float(function<float(vector<float> const &)>, function<float(std::vector<float> const &)>, vector<vector<float>> const &)> op =
        [](function<float(vector<float> const &)> f1, function<float(std::vector<float> const &)> f2, vector<vector<float>> const &vv)
    {
        vector<float> g;
        for (auto v : vv)
        {
            g.push_back(f2(v));
        }
        return f1(g);
    };

    function<float(vector<float> const &)> resta = [](vector<float> const &v)
    {
        float resta = v.at(0);
        for (int i = 0; i < v.size(); i++)
        {
            resta -= v.at(i);
        }
        return resta;
    };

    function<float(vector<float> const &)> modulo = [](vector<float> const &v)
    {
        float suma = 0;
        for (auto elem : v)
        {
            suma += elem * elem;
        }
        return sqrt(suma);
    };

    cout << "La suma de las medias es: " << op(suma_, media, {{1, 5}, {3, 7}}) << endl;
    cout << "El maximo de los maximos es: " << op(max, max, {{1, 5}, {3, 7}}) << endl;
    cout << "El maximo de la suma es: " << op(max, suma_, {{1, 5}, {3, 7}}) << endl;
    cout << "La media del modulo es: " << op(media, modulo, {{1, 5}, {3, 7}}) << endl;

    return 0;
}
