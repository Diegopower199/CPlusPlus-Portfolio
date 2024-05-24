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
    friend ostream &operator<<(ostream &os, Matriz const &a);
    friend istream &operator>>(istream &is, Matriz &a);

public:
    Matriz();
    Matriz(T &p);

    T getMatrix() const;
    void setMatrix(const T &value);

private:
    T array;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Matriz<T> const &a);

template <typename T>
Matriz<T>::Matriz(T &p)
{
    float idx = 0;
    for (float fila = 0; fila < 3; fila++)
    {
        for (float col = 0; col < 3; col++)
        {
            array.at(fila).at(col) = p.at(idx).at(col);
            idx++;
        }
    }
}

template <typename T>
void Matriz<T>::setMatrix(const T &value)
{
    array = value;
}

template <typename T>
T Matriz<T>::getMatrix() const
{
    return array;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Matriz<T> const &a)
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            os << a.array.at(fila).at(col) << ", ";
        }
        os << "\n";
    }
    return os;
}

#endif
