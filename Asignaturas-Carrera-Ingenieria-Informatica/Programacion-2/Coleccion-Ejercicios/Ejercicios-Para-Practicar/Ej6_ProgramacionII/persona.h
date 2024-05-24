#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona
{
public:
    Persona(std::string nombre, int edad, std::string dni);

    std::string getNombre() const;
    void setNombre(const std::string &value);

    int getEdad() const;
    void setEdad(int value);

    std::string getDni() const;
    void setDni(const std::string &value);

private:
    std::string nombre;
    int edad;
    std::string dni;
};

#endif
