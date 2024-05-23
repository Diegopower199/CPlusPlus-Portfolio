#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <array>
#include <ostream>
#include <istream>

using namespace std;

template <typename T>
class Matriz
{
    template <typename TN>
    friend ostream &operator<<(ostream &os, Matriz<TN> const &a);

    template <typename TN>
    friend istream &operator>>(istream &is, Matriz<TN> &a);

public:
    Matriz();
    Matriz(T &p);

    T getMatrix() const;
    void setMatrix(const T &value);

private:
    // T array;
    array<array<float, 3>, 3> arrayMatriz;
};

template <typename T>
Matriz<T>::Matriz(T &p)
{
    arrayMatriz = p;
}

template <typename T>
void Matriz<T>::setMatrix(const T &value)
{
    arrayMatriz = value;
}

template <typename T>
T Matriz<T>::getMatrix() const
{
    return arrayMatriz;
}

template <typename TN>
std::ostream &operator<<(std::ostream &os, Matriz<TN> const &a)
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            os << a.arrayMatriz.at(fila).at(col) << ", ";
        }
        os << "\n";
    }
    return os;
}

#endif
