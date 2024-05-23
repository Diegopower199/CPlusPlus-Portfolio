
#include "matriz.h"

#include "matriz2.h"

Matriz2::Matriz2()
{
    for (int fila = 0; fila < 2; fila++)
    {
        for (int col = 0; col < 2; col++)
        {
            matrix.at(fila).at(col) = 0;
        }
    }
}

Matriz2::Matriz2(array<float, 9> const &p)
{
    int idx = 0;
    for (int fila = 0; fila < 2; fila++)
    {
        for (int col = 0; col < 2; col++)
        {
            matrix.at(fila).at(col) = p.at(idx);
            idx++;
        }
    }
}

array<array<float, 3>, 3> Matriz2::getMatrix() const
{
    return matrix;
}

void Matriz2::setMatrix(const array<array<float, 3>, 3> &value)
{
    matrix = value;
}

ostream &operator<<(ostream &os, Matriz2 const a)
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            os << a.matrix.at(fila).at(col);
        }
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Matriz2 &a)
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            is >> a.matrix.at(fila).at(col);
        }
    }
    return is;
}
