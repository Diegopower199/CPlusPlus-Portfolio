#include <iostream>
#include <array>
#include <vector>
#include <bolsa.h>
#include "jugador.h"

using namespace std;

int main()
{

    std::vector<int> bolas = {};

    Bolsa bolasEnumeradas = {bolas};

    Jugador jugador1 = {};
    Jugador jugador2 = {};

    int numeroApostadoJugador1;

    int numeroApostadoJugador2;

    std::cout << "Jugador 1 apuesta que numero van a obtener entre 10 y 50: ";
    std::cin >> numeroApostadoJugador1;

    if (numeroApostadoJugador1 < 10 || numeroApostadoJugador1 > 50)
    {
        std::cout << "Usted no puede apostar ese numero, introduce un numero entre 10 y 50: ";
        std::cin >> numeroApostadoJugador1;
    }

    std::cout << "Jugador 2 apuesta que numero van a obtener: ";
    std::cin >> numeroApostadoJugador2;

    if (numeroApostadoJugador2 < 10 || numeroApostadoJugador2 > 50)
    {
        std::cout << "Usted no puede apostar ese numero, introduce un numero entre 10 y 50: ";
        std::cin >> numeroApostadoJugador2;
    }

    int sumaTodosLosPuntosJugador1 = 0;
    int sumaTodosLosPuntosJugador2 = 0;

    int seguirJugandoJugador1;
    int seguirJugandoJugador2;

    while (jugador1.getSigueJugando() != false || jugador2.getSigueJugando() != false)
    {
        sumaTodosLosPuntosJugador1 = sumaTodosLosPuntosJugador1 + jugador1.sacarBola(bolas);

        sumaTodosLosPuntosJugador2 = sumaTodosLosPuntosJugador2 + jugador2.sacarBola(bolas);

        std::cout << "Quiere seguir jugando Jugador 1 (1 que si, 0 que no): ";
        std::cin >> seguirJugandoJugador1;

        std::cout << "Quiere seguir jugando Jugador 2 (1 que si, 0 que no): ";
        std::cin >> seguirJugandoJugador2;

        if (seguirJugandoJugador1 == 0)
        {
            jugador1.setSigueJugando(false);
        }

        if (seguirJugandoJugador2 == 0)
        {
            jugador2.setSigueJugando(false);
        }

        jugador1.setSumaAllPoints(sumaTodosLosPuntosJugador1);
        jugador2.setSumaAllPoints(sumaTodosLosPuntosJugador2);
    }
}
