#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>

using namespace std;

class Vector3
{
    friend Vector3 operator+(Vector3 const &v1, Vector3 const &v2);
    friend Vector3 operator-(Vector3 const &v1, Vector3 const &v2);
    friend float operator*(Vector3 const &v1, Vector3 const &v2);

public:
    Vector3();
    Vector3(float x, float y, float z);

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

    float getZ() const;
    void setZ(float value);

private:
    float x, y, z;
};

#endif
