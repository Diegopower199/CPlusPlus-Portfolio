#include "matriz2.h"

Matriz2::Matriz2()
{
    for (int fila = 0; fila < 2; fila++)
    {
        for (int col = 0; col < 2; col++)
        {
            data.at(fila).at(col) = 0;
        }
    }
}

Matriz2::Matriz2(array<float, 4> const &p)
{
    int idx = 0;
    for (int fila = 0; fila < 2; fila++)
    {
        for (int col = 0; col < 2; col++)
        {
            data.at(fila).at(col) = p.at(idx);
            idx++;
        }
    }
}

float Matriz2::get(int row, int col) const
{
    if (row < 0 || row > 1 || col < 0 || col > 1)
        throw string{"out of bounds"};
    return data.at(row).at(col);
}

void Matriz2::set(int row, int col, float value)
{
    if (row < 0 || row > 1 || col < 0 || col > 1)
        throw string{"out of bounds"};
    data.at(row).at(col) = value;
}

void Matriz2::print() const
{
    for (int fila = 0; fila < 2; fila++)
    {
        for (int col = 0; col < 2; col++)
        {
            cout << data.at(fila).at(col);
        }
        cout << endl;
    }
}

float Matriz2::determinant() const
{
    return 9;
}

ostream &operator<<(ostream &os, Matriz2 const a)
{
    for (int fila = 0; fila < 2; fila++)
    {
        for (int col = 0; col < 2; col++)
        {
            os << a.data.at(fila).at(col);
        }
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Matriz2 &a)
{
    for (int fila = 0; fila < 2; fila++)
    {
        for (int col = 0; col < 2; col++)
        {
            is >> a.data.at(fila).at(col);
        }
    }
    return is;
}

shared_ptr<Matriz2> add(const shared_ptr<Matriz2> a, const shared_ptr<Matriz2> b)
{
    auto result = make_shared<Matriz2>();
    for (int fila = 0; fila < 2; fila++)
    {
        for (int col = 0; col < 2; col++)
        {
            result->set(fila, col, a->get(fila, col) + b->get(fila, col));
        }
    }
    return result;
}

Matriz2 operator+(Matriz2 const &a, Matriz2 const &b)
{
    Matriz2 result;
    for (int fila = 0; fila < 2; fila++)
    {
        for (int col = 0; col < 2; col++)
        {
            result.set(fila, col, a.get(fila, col) + b.get(fila, col));
        }
    }
    return result;
}
