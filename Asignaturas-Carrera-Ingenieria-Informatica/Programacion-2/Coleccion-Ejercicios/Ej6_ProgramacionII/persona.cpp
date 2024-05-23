#include "persona.h"

Persona::Persona(std::string nombre, int edad, std::string dni) : nombre{nombre}, edad{edad}, dni{dni} {}

std::string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const std::string &value)
{
    nombre = value;
}

int Persona::getEdad() const
{
    return edad;
}

void Persona::setEdad(int value)
{
    edad = value;
}

std::string Persona::getDni() const
{
    return dni;
}

void Persona::setDni(const std::string &value)
{
    dni = value;
}
