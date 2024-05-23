#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>

using namespace std;

// Aquí la clase Pair está templatizada, es decir no sabemos a priori los tipos de key y de value
template <typename K, typename V>
class Pair
{

public:
    Pair(K v0, V v1);
    K key() const; // Funcion key() que devuelve la clave

    V value() const; // Funcion value() que devuelve el valor
    void print() const;

private:
    K _key;
    V _value;
};

// Definición de una clase templatizada. AQUI INICIALIZAS EL VALOR DE LAS VARIABLES _key y _value
template <typename K, typename V>
Pair<K, V>::Pair(K v0, V v1)
{
    _key = v0;
    _value = v1;
}

template <typename K, typename V>
K Pair<K, V>::key() const
{
    return _key;
}

template <typename K, typename V>
V Pair<K, V>::value() const
{
    return _value;
}

template <typename K, typename V>
void Pair<K, V>::print() const
{
    std::cout << _key << _value;
}

#endif
