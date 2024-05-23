#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

template <typename T, typename K>
class Persona
{
public:
    Persona(T valor1, K valor2);

    void setName(const T &value);
    T getName() const;

    void setEdad(const K &value);
    K getEdad() const;

    T nombre() const;

    K age() const;

private:
    T name;
    K edad;
};

template <typename T, typename K>
T Persona<T, K>::nombre() const
{
    return name;
}

template <typename T, typename K>
K Persona<T, K>::age() const
{
    return edad;
}

template <typename T, typename K>
Persona<T, K>::Persona(T v0, K v1)
{
    name = v0;
    edad = v1;
}

template <typename T, typename K>
void Persona<T, K>::setName(const T &value)
{
    name = value;
}

template <typename T, typename K>
void Persona<T, K>::setEdad(const K &value)
{
    edad = value;
}

template <typename T, typename K>
T Persona<T, K>::getName() const
{
    return name;
}

template <typename T, typename K>
K Persona<T, K>::getEdad() const
{
    return edad;
}

#endif
