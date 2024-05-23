#include <iostream>
#include <functional>
#include <vector>

std::vector<float> capturarVectorIndividual()
{
    std::vector<float> vectorUsuario = {};
    int tamañoVector = 0;

    std::cout << "Introduce el tamaño del vector: ";
    std::cin >> tamañoVector;

    float elementoDeUsuario = 0;
    int posicion = 0;

    while (posicion < tamañoVector)
    {
        std::cout << "Introduce el elemento deseado: ";
        std::cin >> elementoDeUsuario;

        vectorUsuario.push_back(elementoDeUsuario);

        posicion++;
    }

    return vectorUsuario;
}

int elegirOpcion(std::string texto)
{
    std::cout << "1. max\n";
    std::cout << "2. min\n";
    std::cout << "3. mean\n";
    std::cout << "4. summatory\n";
    std::cout << "5. productory\n";
    std::cout << texto;

    int opcionUsuario = 0;

    std::cin >> opcionUsuario;

    return opcionUsuario;
}

int main()
{

    // Apartado 1
    std::function<float(std::vector<float> const &)> max = [](std::vector<float> const &v)
    {
        float max = -99999;

        for (auto elem : v)
        {
            if (max < elem)
            {
                max = elem;
            }
        }
        return max;
    };

    std::function<float(std::vector<float> const &)> min = [](std::vector<float> const &v)
    {
        float min = 99999;

        for (auto elem : v)
        {
            if (min > elem)
            {
                min = elem;
            }
        }
        return min;
    };

    std::function<float(std::vector<float> const &)> media = [](std::vector<float> const &v)
    {
        float suma = 0;

        for (auto elem : v)
        {
            suma = suma + elem;
        }
        return suma / v.size();
    };

    std::function<float(std::vector<float> const &)> sumatorio = [](std::vector<float> const &v)
    {
        float suma = 0;

        for (auto elem : v)
        {
            suma += elem;
        }
        return suma;
    };

    std::function<float(std::vector<float> const &)> producto = [](std::vector<float> const &v)
    {
        float producto = 1;

        for (auto elem : v)
        {
            producto = producto * elem;
        }
        return producto;
    };

    std::function<float(std::function<float(std::vector<float> const &)>, std::vector<std::vector<float>> const &)> operaciones = [](std::function<float(std::vector<float> const &)> f1, std::vector<std::vector<float>> const &vv)
    {
        std::vector<float> g;

        for (auto v : vv)
        {
            g.push_back(f1(v));
        }
        return f1(g);
    };

    std::cout << operaciones(max, {{1, 5}, {3, 7}}) << "\n";
    std::cout << operaciones(min, {{1, 5}, {3, 7}}) << "\n";
    std::cout << operaciones(media, {{1, 5}, {3, 7}}) << "\n";
    std::cout << operaciones(sumatorio, {{1, 5}, {3, 7}}) << "\n";
    std::cout << operaciones(producto, {{1, 5}, {3, 7}}) << "\n";

    // Apartado 2
    std::cout << "\n"
              << "\n";

    std::function<float(std::function<float(std::vector<float> const &)>, std::function<float(std::vector<float> const &)>, std::vector<std::vector<float>> const &)> comp = [](std::function<float(std::vector<float> const &)> f1, std::function<float(std::vector<float> const &)> f2, std::vector<std::vector<float>> const &vv)
    {
        std::vector<float> g;

        for (auto v : vv)
        {
            g.push_back(f2(v));
        }
        return f1(g);
    };

    std::cout << comp(max, max, {{1, 2, 3}, {3, 5}, {1, 1, 1, 1}}) << "\n";
    std::cout << comp(min, max, {{1, 2, 3}, {3, 5}, {1, 1, 1, 1}}) << "\n";
    std::cout << comp(sumatorio, media, {{1, 2, 3}, {3, 5}, {1, 1, 1, 1}}) << "\n";
    std::cout << comp(media, sumatorio, {{1, 2, 3}, {3, 5}, {1, 1, 1, 1}}) << "\n";

    // Apartado 3
    std::cout << "\n"
              << "\n";

    int vectoresTotales = 0;
    std::cout << "Introduce cuantos vectores quieres: ";
    std::cin >> vectoresTotales;

    std::vector<std::vector<float>> vectoresUsuario = {};

    int vectorActual = 1;

    while (vectorActual <= vectoresTotales)
    {

        vectoresUsuario.push_back(capturarVectorIndividual());

        vectorActual++;
    }

    int primeraOperacion = elegirOpcion("Cuál es la primera operación que quiere realizar: ");

    int segundaOperacion = elegirOpcion("Cuál es la segunda operación que quiere realizar: ");

    std::function<float(std::vector<float> const &)> operacion1;

    std::function<float(std::vector<float> const &)> operacion2;

    if (primeraOperacion == 1)
    {
        operacion1 = max;
    }
    else if (primeraOperacion == 2)
    {
        operacion1 = min;
    }
    else if (primeraOperacion == 3)
    {
        operacion1 = media;
    }
    else if (primeraOperacion == 4)
    {
        operacion1 = sumatorio;
    }
    else if (primeraOperacion == 5)
    {
        operacion1 = producto;
    }

    if (segundaOperacion == 1)
    {
        operacion2 = max;
    }
    else if (segundaOperacion == 2)
    {
        operacion2 = min;
    }
    else if (segundaOperacion == 3)
    {
        operacion2 = media;
    }
    else if (segundaOperacion == 4)
    {
        operacion2 = sumatorio;
    }
    else if (segundaOperacion == 5)
    {
        operacion2 = producto;
    }

    std::cout << "El resultado es: " << comp(operacion1, operacion2, vectoresUsuario) << "\n";
}