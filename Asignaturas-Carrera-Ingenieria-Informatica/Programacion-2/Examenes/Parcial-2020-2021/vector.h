#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Vector
{
    friend Vector operator+(Vector const &v1, Vector const &v2);
    friend Vector operator-(Vector const &v1, Vector const &v2);
    friend float operator*(Vector const &v1, Vector const &v2);
    friend bool operator==(Vector const &v1, Vector const &v2);
    friend ostream &operator<<(ostream &os, Vector const &v);
    friend istream &operator>>(istream &is, Vector &v);

public:
    Vector();
    Vector(float x, float y, float z);

    float getX() const;

    float getY() const;

    float getZ() const;

    float getModule(Vector const &a) const;

private:
    float x, y, z;
};

#endif
