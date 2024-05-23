#include "contacto.h"
#include <vector>
#include <memory>
#include <functional>

Contacto::Contacto(std::string _nombre, std::string _primerApellido, std::string _telefono, std::string _correoElectronico, std::string _fechaNacimiento)
{
    setName(_nombre);
    setPrimerApellido(_primerApellido);
    setTelefono(_telefono);
    setCorreoElectronico(_correoElectronico);
    setFechaNacimiento(_fechaNacimiento);
}

std::string Contacto::getNombre() const
{
    return nombre;
}

void Contacto::setName(const std::string &value)
{
    nombre = value;
}

std::string Contacto::getPrimerApellido() const
{
    return primerApellido;
}

void Contacto::setPrimerApellido(const std::string &value)
{
    primerApellido = value;
}

std::string Contacto::getTelefono() const
{
    return telefono;
}

void Contacto::setTelefono(const std::string &value)
{
    if (value.length() != 9)
        throw std::string{"Longitud incorrecta"};
    telefono = value;
}

std::string Contacto::getCorreoElectronico() const
{
    return correoElectronico;
}

void Contacto::setCorreoElectronico(const std::string &value)
{
    correoElectronico = value;
}

std::string Contacto::getFechaNacimiento() const
{
    return fechaNacimiento;
}

void Contacto::setFechaNacimiento(const std::string &value)
{
    fechaNacimiento = value;
}

std::ostream &operator<<(std::ostream &os, Contacto const &p)
{
    os << "Nombre: " << p.getNombre() << "\n";
    os << "Primer Apellido: " << p.getPrimerApellido() << "\n";
    os << "Telefono: " << p.getTelefono() << "\n";
    os << "Correo Electronico: " << p.getCorreoElectronico() << "\n";
    os << "Fecha de nacimiento: " << p.getFechaNacimiento() << "\n";
    return os;
}
