#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>

using namespace std;

class Animal
{
public:
    Animal() {}

    Animal(string _nombre, string _pApellido, string _sApellido, string _fijo, string _movil);

    string getNombre() const;
    string getPApellido() const;
    string getSApellido() const;
    string getFijo() const;
    string getMovil() const;

    void setFijo(string f);
    void setMovil(string m);

    bool esEste(string _nombre, string _pApellido, string _sApellido) const;
    void print() const;

private:
    string nombre, pApellido, sApellido, fijo, movil;
};
#endif