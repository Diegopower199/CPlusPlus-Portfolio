#include "tiempo.h"

Tiempo::Tiempo() : horas{0}, minutos{0}, segundos{0} {}

Tiempo::Tiempo(int horas, int minutos, int segundos) : horas{horas}, minutos{minutos}, segundos{segundos} {}

Tiempo::Tiempo(const Tiempo &other) : horas{other.horas}, minutos{other.minutos}, segundos{other.segundos} {}

int Tiempo::getHoras() const
{
    return horas;
}

void Tiempo::setHoras(int value)
{
    horas = value;
}

int Tiempo::getMinutos() const
{
    return minutos;
}

void Tiempo::setMinutos(int value)
{
    if (value > 59)
    {
        throw string{"Error"};
        minutos = 0;
        horas++;
    }
    else
    {
        minutos = value;
    }
}

int Tiempo::getSegundos() const
{
    return segundos;
}

void Tiempo::setSegundos(int value)
{
    if (value > 59)
    {
        throw string{"Error"};
        segundos = 0;
        minutos++;
    }
    else
    {
        segundos = value;
    }
}

int Tiempo::get_seconds()
{
    minutos = horas * 60;
    segundos = minutos * 60;
    return segundos;
}

Tiempo operator+(Tiempo const &t1, Tiempo const &t2)
{
    Tiempo result{t1.horas + t2.horas, t1.minutos + t2.minutos, t1.segundos + t2.segundos};
    return result;
}

Tiempo operator-(Tiempo const &t1, Tiempo const &t2)
{
    Tiempo result{t1.horas - t2.horas, t1.minutos - t2.minutos, t1.segundos - t2.segundos};
    return result;
}

ostream &operator<<(ostream &os, Tiempo const &t)
{
    os << "[" << t.horas << ":" << t.minutos << ":" << t.segundos << "]" << endl;
    return os;
}

bool operator==(Tiempo const &t1, Tiempo const &t2)
{
    return ((t1.horas == t2.horas) && (t1.minutos == t2.minutos) && (t1.segundos == t2.segundos));
}

istream &operator>>(istream &is, Tiempo &t)
{
    is >> t.horas;
    is >> t.minutos;
    is >> t.segundos;
    return is;
}
