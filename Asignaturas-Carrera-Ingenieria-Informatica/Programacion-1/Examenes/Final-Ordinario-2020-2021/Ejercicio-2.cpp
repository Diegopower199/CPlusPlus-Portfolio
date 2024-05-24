#include <iostream>
#include <stdlib.h>
#include <time.h>

int numeroIntroducidoUsuario(int &numeroUsuario)
{
    std::cout << "Introduce un numero entre el 1 y 50 incluidos para adivinar el numero: ";
    numeroUsuario = 0;
    std::cin >> numeroUsuario;

    while (numeroUsuario <= 0 || numeroUsuario > 50)
    {
        std::cout << "\nEse numero no esta disponible, introduce un numero entre el 1 y 50 incluidos para adivinar el numero: ";
        std::cin >> numeroUsuario;
    }

    return numeroUsuario;
}

int main()
{

    srand(time(NULL));

    int numeroAleatorio = (rand() % 50) + 1;

    std::cout << "Numero aleatorio: " << numeroAleatorio << "\n";
    int numero = 0;

    for (int pos = 0; pos < 5; pos++)
    {
        int numeroUsuario = numeroIntroducidoUsuario(numero);

        if (numeroUsuario < numeroAleatorio)
        {
            std::cout << "\nEl numero es menor al que ha introducido\n";
        }
        else if (numeroUsuario > numeroAleatorio)
        {
            std::cout << "\nEl numero es mayor al que ha introducido\n";
        }
        else
        {
            std::cout << "enhorabuena";
            return 0;
        }
    }

    std::cout << "Has perdido, el numero aleatorio es: " << numeroAleatorio;
}
