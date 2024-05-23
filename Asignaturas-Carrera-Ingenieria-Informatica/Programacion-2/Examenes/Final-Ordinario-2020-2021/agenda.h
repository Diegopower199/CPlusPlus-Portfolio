#ifndef AGENDA_H
#define AGENDA_H

#include <string>

template <typename T>
class Agenda
{
public:
    Agenda(std::string const &_clave, T const &_valor);
    std::string getClave() const;
    void setClave(const std::string &value);
    T getValor() const;
    void setValor(const T &value);

private:
    std::string clave;
    T valor;
};

template <typename T>
Agenda<T>::Agenda(const std::string &_clave, const T &_valor) : clave{_clave}, valor{_valor} {}

template <typename T>
std::string Agenda<T>::getClave() const
{
    return clave;
}

template <typename T>
void Agenda<T>::setClave(const std::string &value)
{
    clave = value;
}

template <typename T>
T Agenda<T>::getValor() const
{
    return valor;
}

template <typename T>
void Agenda<T>::setValor(const T &value)
{
    valor = value;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Agenda<T> const &d)
{
    os << d.getClave() << ": " << d.getValor() << "\n";
    return os;
}

#endif
