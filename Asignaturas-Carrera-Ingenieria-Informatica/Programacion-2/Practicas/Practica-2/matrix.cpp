#include "matrix.h"

Matrix::Matrix()
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            data.at(fila).at(col) = 0;
        }
    }
}

Matrix::Matrix(array<float, 9> const &p)
{
    int idx = 0;
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            data.at(fila).at(col) = p.at(idx);
            idx++;
        }
    }
}

float Matrix::get(int row, int col) const
{
    if (row < 0 || row > 2 || col < 0 || col > 2)
        throw string{"out of bounds"};
    return data.at(row).at(col);
}

void Matrix::set(int row, int col, float value)
{
    if (row < 0 || row > 2 || col < 0 || col > 2)
        throw string{"out of bounds"};
    data.at(row).at(col) = value;
}

void Matrix::print() const
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << data.at(fila).at(col);
        }
        cout << endl;
    }
}

float Matrix::determinant() const
{
    return 9;
}

ostream &operator<<(ostream &os, Matrix const a)
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            os << a.data.at(fila).at(col);
        }
        os << endl;
    }
    return os;
}

shared_ptr<Matrix> add(const shared_ptr<Matrix> a, const shared_ptr<Matrix> b)
{
    auto result = make_shared<Matrix>();
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            result->set(fila, col, a->get(fila, col) + b->get(fila, col));
        }
    }
    return result;
}

Matrix operator+(Matrix const &a, Matrix const &b)
{
    Matrix result;
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            result.set(fila, col, a.get(fila, col) + b.get(fila, col));
        }
    }
    return result;
}

istream &operator>>(istream &is, Matrix &a)
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            is >> a.data.at(fila).at(col);
        }
    }
    return is;
}
