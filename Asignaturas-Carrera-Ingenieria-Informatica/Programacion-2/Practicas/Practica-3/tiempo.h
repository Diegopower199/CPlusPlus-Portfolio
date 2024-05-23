#ifndef TIEMPO_H
#define TIEMPO_H

#include <string>
#include <istream>
#include <ostream>

using namespace std;

class Tiempo
{
    friend Tiempo operator+(Tiempo const &t1, Tiempo const &t2);
    friend Tiempo operator-(Tiempo const &t1, Tiempo const &t2);
    friend bool operator==(Tiempo const &t1, Tiempo const &t2);
    friend ostream &operator<<(ostream &os, Tiempo const &t);
    friend istream &operator>>(istream &is, Tiempo &t);

public:
    Tiempo();
    Tiempo(int horas, int minutos, int segundos);
    Tiempo(Tiempo const &other);

    int getHoras() const;
    void setHoras(int value);

    int getMinutos() const;
    void setMinutos(int value);

    int getSegundos() const;
    void setSegundos(int value);

    int get_seconds();

private:
    int horas, minutos, segundos;
};

#endif
