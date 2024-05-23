#ifndef HOMBRE_H
#define HOMBRE_H

#include <iostream>

template <typename T, typename A>
class Hombre
{
public:
    Hombre(T const &b, A const &c);

    void setNombre(std::string);
    std::string getNombre() const;

    void setEdad(int);
    int getEdad() const;

private:
    T nombre;
    A edad;
};

#endif
