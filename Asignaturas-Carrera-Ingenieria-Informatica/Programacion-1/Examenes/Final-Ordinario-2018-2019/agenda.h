#ifndef AGENDA_H
#define AGENDA_H

#include "contacto.h"
#include <vector>
#include <iostream>

using namespace std;

class Registro
{
public:
    Registro();

    bool anadirContacto(string nombre, string pApellido, string sApellido, string movil, string fijo);

    bool eliminarContacto(string nombre, string pApellido, string sApellido);
    bool buscarContacto(string nombre, string pApellido, string sApellido, Animal &contacto);
    bool modificarContacto(string nombre, string pApellido, string sApellido, string movil, string fijo);

private:
    vector<Animal> contactos;
};

#endif