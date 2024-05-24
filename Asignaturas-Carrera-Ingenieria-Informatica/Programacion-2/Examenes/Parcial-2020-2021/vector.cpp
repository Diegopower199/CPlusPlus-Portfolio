#include "vector.h"

Vector::Vector() : x{0}, y{0}, z{0}
{
}

Vector::Vector(float x, float y, float z) : x{x}, y{y}, z{z}
{
}

float Vector::getX() const
{
    return x;
}

float Vector::getY() const
{
    return y;
}

float Vector::getZ() const
{
    return z;
}

float Vector::getModule(const Vector &a) const
{
    return sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()) + (a.getZ() * a.getZ()));
}

Vector operator+(Vector const &v1, Vector const &v2)
{
    Vector result{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
    return result;
}

Vector operator-(Vector const &v1, Vector const &v2)
{
    Vector result{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
    return result;
}

float operator*(Vector const &v1, Vector const &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

ostream &operator<<(ostream &os, Vector const &v)
{
    os << "[" << v.x << "," << v.y << "," << v.z << "]" << endl;
    return os;
}

bool operator==(Vector const &v1, Vector const &v2)
{
    return ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z));
}

istream &operator>>(istream &is, Vector &v)
{
    is >> v.x;
    is >> v.y;
    is >> v.z;
    return is;
}
