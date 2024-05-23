#include <iostream>
#include <vector>
#include "matriz.h"

using namespace std;

int main()
{
    int f1, c1, f2, c2;

    // Pedimos los datos de la matriz 1
    Matriz mat;
    cout << "MATRIZ 1 \n\n";
    cout << "FILAS: ";
    cin >> f1;
    cout << "COLUMNAS: ";
    cin >> c1;
    mat.pedirMatriz(f1, c1);

    // Pedimos los datos de la matriz 2
    Matriz mat2;
    cout << "MATRIZ 2\n\n";
    cout << "FILAS: ";
    cin >> f2;
    cout << "COLUMNAS: ";
    cin >> c2;
    mat2.pedirMatriz(f2, c2);
}
