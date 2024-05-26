#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Contacto
{
public:
    Contacto();
    Contacto(std::string nom, std::string apell, std::string telef, std::string gmail, std::string fecha);

    std::string getNombre() const;
    void setNombre(const std::string &value);

    std::string getApellido1() const;
    void setApellido1(const std::string &value);

    std::string getTelefono() const;
    void setTelefono(const std::string &value);

    std::string getEmail() const;
    void setEmail(const std::string &value);

    std::string getNacimiento() const;
    void setNacimiento(const std::string &value);

private:
    std::string nombre;
    std::string apellido1;
    std::string telefono;
    std::string email;
    std::string nacimiento;
};

class Agenda
{
public:
    void insertar(std::shared_ptr<Contacto> c1);
    void borrar(const std::string &nomb_, const std::string &apell);
    void setAgenda(const std::vector<std::shared_ptr<Contacto>> &agend);
    std::shared_ptr<Contacto> findNom(const std::string &nomb_, const std::string &apell) const;
    std::shared_ptr<Contacto> findAge(const std::string &nacimiento) const;
    std::shared_ptr<Contacto> print(const std::string &fechas) const;
    std::vector<std::shared_ptr<Contacto>> getAgenda() const;

private:
    std::vector<std::shared_ptr<Contacto>> agenda;
};

std::ostream &operator<<(std::ostream &os, const Contacto &c);
std::ostream &operator<<(std::ostream &os, const Agenda &ag);

#endif
