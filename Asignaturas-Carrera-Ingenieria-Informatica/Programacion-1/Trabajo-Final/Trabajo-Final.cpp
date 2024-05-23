#include <iostream>
#include <array>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int ruleta()
{
    srand(time(NULL));
    int numeroAleatorio = 0;

    numeroAleatorio = (rand() % 37) + 0;

    return numeroAleatorio;
}

int dineroApostadoRonda(int a)
{
    std::cout << "¿Cuanto dinero quieres apostar: ";
    int dineroApostado = 0;
    std::cin >> dineroApostado;
    return dineroApostado;
}

int apostarORetirarse()
{
    std::cout << "1. Apostar\n";
    std::cout << "2. Retirarse\n";

    int opcionUsuario = 0;

    std::cin >> opcionUsuario;

    return opcionUsuario;
}

int opciondeseada()
{
    std::cout << "Qué desea hacer: \n\n1. Elegir color\n2. Elegir número\n";

    int opcionUsuario2 = 0;

    std::cin >> opcionUsuario2;

    return opcionUsuario2;
}

int colorElegidoUsuario()
{
    int elegirColor = 0;
    std::cout << "\nElige\n1.Negro\n2.Rojo\n";
    std::cin >> elegirColor;
    return elegirColor;
}

int dineroApostado(std::string frase)
{
    std::cout << frase;
    int dineroApuesta = 0;
    std::cin >> dineroApuesta;
    return dineroApuesta;
}

void dineroGanadoColor(std::array<int, 4> colorElegidoEnNumero, int colorAleatorio, std::array<int, 4> dineroApostadoJugadores, std::array<int, 4> &dineroJugadores, std::array<int, 4> &dineroGanadoCadaRonda, int &dineroGanadoBanca)
{
    int resultado = 0;
    for (int pos = 0; pos < 4; pos++)
    {
        if (colorElegidoEnNumero.at(pos) == colorAleatorio)
        {
            resultado = dineroApostadoJugadores.at(pos) * 2;
            dineroJugadores.at(pos) = dineroJugadores.at(pos) + resultado;
            dineroGanadoCadaRonda.at(pos) = dineroGanadoCadaRonda.at(pos) + resultado;
            dineroGanadoBanca = dineroGanadoBanca - resultado;
        }
    }
    return;
}

void dineroGanadoPorNumero(int numeroRuleta, std::array<int, 4> numeroElegido, std::array<int, 4> dineroApostadoJugadores, std::array<int, 4> &dineroJugadores, std::array<int, 4> &dineroGanadoCadaRonda, int &dineroGanadoBanca)
{
    int resultado = 0;
    for (int pos = 0; pos < 4; pos++)
    {
        if (numeroElegido.at(pos) == numeroRuleta)
        {
            resultado = dineroApostadoJugadores.at(pos) * 35;
            dineroJugadores.at(pos) = dineroJugadores.at(pos) + resultado;
            dineroGanadoCadaRonda.at(pos) = dineroGanadoCadaRonda.at(pos) + resultado;
            dineroGanadoBanca = dineroGanadoBanca - resultado;
        }
    }
    return;
}

int main()
{
    std::array<bool, 4> seguirJugando = {true, true, true, true};

    std::cout << "Los 4 jugadores empiezan con 10 euros\n\n\n";
    std::array<int, 4> dineroJugadores = {10, 10, 10, 10};
    std::array<int, 4> dineroApostadoJugadores = {0, 0, 0, 0};
    std::array<int, 4> colorElegidoEnNumero = {0, 0, 0, 0};

    std::array<int, 4> dineroGanadoCadaRonda = {0, 0, 0, 0};
    int dineroGanadoBanca = 0;

    int colorRuleta = -1;

    std::array<int, 4> numeroElegido = {0, 0, 0, 0};

    std::array<int, 4> opdeseada = {0, 0, 0, 0};

    int numeroRuleta = -1;

    int opcionApostarRetirarse = 0;
    std::string elegirColor = "";
    int elegirNumero = 0;
    int dineroApostado = 0;

    while (seguirJugando.at(0) == true || seguirJugando.at(1) == true || seguirJugando.at(2) == true || seguirJugando.at(3) == true)
    {

        int jugador = 1;

        for (int pos = 0; pos < 4; pos++)
        {

            if (seguirJugando.at(pos) == true)
            {
                std::cout << "Jugador " << jugador << " : Elige qué quieres hacer\n\n";
                opcionApostarRetirarse = apostarORetirarse();

                while (opcionApostarRetirarse <= 0 || opcionApostarRetirarse > 2)
                {
                    std::cout << "Error, esa opcion no esta registrada.\nJugador " << jugador << ", Elige qué quieres hacer\n\n";
                    opcionApostarRetirarse = apostarORetirarse();
                }

                if (opcionApostarRetirarse == 1)
                {
                    dineroApostado = dineroApostadoRonda(dineroJugadores.at(pos));

                    while (dineroApostado > dineroJugadores.at(pos) || dineroApostado <= 0)
                    {
                        if (dineroApostado == 0)
                        {
                            std::cout << "No puede apostar 0, Usted tiene " << dineroJugadores.at(pos) << " euros" << "\nPon otra: \n";
                            dineroApostado = dineroApostadoRonda(dineroJugadores.at(pos));
                        }
                        else if (dineroApostado < 0)
                        {
                            std::cout << "No puede apostar valores negativos, Usted tiene " << dineroJugadores.at(pos) << " euros" << "\nPon otra: \n";
                            dineroApostado = dineroApostadoRonda(dineroJugadores.at(pos));
                        }
                        else
                        {
                            std::cout << "Esa cantidad no la tiene. Usted tiene " << dineroJugadores.at(pos) << " euros" << "\nPon otra: \n";
                            dineroApostado = dineroApostadoRonda(dineroJugadores.at(pos));
                        }
                    }

                    dineroApostadoJugadores.at(pos) = dineroApostado;

                    dineroGanadoCadaRonda.at(pos) = dineroGanadoCadaRonda.at(pos) - dineroApostadoJugadores.at(pos);

                    dineroGanadoBanca = dineroGanadoBanca + dineroApostadoJugadores.at(pos);

                    dineroJugadores.at(pos) = dineroJugadores.at(pos) - dineroApostadoJugadores.at(pos);

                    opdeseada.at(pos) = opciondeseada();

                    while (opdeseada.at(pos) <= 0 || opdeseada.at(pos) > 2)
                    {
                        std::cout << "Error, esa opcion no esta registrada.\nJugador " << jugador;
                        opdeseada.at(pos) = opciondeseada();
                    }

                    if (opdeseada.at(pos) == 1)
                    {
                        colorElegidoEnNumero.at(pos) = colorElegidoUsuario();
                        while (colorElegidoEnNumero.at(pos) <= 0 || colorElegidoEnNumero.at(pos) >= 3)
                        {
                            std::cout << "Error, elige un número entre 1 y 2: ";
                            colorElegidoEnNumero.at(pos) = colorElegidoUsuario();
                        }
                    }
                    else if (opdeseada.at(pos) == 2)
                    {
                        std::cout << "Elige un número entre 1 y 36: ";
                        std::cin >> elegirNumero;
                        while (elegirNumero <= 0 || elegirNumero > 36)
                        {
                            std::cout << "Error, elige un número entre 1 y 36: ";
                            std::cin >> elegirNumero;
                        }
                        numeroElegido.at(pos) = elegirNumero;
                    }
                }

                else if (opcionApostarRetirarse == 2)
                {
                    std::cout << "El jugador " << jugador << " se ha retirado\n";
                    seguirJugando.at(pos) = false;
                }
                dineroApostado = 0;
            }
            jugador++;
        }

        numeroRuleta = ruleta();

        if (numeroRuleta % 2 == 1)
        { // Numero Impar que es el Color Negro
            colorRuleta = 1;
        }
        else if (numeroRuleta == 0)
        { // Numero 0 que es el Color Verde
            colorRuleta = 0;
        }
        else
        { // Numero Par que es el Color Rojo
            colorRuleta = 2;
        }

        for (int pos = 0; pos < 1; pos++)
        {
            if (opdeseada.at(pos) == 1)
            {
                dineroGanadoColor(colorElegidoEnNumero, colorRuleta, dineroApostadoJugadores, dineroJugadores, dineroGanadoCadaRonda, dineroGanadoBanca);
            }
            else
            {
                dineroGanadoPorNumero(numeroRuleta, numeroElegido, dineroApostadoJugadores, dineroJugadores, dineroGanadoCadaRonda, dineroGanadoBanca);
            }
        }

        std::cout << "Color Ruleta (1.Negro y 2.Rojo): " << colorRuleta << "\n";

        std::cout << "El número de la ruleta es: " << numeroRuleta << "\n";

        std::cout << "\n\n";

        for (int pos = 0; pos < 4; pos++)
        {
            if (dineroJugadores.at(pos) == 0)
            {
                seguirJugando.at(pos) = false;
            }
        }

        dineroApostadoJugadores = {0, 0, 0, 0};
    }

    int jugadores = 1;

    for (int pos = 0; pos < 4; pos++)
    {

        if (dineroGanadoCadaRonda.at(pos) < 0)
        {
            std::cout << "El jugador " << jugadores << " ha perdido " << -dineroGanadoCadaRonda.at(pos) << "\n";
        }
        else
        {
            std::cout << "El jugador " << jugadores << " ha ganado " << dineroGanadoCadaRonda.at(pos) << "\n";
        }
        jugadores = jugadores + 1;
    }

    if (dineroGanadoBanca < 0)
    {
        std::cout << "La banca ha perdido " << -dineroGanadoBanca << "\n";
    }
    else
    {
        std::cout << "La banca ha ganado " << dineroGanadoBanca << "\n";
    }
}
