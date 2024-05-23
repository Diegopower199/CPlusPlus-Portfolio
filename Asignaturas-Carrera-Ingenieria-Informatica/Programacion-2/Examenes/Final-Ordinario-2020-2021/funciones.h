#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "agenda.h"
#include "contacto.h"

#include <vector>
#include <memory>
#include <functional>

template <typename T>
class Listado
{
public:
    Listado();
    void insertar(std::shared_ptr<Agenda<T>> a);
    void eliminar(std::string const &clave);
    std::shared_ptr<Agenda<T>> find(const std::function<bool(std::shared_ptr<Agenda<T>>)> &op) const;
    std::vector<std::shared_ptr<Agenda<T>>> getDatos() const;
    std::vector<std::shared_ptr<Agenda<T>>> filter(std::vector<std::shared_ptr<Agenda<T>>> p, std::function<bool(std::shared_ptr<Agenda<T>>)> op);

private:
    std::vector<std::shared_ptr<Agenda<T>>> datos;
};

template <typename T>
Listado<T>::Listado() {}

template <typename T>
void Listado<T>::insertar(std::shared_ptr<Agenda<T>> a)
{
    for (auto const &n : datos)
    {
        if (n->getClave() == a->getClave())
            throw std::string{"Ya existe una persona"};
    }
    datos.push_back(a);
}

template <typename T>
void Listado<T>::eliminar(const std::string &clave)
{
    for (unsigned int long i{0}; i < datos.size(); i++)
    {
        if (datos.at(i)->getClave() == clave)
        {
            datos.erase(datos.begin() + i);
            return;
        }
    }

    throw std::string{"No existe la persona que quieres borrar"};
}

template <typename T>
std::shared_ptr<Agenda<T>> Listado<T>::find(std::function<bool(std::shared_ptr<Agenda<T>>)> const &op) const
{
    for (auto n : datos)
    {
        if (op(n))
            return n;
    }
    return nullptr;
}

template <typename T>
std::vector<std::shared_ptr<Agenda<T>>> Listado<T>::getDatos() const
{
    return datos;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Listado<T> const &l)
{
    for (auto n : l.getDatos())
    {
        os << *n << "\n";
    }
    os << "\n";
    return os;
}

template <typename T>
Listado<T> operator+(Listado<T> const &s, Listado<T> const &l)
{
    Listado<T> result = s;
    for (auto n : l.getDatos())
    {
        result.insertar(n);
    }
    return result;
}

#endif
