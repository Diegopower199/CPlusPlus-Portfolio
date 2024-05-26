#ifndef FRUTA_H
#define FRUTA_H

#include <iostream>
#include <ostream>

class Fruta
{
public:
    Fruta(const std::string &name, float f, const std::string &pO);
    void set_precio(const float &f);
    void set_origen(const std::string &pO);

    friend std::ostream &operator<<(std::ostream &os, const Fruta &fru);

private:
    std::string _name;
    float _precioKilo;
    std::string _paisOrigen;
};
std::ostream &operator<<(std::ostream &os, const Fruta &fru);

#endif
