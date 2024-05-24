#include "matriz.h"

Matriz::Matriz() : cols{0}, filas{0} {}

Matriz::Matriz(int cols, int filas)
{
    if (cols <= 0 || filas <= 0)
    {
        throw std::string{"Dimensiones incorrectas"};
    };
    cols = unsigned(cols);
    filas = unsigned(filas);
    data.resize(cols * filas, 0);
}

unsigned int Matriz::getCols() const
{
    return cols;
}

unsigned int Matriz::getFilas() const
{
    return filas;
}

float &Matriz::at(unsigned i, unsigned j)
{
    if (i >= filas || j >= cols)
    {
        throw std::string{"Fuera de los limites de la matriz"};
    }
    else
    {
        unsigned elem = i * cols + j;
        return data.at(elem);
    }
}

std::ostream &operator<<(std::ostream &os, Matriz &a)
{
    for (unsigned i{0}; i < a.getFilas(); i++)
    {
        for (unsigned j{0}; j < a.getCols(); j++)
        {
            os << a.at(i, j) << "\t";
        }
        os << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Matriz &a)
{
    for (unsigned i{0}; i < a.getFilas(); i++)
    {
        for (unsigned j{0}; j < a.getCols(); j++)
        {
            is >> a.at(i, j);
        }
    }
    return is;
}

Matriz operator*(Matriz &a, Matriz &b)
{
    if (a.getCols() != b.getCols())
    {
        throw std::string{"Fuera de dimensiones"};
    };
    Matriz result(int(a.getFilas()), int(b.getCols()));

    for (unsigned i{0}; i < result.getFilas(); i++)
    {
        for (unsigned j{0}; j < result.getCols(); j++)
        {
            float aux{0};
            for (unsigned k{0}; k < a.getCols(); k++)
            {
                aux += a.at(i, k) * b.at(k, j);
            }
            result.at(i, j) = aux;
        }
    }
    return result;
}

Matriz operator+(Matriz &a, Matriz &b)
{
    if (a.getCols() != b.getCols() || a.getFilas() != b.getFilas())
    {
        throw std::string{"Fuera de dimensiones"};
    }
    Matriz result(int(a.getFilas()), int(a.getCols()));

    for (unsigned i{0}; i < a.getFilas(); i++)
    {
        for (unsigned j{0}; j < a.getCols(); j++)
        {
            result.at(i, j) = a.at(i, j) + b.at(i, j);
        }
    }
    return result;
}

Matriz operator-(Matriz &a, Matriz &b)
{
    if (a.getCols() != b.getCols() || a.getFilas() != b.getFilas())
    {
        throw std::string{"Fuera de dimensiones"};
    }
    Matriz result(int(a.getFilas()), int(a.getCols()));

    for (unsigned i{0}; i < a.getFilas(); i++)
    {
        for (unsigned j{0}; j < a.getCols(); j++)
        {
            result.at(i, j) = a.at(i, j) - b.at(i, j);
        }
    }
    return result;
}
