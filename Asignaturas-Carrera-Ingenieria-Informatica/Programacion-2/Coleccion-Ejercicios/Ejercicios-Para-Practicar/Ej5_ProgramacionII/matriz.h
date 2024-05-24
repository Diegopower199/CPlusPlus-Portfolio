#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
#include <ostream>
#include <iostream>

class Matriz
{
    friend Matriz operator*(Matriz &a, Matriz &b);
    friend Matriz operator+(Matriz &a, Matriz &b);
    friend Matriz operator-(Matriz &a, Matriz &b);
    friend std::ostream &operator<<(std::ostream &os, Matriz &a);
    friend std::istream &operator>>(std::istream &is, Matriz &a);

public:
    Matriz();
    Matriz(int cols, int filas);

    unsigned int getCols() const;
    unsigned int getFilas() const;
    float &at(unsigned i, unsigned j);

private:
    unsigned int cols, filas;
    std::vector<float> data;
};

#endif
