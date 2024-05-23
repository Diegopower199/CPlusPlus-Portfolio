#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    vector<vector<double>> notas = {{9.5, 4.1, 7.3}, {4.3, 5.5, 6.2}, {1.1, 1.1, 1.1}, {8.1, 10, 9.5}};

    // Apartado 1: MEDIA
    function<float(vector<double> const &)> media = [](vector<double> const &v)
    {
        float suma = 0;
        for (auto elem : v)
        {
            suma += elem;
        }

        cout << v.size() << "\n";

        return suma / v.size();
    };

    // Apartado 2: MÁXIMO
    function<float(vector<double> const &)> max = [](vector<double> const &v)
    {
        float max = -999999999999999;
        for (auto elem : v)
        {
            if (elem > max)
            {
                max = elem;
            }
        }
        return max;
    };

    // Apartado 3: MÍNIMO
    function<float(vector<double> const &)> min = [](vector<double> const &v)
    {
        float min = 999999999999999;
        for (auto elem : v)
        {
            if (elem < min)
            {
                min = elem;
            }
        }
        return min;
    };

    // APARTADO 4: COMPOSICION (MEDIA, MÁXIMO, MÍNIMO)
    function<float(function<double(vector<double>)>, vector<vector<double>>)> operaciones =
        [](function<double(vector<double>)> f1, vector<vector<double>> const &notas)
    {
        vector<double> g;
        for (auto v : notas)
        {
            g.push_back(f1(v));
        }
        return f1(g);
    };

    cout << "Media de las notas: " << operaciones(media, notas) << endl;
    cout << "Maximo de las notas del Alumn@ 4: " << operaciones(max, notas) << endl;
    cout << "Minimo de las notas del Alumn@ 3: " << operaciones(min, notas) << endl;
    cout << endl;

    // Apartado 5: COMPOSICIÓN (MÁX DE MÁX -> ejemplo)
    function<float(function<double(vector<double>)>, function<double(vector<double>)>, vector<vector<double>>)> op =
        [](function<double(vector<double>)> f1, function<double(vector<double>)> f2, vector<vector<double>> const &notas)
    {
        vector<double> g;
        for (auto v : notas)
        {
            g.push_back(f2(v));
        }
        return f1(g);
    };

    cout << "Maximo de maximo de notas: " << op(max, max, notas) << endl;
    cout << "Minimo de los maximos de notas: " << op(min, max, notas) << endl;
    cout << "Maximo de las medias de notas: " << op(max, media, notas) << endl;
    cout << "Minimo de las medias de notas: " << op(min, media, notas) << endl;
}
