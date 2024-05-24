#include <iostream>
#include <array>

struct Player
{
    std::string nombre = "";
    int partidasGanadas = 0;
    std::array<std::string, 3> opcionesPosibles = {"Piedra", "Papel", "Tijera"};
    int selección = 0;
};

int main()
{
    Player jugador1, jugador2;

    int vecesJugado = 0;
    std::string respuesta = "";

    std::cout << "¿Quieres empezar una partida?: ";
    std::getline(std::cin, respuesta);

    if (respuesta == "no")
    {
        vecesJugado = 3;
    }
    else
    {
        std::cout << "Nombre jugador 1: ";
        std::getline(std::cin, jugador1.nombre);
        std::cout << "Seleccion Papel (0), Tijera (1), Piedra (2): ";
        std::cin >> jugador1.selección;
        std::getline(std::cin, respuesta);

        std::cout << "Nombre jugador 2: ";
        std::getline(std::cin, jugador2.nombre);
        std::cout << "Seleccion Papel (0), Tijera (1), Piedra (2): ";
        std::cin >> jugador2.selección;
    }

    while (vecesJugado < 3)
    {

        if (vecesJugado != 0)
        {
            std::cout << "Jugador 1 elige una opcion: " << "Seleccion Papel (0), Tijera (1), Piedra (2): ";
            std::cin >> jugador1.selección;
            std::getline(std::cin, respuesta);

            std::cout << "\nJugador 2 elige una opcion: " << "Seleccion Papel (0), Tijera (1), Piedra (2): ";
            std::cin >> jugador2.selección;
            std::getline(std::cin, respuesta);
        }

        if ((jugador1.selección == 2 && jugador2.selección == 1) || (jugador1.selección == 0 && jugador2.selección == 2) || (jugador1.selección == 1 && jugador2.selección == 0))
        {
            jugador1.partidasGanadas = jugador1.partidasGanadas + 1;
            std::cout << "Jugador 1 ha ganado " << jugador1.partidasGanadas << " vez\n";
        }

        else if ((jugador2.selección == 2 && jugador1.selección == 1) || (jugador2.selección == 0 && jugador1.selección == 2) || (jugador2.selección == 1 && jugador1.selección == 0))
        {
            jugador2.partidasGanadas = jugador2.partidasGanadas + 1;
            std::cout << "Jugador 2 ha ganado " << jugador2.partidasGanadas << " vez\n";
        }

        vecesJugado++;
    }

    if (jugador1.partidasGanadas < jugador2.partidasGanadas)
    {
        std::cout << "\nHa ganado el jugador 2\n";
    }
    else
    {
        std::cout << "\nHa ganado el jugador 1\n";
    }

    std::cout << "Terminado el bucle";
}