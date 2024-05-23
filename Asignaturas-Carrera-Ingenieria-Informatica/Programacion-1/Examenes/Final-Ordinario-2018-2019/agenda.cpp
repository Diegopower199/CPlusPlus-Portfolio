#include "agenda.h"

using namespace std;
Registro::Registro()
{
}

bool Registro::anadirContacto(string nombre, string pApellido, string sApellido, string movil, string fijo)
{
    Animal contacto;
    if (!buscarContacto(nombre, pApellido, sApellido, contacto))
    {
        Animal contacto{nombre, pApellido, sApellido, movil, fijo};
        contactos.push_back(contacto);
        return true;
    }

    return false;
}

bool Registro::eliminarContacto(string nombre, string pApellido, string sApellido)
{
    for (unsigned long int i{0}; i < contactos.size(); i++)
    {

        if (contactos.at(i).esEste(nombre, pApellido, sApellido))
        {
            contactos.erase(contactos.begin() + i);
            return true;
        }
    }

    return false;
}

bool Registro::buscarContacto(string nombre, string pApellido, string sApellido, Animal &contacto)
{
    for (auto const &aux : contactos)
    {
        if (aux.esEste(nombre, pApellido, sApellido))
        {
            contacto = aux;
            return true;
        }
    }

    return false;
}

bool Registro::modificarContacto(string nombre, string pApellido, string sApellido, string movil, string fijo)
{
    for (auto &aux : contactos)
    {
        if (aux.esEste(nombre, pApellido, sApellido))
        {
            aux.setFijo(fijo);
            aux.setMovil(movil);
            return true;
        }
    }

    return false;
}
