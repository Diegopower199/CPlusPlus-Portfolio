#include <iostream>
#include "matriz.h"
#include "plantillas.h"

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

        Matriz s = suma(mat1, mat2);
        Matriz r = resta(mat1, mat2);
        Matriz m = multiplicacion(mat1, mat2);
        cout << "Suma\n"
             << s << "\n\n";
        cout << "Resta\n"
             << r << "\n\n";
        cout << "Multiplicación\n"
             << m << "\n\n";
    }
    catch (string e)
    {
        cout << e << "\n";
    }

    return 0;
}
