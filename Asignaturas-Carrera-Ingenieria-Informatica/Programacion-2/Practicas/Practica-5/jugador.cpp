#include "jugador.h"
#include <string>

Jugador::Jugador()
{
}

Jugador::~Jugador()
{
}

int Jugador::getnumeroApostado() const
{
    return numeroApostadoJugador;
}

void Jugador::setNumeroApostado(int value)
{
    numeroApostadoJugador = value;
}

bool Jugador::getSigueJugando() const
{
    return sigueJugandoJugador;
}

void Jugador::setSigueJugando(bool value)
{
    sigueJugandoJugador = value;
}

int Jugador::getSumaAllPoints() const
{
    return sumaPuntosJugador;
}

void Jugador::setSumaAllPoints(int value)
{
    sumaPuntosJugador = sumaPuntosJugador + value;
}
