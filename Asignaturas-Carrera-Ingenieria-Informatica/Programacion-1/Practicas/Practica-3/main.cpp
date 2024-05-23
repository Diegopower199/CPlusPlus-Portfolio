#include <iostream>
#include <array>

int elegirOpcion()
{

    std::cout << "1.Salir del programa\n";
    std::cout << "2.Introducir matrices\n";
    std::cout << "3.Sumar matrices y mostrar la suma por pantalla\n";
    std::cout << "4.Restar matrices y mostrar la resta por pantalla\n";
    std::cout << "5.Calcular determinante matriz 3x3 y mostrarlo por pantalla\n";
    std::cout << "6.Imprimir las 2 matrices\n";
    std::cout << "Escoge una opcion: ";

    int opcionUsuario = 0;

    std::cin >> opcionUsuario;

    return opcionUsuario;
}

std::array<std::array<int, 3>, 3> EjecutarOpcion2()
{
    std::array<std::array<int, 3>, 3> matriz = {};

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            std::cout << "Introduce el elemento " << fila << ", " << columna << ": ";
            int numero;
            std::cin >> numero;
            matriz.at(fila).at(columna) = numero;
        }
    }

    return matriz;
}

std::array<std::array<int, 3>, 3> EjecutarOpcion3(std::array<std::array<int, 3>, 3> matriz1, std::array<std::array<int, 3>, 3> matriz2)
{
    std::array<std::array<int, 3>, 3> matrizSuma = {};

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            matrizSuma.at(fila).at(columna) = matriz1.at(fila).at(columna) + matriz2.at(fila).at(columna);
        }
    }

    return matrizSuma;
}

std::array<std::array<int, 3>, 3> EjecutarOpcion4(std::array<std::array<int, 3>, 3> matriz1, std::array<std::array<int, 3>, 3> matriz2)
{
    std::array<std::array<int, 3>, 3> matrizResta = {};

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            matrizResta.at(fila).at(columna) = matriz1.at(fila).at(columna) - matriz2.at(fila).at(columna);
        }
    }

    return matrizResta;
}

int EjecutarOpcion5(std::array<std::array<int, 3>, 3> matriz1)
{
    int determinante = 0;

    determinante = (matriz1.at(0).at(0) * matriz1.at(1).at(1) * matriz1.at(2).at(2) + matriz1.at(1).at(0) * matriz1.at(2).at(1) * matriz1.at(0).at(2) + matriz1.at(0).at(1) * matriz1.at(1).at(2) * matriz1.at(2).at(0)) - (matriz1.at(0).at(2) * matriz1.at(1).at(1) * matriz1.at(2).at(0) + matriz1.at(1).at(2) * matriz1.at(2).at(1) * matriz1.at(0).at(0) + matriz1.at(1).at(0) * matriz1.at(0).at(1) * matriz1.at(2).at(2));

    return determinante;
}

int main()
{

    std::array<std::array<int, 3>, 3> matrizA = {};
    std::array<std::array<int, 3>, 3> matrizB = {};
    std::array<std::array<int, 3>, 3> resultado = {};

    for (int fila{0}; fila < 3; fila++)
    {
        for (int col{0}; col < 3; col++)
        {
            int numero = 0;
            matrizA.at(fila).at(col) = numero;
            matrizB.at(fila).at(col) = numero;
        }
    }

    int opcionMenu = 0;

    while (opcionMenu != 1)
    {
        opcionMenu = elegirOpcion();

        if (opcionMenu == 2)
        {
            matrizA = EjecutarOpcion2();
            matrizB = EjecutarOpcion2();
            std::cout << "\n";
        }
        if (opcionMenu == 3)
        {
            resultado = EjecutarOpcion3(matrizA, matrizB);

            for (auto fila : resultado)
            {
                for (auto elem : fila)
                {
                    std::cout << elem << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }

        if (opcionMenu == 4)
        {
            resultado = EjecutarOpcion4(matrizA, matrizB);

            for (auto fila : resultado)
            {
                for (auto elem : fila)
                {
                    std::cout << elem << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }

        if (opcionMenu == 5)
        {
            int determinanteA = 0;
            determinanteA = EjecutarOpcion5(matrizA);
            std::cout << "El determinante de la primera matriz es " << determinanteA << "\n";
        }

        if (opcionMenu == 6)
        {
            std::cout << "La primera matriz es \n";

            for (auto fila : matrizA)
            {
                for (auto elem : fila)
                {
                    std::cout << elem << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            std::cout << "La segunda matriz es \n";

            for (auto fila : matrizB)
            {
                for (auto elem : fila)
                {
                    std::cout << elem << " ";
                }
                std::cout << "\n";
            }
        }
    }
}
