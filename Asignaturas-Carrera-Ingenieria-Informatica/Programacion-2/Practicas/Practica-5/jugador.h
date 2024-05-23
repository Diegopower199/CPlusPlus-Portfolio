#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "bolsa.h"

class Jugador : public Bolsa
{
public:
    Jugador();
    ~Jugador();

    int getnumeroApostado() const;
    void setNumeroApostado(int value);

    bool getSigueJugando() const;
    void setSigueJugando(bool value);

    int getSumaAllPoints() const;
    void setSumaAllPoints(int value);

private:
    int numeroApostadoJugador = 0;
    int sumaPuntosJugador = 0;
    bool sigueJugandoJugador;
};

#endif
