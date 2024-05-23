#include "vector3.h"

Vector3::Vector3() : x{0}, y{0}, z{0} {}

Vector3::Vector3(float x, float y, float z) : x{x}, y{y}, z{z} {}

float Vector3::getX() const
{
    return x;
}

void Vector3::setX(float value)
{
    x = value;
}

float Vector3::getY() const
{
    return y;
}

void Vector3::setY(float value)
{
    y = value;
}

float Vector3::getZ() const
{
    return z;
}

void Vector3::setZ(float value)
{
    z = value;
}

Vector3 operator+(Vector3 const &v1, Vector3 const &v2)
{
    Vector3 result{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
    return result;
}

Vector3 operator-(Vector3 const &v1, Vector3 const &v2)
{
    Vector3 result{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
    return result;
}

float operator*(Vector3 const &v1, Vector3 const &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
