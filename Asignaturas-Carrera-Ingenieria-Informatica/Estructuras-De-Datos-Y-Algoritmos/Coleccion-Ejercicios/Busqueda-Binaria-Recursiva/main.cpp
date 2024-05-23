#include <iostream>
#include <vector>

std::vector<int> slice(const std::vector<int> &values, int begin, int end)
{
    if (begin >= end)
    {
        return std::vector<int>{};
    }
    return std::vector<int>(values.begin() + begin, values.begin() + end);
}

bool binary_search(const std::vector<int> &values, int value_to_find)
{
    if (values.empty())
    {
        return false;
    }
    int middle = values.size() / 2;
    if (value_to_find < values.at(middle))
    {
        auto new_vector = slice(values, 0, middle);
        return binary_search(new_vector, value_to_find);
    }
    else if (value_to_find > values.at(middle))
    {
        auto new_vector = slice(values, middle + 1, values.size());
        return binary_search(new_vector, value_to_find);
    }
    else
    {
        return true;
    }
}

int BusquedaBinariaRecursiva(const std::vector<int> &v, int valorAbuscar, int primero, int ultimo)
{
    if (primero > ultimo)
    {
        return -1;
    }

    int medio = (primero + ultimo) / 2;

    if (valorAbuscar < v.at(medio))
    {
        return BusquedaBinariaRecursiva(v, valorAbuscar, primero, medio - 1);
    }
    else if (valorAbuscar > v.at(medio))
    {
        return BusquedaBinariaRecursiva(v, valorAbuscar, medio + 1, ultimo);
    }
    else
    {
        return medio;
    }
}

int main()
{
    std::vector<int> values{1, 3, 5, 8, 13};

    // Usando la función boolean binary_search
    bool found = binary_search(values, 8);
    if (found)
    {
        std::cout << "Element found using binary_search" << std::endl;
    }
    else
    {
        std::cout << "Element not found using binary_search" << std::endl;
    }

    // Usando la función de búsqueda binaria recursiva que devuelve índice
    int index = BusquedaBinariaRecursiva(values, 8, 0, values.size() - 1);
    if (index != -1)
    {
        std::cout << "Element found at index " << index << " using BusquedaBinariaRecursiva" << std::endl;
    }
    else
    {
        std::cout << "Element not found using BusquedaBinariaRecursiva" << std::endl;
    }

    return 0;
}
