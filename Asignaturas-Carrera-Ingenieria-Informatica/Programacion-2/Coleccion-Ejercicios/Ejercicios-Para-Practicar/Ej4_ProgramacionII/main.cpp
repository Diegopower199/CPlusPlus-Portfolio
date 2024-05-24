#include <iostream>
#include "matriz.h"

using namespace std;

int main()
{
    try
    {
        cout << "Introduce el numero de filas y columnas de la matriz 1: ";
        int fil, cols;
        cin >> fil >> cols;
        Matriz mat1{fil, cols};
        cout << "Introduce la matriz, numero a numero, por filas:\n";
        cin >> mat1;

        cout << "Introduce el numero de filas y columnas de la matriz 2: ";

        cin >> fil >> cols;
        Matriz mat2{fil, cols};
        cout << "Introduce la matriz, numero a numero, por filas:\n";
        cin >> mat2;

        Matriz suma = mat1 + mat2;
        Matriz resta = mat1 - mat2;
        Matriz mult = mat1 * mat2;
        cout << "Suma\n"
             << suma << "\n\n";
        cout << "Resta\n"
             << resta << "\n\n";
        cout << "Multiplicación\n"
             << mult << "\n\n";
    }
    catch (string e)
    {
        cout << e << "\n";
    }

    return 0;
}
