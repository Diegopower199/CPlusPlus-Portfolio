#ifndef MATRIZ2_H
#define MATRIZ2_H

#include <iostream>
#include <array>
#include <memory>

using namespace std;

class Matriz2
{
    friend ostream &operator<<(ostream &os, Matriz2 const a);
    friend istream &operator>>(istream &is, Matriz2 &a);

public:
    Matriz2();
    Matriz2(array<float, 4> const &p);

    float get(int row, int col) const;
    void set(int row, int col, float value);
    void print() const;
    float determinant() const;

private:
    array<array<float, 2>, 2> data;
};

ostream &operator<<(ostream &os, Matriz2 const a);
istream &operator>>(istream &is, Matriz2 &a);
shared_ptr<Matriz2> add(const shared_ptr<Matriz2> a, const shared_ptr<Matriz2> b);

#endif
