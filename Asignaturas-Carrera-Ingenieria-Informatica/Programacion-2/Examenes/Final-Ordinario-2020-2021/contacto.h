#ifndef CONTACTO_H
#define CONTACTO_H

#include <string>
#include <ostream>

class Contacto
{
    friend std::ostream &operator<<(std::ostream &os, Contacto const &p);

public:
    Contacto(std::string _nombre, std::string primerApellido, std::string _telefono, std::string _correoElectronico, std::string _fechaNacimiento);

    std::string getNombre() const;
    void setName(const std::string &value);

    std::string getPrimerApellido() const;
    void setPrimerApellido(const std::string &value);

    std::string getTelefono() const;
    void setTelefono(const std::string &value);

    std::string getCorreoElectronico() const;
    void setCorreoElectronico(const std::string &value);

    std::string getFechaNacimiento() const;
    void setFechaNacimiento(const std::string &value);

private:
    std::string nombre;
    std::string primerApellido;
    std::string telefono;
    std::string correoElectronico;
    std::string fechaNacimiento;
};

#endif
