#include <array>
#include <cmath>

int main()
{
    std::array<double, 20> serie;

    serie.at(0) = 1;
    serie.at(1) = 1;
    serie.at(2) = 2;

    for (int i = 3; i < serie.size(); i++)
    {
        serie.at(i) = pow(-1, i) * serie.at(i - 1) + serie.at(i - 2) - 1 / serie.at(i - 3);
    }

    for (double elem : serie)
    {
        std::cout << elem << std::endl;
    }

    double acum{0};
    for (double elem : serie)
    {
        acum = acum + elem;
    }
    std::cout << "La suma acumulada es: " << acum << std::endl;

    std::cout << "La media es: " << acum / serie.size() << std::endl;

    return 0;
}