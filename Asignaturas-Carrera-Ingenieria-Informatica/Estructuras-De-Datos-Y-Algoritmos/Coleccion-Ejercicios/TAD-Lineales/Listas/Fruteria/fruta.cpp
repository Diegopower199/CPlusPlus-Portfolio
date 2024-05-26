#include "fruta.h"

Fruta::Fruta(const std::string &name, float f, const std::string &pO)
{
    _name = name;
    _precioKilo = f;
    _paisOrigen = pO;
}

void Fruta::set_precio(const float &f)
{
    _precioKilo = f;
}

void Fruta::set_origen(const std::string &pO)
{
    _paisOrigen = pO;
}

std::ostream &operator<<(std::ostream &os, const Fruta &fru)
{
    os << fru._name << ", " << fru._precioKilo << ", " << fru._paisOrigen << "\n";
    return os;
}
