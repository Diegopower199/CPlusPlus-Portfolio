#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

class Persona
{
public:
    Persona();
    Persona(std::string const &_nombre, int _nacimiento, std::string const &_telefono);
    std::string getNombre() const;
    void setNombre(const std::string &value);
    int getNacimiento() const;
    void setNacimiento(int value);
    std::string getTelefono() const;
    void setTelefono(const std::string &value);

private:
    std::string nombre;
    int nacimiento;
    std::string telefono;
};

std::ostream &operator<<(std::ostream &os, Persona const &p);

#endif
