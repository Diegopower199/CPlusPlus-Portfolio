#include "persona.h"

Persona::Persona() {}

Persona::Persona(const std::string &_nombre, int _nacimiento, const std::string &_telefono) : nombre{_nombre}, nacimiento{_nacimiento}, telefono{_telefono} {}

std::string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const std::string &value)
{
    if (value.size() == 0)
        throw std::string{"No puede ir en blanco"};
    nombre = value;
}

int Persona::getNacimiento() const
{
    return nacimiento;
}

void Persona::setNacimiento(int value)
{
    nacimiento = value;
}

std::string Persona::getTelefono() const
{
    return telefono;
}

void Persona::setTelefono(const std::string &value)
{
    if (value.size() != 9)
        throw std::string{"Introduce un numero de 9 digitos"};
    telefono = value;
}

std::ostream &operator<<(std::ostream &os, Persona const &p)
{
    os << "Nombre: " << p.getNombre() << "\nNacimiento: " << p.getNacimiento() << "\nTelefono: " << p.getTelefono() << "\n";
    return os;
}
