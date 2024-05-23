#include "persona.h"
#include <iostream>

using namespace std;

Persona::Persona()
{
}

string Persona::getName() const
{
    return name;
}

void Persona::setName(const string &value)
{
    name = value;
}

string Persona::getDni() const
{
    return dni;
}

void Persona::setDni(const string &value)
{
    dni = value;
}

string Persona::getTel() const
{
    return tel;
}

void Persona::setTel(const string &value)
{
    tel = value;
}

int Persona::getBirth() const
{
    return birth;
}

void Persona::setBirth(int value)
{
    birth = value;
}

void Persona::print() const
{
    cout << "Name: " << name << "\n";
    cout << "DNI: " << dni << "\n";
    cout << "Tel.: " << tel << "\n";
    cout << "Birth: " << birth << "\n";
}

int Persona::age(int a) const
{
    return (a - birth);
}

bool Persona::isAdult(int a) const
{
    return age(a) >= 18;
}
