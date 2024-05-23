#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>
#include <functional>

using namespace std;

// Las funciones tempoplatizadas se deben declarar y definir SIEMPRE en archivos .h
struct Persona
{
  string nombre;
  int edad;
};

template <typename T>
void print(T const &a)
{
  cout << a << "\n";
}

// Particularización de un template
template <>
void print(Persona const &a)
{
  cout << "nombre: " << a.nombre << "\n";
  cout << "edad: " << a.edad << "\n";
}

// Múltiples tipos templatizados
template <class T, class Y>
void print(T const &a, Y const &b)
{
  std::cout << a << "\n";
  std::cout << b << "\n";
}

// forEach
template <class T, class Y>
void forEach(T const &v, function<void(Y)> const &op)
{
  for (auto elem : v)
  {
    op(elem);
  }
}

// filter
template <class T, class Y>
T filter(T const &v, function<bool(Y)> const &f)
{
  T result;
  for (auto elem : v)
  {
    if (f(elem))
      result.push_back(elem);
  }

  return result;
}

// map
template <class T, class Y>
T map(T const &v, function<Y(Y)> const &f)
{
  T result;
  for (auto elem : v)
  {
    result.push_back(f(elem));
  }

  return result;
}

// find
template <class T, class Y>
Y find(T const &v, function<bool(Y)> const &f)
{

  for (auto elem : v)
  {
    if (f(elem))
      return elem;
  }

  return Y{};
}
#endif
