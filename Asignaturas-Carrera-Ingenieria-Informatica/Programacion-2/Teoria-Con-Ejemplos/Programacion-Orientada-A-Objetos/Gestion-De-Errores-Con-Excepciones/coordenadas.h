#ifndef COORDENADAS_H
#define COORDENADAS_H

#include <iostream>
#include <vector>

using namespace std;

class Coordenadas
{
public:
    Coordenadas(float x, float y, float z):x{x}, y{y}, z{z}{
        if(x < 0 || y < 0 || z < 0) throw string{"Error"};
    }
    float getX() const;

    float getY() const;

    float getZ() const;

private:
    float x,y,z;
};

#endif
